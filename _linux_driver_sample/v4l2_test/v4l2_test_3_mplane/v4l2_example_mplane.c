/*
代码来源：https://www.cnblogs.com/yangxinrui/p/15897361.html
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <linux/videodev2.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <assert.h>

#include "display.h"


#define TRUE            (1)
#define FALSE           (0)

#define FILE_VIDEO      "/dev/video0"
#define IMAGE           "./img/demo"

#define IMAGEWIDTH      1080 
#define IMAGEHEIGHT     720 

#define FRAME_NUM       4

#define CLEAR(item) memset(item, 0x0, sizeof(*(item)))

int fd;

#define FMT_NUM_PLANES  1
struct v4l2_requestbuffers reqbuf;
/* Our current format uses 3 planes per buffer */

struct {
	void *start[FMT_NUM_PLANES];
	size_t length[FMT_NUM_PLANES];
} *buffers;

struct v4l2_buffer buffer;

int v4l2_init()
{
    struct v4l2_capability cap;
    struct v4l2_fmtdesc fmtdesc;
    struct v4l2_format fmt;

    if ((fd = open(FILE_VIDEO, O_RDWR)) == -1) 
    {
        printf("Error opening V4L interface\n");
        return FALSE;
    }

    // 查看设备支持的功能
    if (ioctl(fd, VIDIOC_QUERYCAP, &cap) == -1) 
    {
        printf("Error opening device %s: unable to query device.\n",FILE_VIDEO);
        return FALSE;
    }
    else
    {
        printf("driver:\t\t%s\n",cap.driver);
        printf("card:\t\t%s\n",cap.card);
        printf("bus_info:\t%s\n",cap.bus_info);
        printf("version:\t%d\n",cap.version);
        printf("capabilities:\t%x\n",cap.capabilities);
        
        if ((cap.capabilities & V4L2_CAP_VIDEO_CAPTURE) == V4L2_CAP_VIDEO_CAPTURE) 
        {
            printf("Device %s: supports capture.\n",FILE_VIDEO);
        }

        if ((cap.capabilities & V4L2_CAP_VIDEO_CAPTURE_MPLANE) == V4L2_CAP_VIDEO_CAPTURE_MPLANE) 
        {
            printf("Device %s: supports mplane capture.\n",FILE_VIDEO);
        }

        if ((cap.capabilities & V4L2_CAP_STREAMING) == V4L2_CAP_STREAMING) 
        {
            printf("Device %s: supports streaming.\n",FILE_VIDEO);
        }
    }

    // 枚举支持的所有图层格式
    fmtdesc.index = 0;
    fmtdesc.type = V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE;
    printf("Support format:\n");
    while(ioctl(fd,VIDIOC_ENUM_FMT,&fmtdesc)!=-1)
    {
        printf("\t%d.%s,%d\n",fmtdesc.index+1,fmtdesc.description, 
				fmtdesc.flags);
        fmtdesc.index++;
    }

	// 显示当前的图层格式
	fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE;
    printf("get fmt...\n"); 
    if(ioctl(fd, VIDIOC_G_FMT, &fmt) == -1)
    {
        printf("Unable to get format\n");
		perror("VIDIOC_G_FMT");
        return FALSE;
    }
	else {
        printf("fmt.type:\t\t%d\n",fmt.type);
        printf("pix.pixelformat:\t%c%c%c%c\n",fmt.fmt.pix_mp.pixelformat & 0xFF, (fmt.fmt.pix_mp.pixelformat >> 8) & 0xFF,(fmt.fmt.pix_mp.pixelformat >> 16) & 0xFF, (fmt.fmt.pix_mp.pixelformat >> 24) & 0xFF);
        printf("pix.height:\t\t%d\n",fmt.fmt.pix_mp.height);
        printf("pix.width:\t\t%d\n",fmt.fmt.pix_mp.width);
        printf("pix.field:\t\t%d\n",fmt.fmt.pix_mp.field);
    }
	fmt.fmt.pix_mp.pixelformat = V4L2_PIX_FMT_YUV420;
	fmt.fmt.pix_mp.width = IMAGEWIDTH;
	fmt.fmt.pix_mp.height = IMAGEHEIGHT;
    if(ioctl(fd, VIDIOC_S_FMT, &fmt) == -1)
    {
        printf("Unable to set format\n");
        return FALSE;
    }

    return TRUE;
}

