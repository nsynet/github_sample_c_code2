/*
 * a simple char device driver: globalmem without mutex
 *
 * Copyright (C) 2014 Barry Song  (baohua@kernel.org)
 *
 * Licensed under GPLv2 or later.
 */

#include <linux/module.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/uaccess.h>

#define GLOBALMEM_SIZE	0x1000
#define MEM_CLEAR 0x1


struct globalmem_dev {
	struct cdev cdev;
	unsigned char mem[GLOBALMEM_SIZE];
};


static int globalmem_major = 0;
module_param(globalmem_major, int, S_IRUGO);
static dev_t devno;
static struct class *globalmem_class = NULL;
static int globalmem_major;
struct globalmem_dev *globalmem_devp = NULL;

static int globalmem_open(struct inode *inode, struct file *filp)
{
	filp->private_data = globalmem_devp;
	return 0;
}

static int globalmem_release(struct inode *inode, struct file *filp)
{
	return 0;
}

static long globalmem_ioctl(struct file *filp, unsigned int cmd,
			    unsigned long arg)
{
	struct globalmem_dev *dev = filp->private_data;

	switch (cmd) {
	case MEM_CLEAR:
		memset(dev->mem, 0, GLOBALMEM_SIZE);
		printk(KERN_INFO "globalmem is set to zero\n");
		break;

	default:
		return -EINVAL;
	}

	return 0;
}

static ssize_t globalmem_read(struct file *filp, char __user * buf, size_t size,
			      loff_t * ppos)
{
	unsigned long p = *ppos;
	unsigned int count = size;
	int ret = 0;
	struct globalmem_dev *dev = filp->private_data;

	if (p >= GLOBALMEM_SIZE)
		return 0;
	if (count > GLOBALMEM_SIZE - p)
		count = GLOBALMEM_SIZE - p;

	if (copy_to_user(buf, dev->mem + p, count)) {
		ret = -EFAULT;
	} else {
		*ppos += count;
		ret = count;

		printk(KERN_INFO "read %u bytes(s) from %lu\n", count, p);
	}

	return ret;
}

static ssize_t globalmem_write(struct file *filp, const char __user * buf,
			       size_t size, loff_t * ppos)
{
	unsigned long p = *ppos;
	unsigned int count = size;
	int ret = 0;
	struct globalmem_dev *dev = filp->private_data;

	if (p >= GLOBALMEM_SIZE)
		return 0;
	if (count > GLOBALMEM_SIZE - p)
		count = GLOBALMEM_SIZE - p;

	if (copy_from_user(dev->mem + p, buf, count))
		ret = -EFAULT;
	else {
		*ppos += count;
		ret = count;

		printk(KERN_INFO "written %u bytes(s) from %lu\n", count, p);
	}

	return ret;
}

static loff_t globalmem_llseek(struct file *filp, loff_t offset, int orig)
{
	loff_t ret = 0;
	switch (orig) {
	case 0:
		if (offset < 0) {
			ret = -EINVAL;
			break;
		}
		if ((unsigned int)offset > GLOBALMEM_SIZE) {
			ret = -EINVAL;
			break;
		}
		filp->f_pos = (unsigned int)offset;
		ret = filp->f_pos;
		break;
	case 1:
		if ((filp->f_pos + offset) > GLOBALMEM_SIZE) {
			ret = -EINVAL;
			break;
		}
		if ((filp->f_pos + offset) < 0) {
			ret = -EINVAL;
			break;
		}
		filp->f_pos += offset;
		ret = filp->f_pos;
		break;
	default:
		ret = -EINVAL;
		break;
	}
	return ret;
}

static const struct file_operations globalmem_fops = {
	.owner = THIS_MODULE,
	.llseek = globalmem_llseek,
	.read = globalmem_read,
	.write = globalmem_write,
	.unlocked_ioctl = globalmem_ioctl,
	.open = globalmem_open,
	.release = globalmem_release,
};


// devnode 回调函数
static char *globalmem_devnode(struct device *dev, umode_t *mode)
{
    if (mode != NULL) {
        *mode = 0666; // 所有用户可读写
    }
    return NULL;
}


static int __init globalmem_init(void)
{
	int ret;

    ret = alloc_chrdev_region(&devno, 0, 1, "globalmem");
    globalmem_major = MAJOR(devno);

	if (ret < 0)
		return ret;

	globalmem_devp = kzalloc(sizeof(struct globalmem_dev), GFP_KERNEL);
	if (!globalmem_devp) {
		ret = -ENOMEM;
		goto fail_malloc;
	}
   
	cdev_init(&(globalmem_devp->cdev), &globalmem_fops);
	globalmem_devp->cdev.owner = THIS_MODULE;
	ret = cdev_add(&(globalmem_devp->cdev), devno, 1);
	if (ret)
		printk(KERN_NOTICE "Error %d adding globalmem", ret);

    // 创建设备类
	globalmem_class = class_create(THIS_MODULE, "globalmem_class"); 
    if (IS_ERR(globalmem_class)) {
        unregister_chrdev_region(devno, 1);
        return PTR_ERR(globalmem_class);
    }
    
    // 设置设备节点权限
    globalmem_class->devnode = globalmem_devnode;
    
    // 创建设备节点
	device_create(globalmem_class, NULL, devno, NULL, "globalmem"); 
    
	return 0;

 fail_malloc:
	unregister_chrdev_region(devno, 1);
	return ret;
}
module_init(globalmem_init);

static void __exit globalmem_exit(void)
{
	if( globalmem_class != NULL )
	{
        // 销毁设备节点
		device_destroy(globalmem_class,  devno);
        
        // 销毁设备类        
		class_destroy(globalmem_class);
	}
	
	if(&globalmem_devp->cdev)
    {
        cdev_del(&globalmem_devp->cdev);        
    }

	kfree(globalmem_devp);
	unregister_chrdev_region(devno, 1);
}
module_exit(globalmem_exit);

MODULE_AUTHOR("Barry Song <baohua@kernel.org>");
MODULE_LICENSE("GPL v2");