int v4l2_mem_ops()
{
	unsigned int i, j;

	memset(&reqbuf, 0, sizeof(reqbuf));
	reqbuf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE;
	reqbuf.memory = V4L2_MEMORY_MMAP;
	reqbuf.count = 4;

	if (ioctl(fd, VIDIOC_REQBUFS, &reqbuf) < 0) {
		if (errno == EINVAL)
			printf("Video capturing or mmap-streaming is not supported\\n");
		else
			perror("VIDIOC_REQBUFS");

		exit(EXIT_FAILURE);
	}

	/* We want at least five buffers. */

	if (reqbuf.count < 2) {
		/* You may need to free the buffers here. */
		printf("Not enough buffer memory\\n");
		exit(EXIT_FAILURE);
	}

	buffers = calloc(reqbuf.count, sizeof(*buffers));
	assert(buffers != NULL);

	for (i = 0; i < reqbuf.count; i++) {
		struct v4l2_plane planes[FMT_NUM_PLANES];

		memset(&buffer, 0, sizeof(buffer));
		buffer.type = reqbuf.type;
		buffer.memory = V4L2_MEMORY_MMAP;
		buffer.index = i;
		/* length in struct v4l2_buffer in multi-planar API stores the size
		 * of planes array. */
		buffer.length = FMT_NUM_PLANES;
		buffer.m.planes = planes;

		if (ioctl(fd, VIDIOC_QUERYBUF, &buffer) < 0) {
			perror("VIDIOC_QUERYBUF");
			exit(EXIT_FAILURE);
		}

		/* Every plane has to be mapped separately */
		for (j = 0; j < FMT_NUM_PLANES; j++) {
			buffers[i].length[j] = buffer.m.planes[j].length; /* remember for munmap() */

			buffers[i].start[j] = mmap(NULL, buffer.m.planes[j].length,
					 PROT_READ | PROT_WRITE, /* recommended */
					 MAP_SHARED,             /* recommended */
					 fd, buffer.m.planes[j].m.mem_offset);

			if (MAP_FAILED == buffers[i].start[j]) {
				/* If you do not exit here you should unmap() and free()
				   the buffers and planes mapped so far. */
				perror("mmap");
				exit(EXIT_FAILURE);
			}
		}
	}

		printf("Success to test mem\n");
		return EXIT_FAILURE;

}

int v4l2_frame_process()
{
    unsigned int n_buffers;
    enum v4l2_buf_type type;
    char file_name[100];
    char index_str[10];
    long long int extra_time = 0;
    long long int cur_time = 0;
    long long int last_time = 0;

	printf("count = : %d\n", reqbuf.count);
    //入队和开启采集
	int i;
	for (i = 0; i < reqbuf.count; i++) {
		buffer.index = i;
		if (ioctl(fd, VIDIOC_QBUF, &buffer) < 0) {
			printf("failed enqueue buffer\n");
			perror("VIDIOC_QBUF");
			return EXIT_FAILURE;
		}
	}
    type = V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE;
	if (ioctl(fd, VIDIOC_STREAMON, &type) < 0) {
		printf("failed start stream\n");
		perror("VIDIOC_STREAMON");
		return EXIT_FAILURE;
	}
	printf("Success to start stream\n");
    
	display_t dp = {0};

	if (display_init(&dp, IMAGEWIDTH, 
				IMAGEHEIGHT, SDL_IYUV_OVERLAY) < 0) {
		printf("Failed to init display\n");
		return -1;	
	}

    //出队，处理，写入yuv文件，入队，循环进行
    int loop = 3;
    while(1)
    {
        for(i = 0; i < reqbuf.count; i++)
        {
            //出队
            buffer.index = i;
			if (ioctl(fd, VIDIOC_DQBUF, &buffer) < 0) {
				printf("failed to dequeue\n");
				perror("ioctl");
				return EXIT_FAILURE;
			}
            
            //处理数据只是简单写入文件，名字以loop的次数和帧缓冲数目有关
            printf("grab image data OK\n");
            memset(file_name, 0, sizeof(file_name));
            memset(index_str, 0, sizeof(index_str));
            sprintf(index_str, "%d", loop * 4 + i);
            strcpy(file_name, IMAGE);
            strcat(file_name, index_str);
            strcat(file_name,".yuv");
            FILE *fp2 = fopen(file_name, "wb");
            if(!fp2)
            {
                printf("open %s error\n",file_name);
                return EXIT_FAILURE;
            }

	    int j;
		for (j = 0; j < FMT_NUM_PLANES; j++) {
			fwrite(buffers[i].start[j], buffers[i].length[j],1,fp2);
		}
            fclose(fp2);
            printf("save %s OK\n",file_name);

            //入队循环
            ioctl(fd, VIDIOC_QBUF, &buffer); 
        }

    }
    return TRUE;    
}

int v4l2_release()
{
    enum v4l2_buf_type type;

    //关闭流
    type = V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE;
	ioctl(fd, VIDIOC_STREAMOFF, &type);
    
	int i, j;
	/* Cleanup. */
	for (i = 0; i < reqbuf.count; i++)
		for (j = 0; j < FMT_NUM_PLANES; j++)
			munmap(buffers[i].start[j], buffers[i].length[j]);

    //关闭设备
    close(fd);
    return TRUE;
}

int main(int argc, char const *argv[])
{
    printf("begin....\n");
    sleep(1);

    v4l2_init();
    printf("init....\n");
    sleep(1);

    v4l2_mem_ops();
    printf("malloc....\n");
    sleep(1);

    v4l2_frame_process();
    printf("process....\n");
    sleep(1);

    v4l2_release();
    printf("release\n");
    
    return TRUE;
}
