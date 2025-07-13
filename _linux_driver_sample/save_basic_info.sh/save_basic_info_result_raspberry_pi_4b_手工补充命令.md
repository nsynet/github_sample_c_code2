树莓派独有的命令树莓派独有的命令
raspberry pi 有一些自己的特殊命令，如下：
```
root\@raspberrypi:/usr/bin # ls -al raspi\*

    -rwxr-xr-x 1 root root 84356 2\u6708  10  2021 raspi-config
    -rwxr-xr-x 1 root root 20564 10\u6708  1  2019 raspi-gpio
    -rwxr-xr-x 1 root root  2383 7\u6708  18  2019 raspinfo
    lrwxrwxrwx 1 root root    22 4\u6708  30 22:09 raspistill -> /opt/vc/bin/raspistill
    lrwxrwxrwx 1 root root    20 4\u6708  30 22:09 raspivid -> /opt/vc/bin/raspivid
    lrwxrwxrwx 1 root root    23 4\u6708  30 22:09 raspividyuv -> /opt/vc/bin/raspividyuv
    lrwxrwxrwx 1 root root    20 4\u6708  30 22:09 raspiyuv -> /opt/vc/bin/raspiyuv
    root@raspberrypi:/usr/bin # 

```

拍照片 $ raspistill -o imagel. jpg
拍视频 $ raspivid -o video h264 -t 10000
树莓派信息 nisy@raspberrypi:/dev/bus/usb/001 $ raspinfo

nisy@raspberrypi:/dev/bus/usb/001 $ raspividyuv 
nisy@raspberrypi:/dev/bus/usb/001 $ raspiyuv
基本配置命令 sudo raspi-config
pinout

树莓派跑分 ./7zzs b

32bit GUI关闭时7zzs测试:
```
RAM size:    2048 MB,  # CPU hardware threads:   4
RAM usage:    889 MB,  # Benchmark threads:      4

                       Compressing  |                  Decompressing
Dict     Speed Usage    R/U Rating  |      Speed Usage    R/U Rating
         KiB/s     %   MIPS   MIPS  |      KiB/s     %   MIPS   MIPS

22:       4159   333   1216   4046  |      80710   362   1901   6886
23:       3981   345   1177   4057  |      82400   378   1887   7130
24:       3753   337   1198   4035  |      76818   360   1875   6741
25:       3684   357   1178   4207  |      74340   358   1849   6616
----------------------------------  | ------------------------------
Avr:      3894   343   1192   4086  |      78567   364   1878   6843
Tot:             354   1535   5465

```

coremark跑分

看到eembc官网的pi4 能跑到 48626分 （https://www.eembc.org/viewer/?benchmark_seq=13417%EF%BC%89)
我用自己的跑一下，设置开机直接进CLI，然后参考上面别人跑分时的“Compiler Flags‘，输入命令：
make XCFLAGS="-O2 -DMULTITHREAD=4 -DUSE_PTHREAD -DPERFORMANCE_RUN=1 -lrt -pthread"
很快跑完，还是有差距，不确信是否与gcc等有关：

```
2K performance run parameters for coremark.
CoreMark Size  : 666
Total ticks   : 14204
Total time (secs): 14.204000
Iterations/Sec  : 30977.189524
Iterations    : 440000
Compiler version : GCC8.3.0
Compiler flags  : -O2 -O2 -DMULTITHREAD=4 -DUSE_PTHREAD -DPERFORMANCE_RUN=1 -lrt -pthread -DPERFORMANCE_RUN=1 -lrt
Parallel PThreads : 4
Memory location : Please put data memory location here
(e.g. code in flash, data on heap etc)
seedcrc     : 0xe9f5
[0]crclist    : 0xe714
[1]crclist    : 0xe714
[2]crclist    : 0xe714
[3]crclist    : 0xe714
[0]crcmatrix   : 0x1fd7
[1]crcmatrix   : 0x1fd7
[2]crcmatrix   : 0x1fd7
[3]crcmatrix   : 0x1fd7
[0]crcstate   : 0x8e3a
[1]crcstate   : 0x8e3a
[2]crcstate   : 0x8e3a
[3]crcstate   : 0x8e3a
[0]crcfinal   : 0x33ff
[1]crcfinal   : 0x33ff
[2]crcfinal   : 0x33ff
[3]crcfinal   : 0x33ff
Correct operation validated. See README.md for run and reporting rules.
CoreMark 1.0 : 30977.189524 / GCC8.3.0 -O2 -O2 -DMULTITHREAD=4 -DUSE_PTHREAD -DPERFORMANCE_RUN=1 -lrt -pthread -DPERFORMANCE_RUN=1 -lrt / Heap / 4:PThreads

```

cd /sys/class/thermal
ls -al
cat thermal\_zone0/type
cat thermal\_zone0/temp
nisy@raspberrypi:/dev/bus/usb/001 $ cat /sys/class/thermal/thermal_zone*/type

cpu-thermal


nisy@raspberrypi:/usr/bin $ vcgencmd commands      
commands="commands, set_logging, bootloader_config, bootloader_version, cache_flush, codec_enabled, get_mem, get_rsts, measure_clock, measure_temp, measure_volts, get_hvs_asserts, get_config, get_throttled, pmicrd, pmicwr, read_ring_osc, version, readmr, otp_dump, set_vll_dir, set_backlight, get_lcd_info, arbiter, test_result, get_camera, enable_clock, scaling_kernel, scaling_sharpness, hdmi_ntsc_freqs, hdmi_adjust_clock, hdmi_status_show, hvs_update_fields, pwm_speedup, force_audio, hdmi_stream_channels, hdmi_channel_map, display_power, memtest, dispmanx_list, schmoo, render_bar, disk_notify, inuse_notify, sus_suspend, sus_status, sus_is_enabled, sus_stop_test_thread, egl_platform_switch, mem_validate, mem_oom, mem_reloc_stats, hdmi_cvt, hdmi_timings, file, vcos, ap_output_control, ap_output_post_processing, vchi_test_init, vchi_test_exit, pm_set_policy, pm_get_status, pm_show_stats, pm_start_logging, pm_stop_logging, vctest_memmap, vctest_start, vctest_stop, vctest_set, vctest_get"
nisy@raspberrypi:/usr/bin $ vcgencmd get_camera 
supported=0 detected=0, libcamera interfaces=0


cat /boot/config.txt
ls -al /sbin/init
v4l2-ctl --list-devices
v4l2-ctl -d /dev/video0 -D
v4l2-ctl -d /dev/video10 -D
v4l2-ctl -d /dev/video11 -D
v4l2-ctl -d /dev/video12 -D
v4l2-ctl -d /dev/video0 -L
v4l2-ctl --list-formats-ext



# 摄像头相关
//从基于Debian Bullseye 的 Raspberry Pi OS 开始的操作系统版本,将不再支持旧的相机系统和应用程序，而 Raspberry Pi 的 *libcamera-app*将被构建和预安装。

libcamera-apps是基于libcamera的相机控制例程，它提供了一系列的功能来控制和获取相机的图像和视频。以下是如何在树莓派上使用libcamera-apps的一些例子：

1. **libcamera-hello**：

这个应用主要用于输出从相机中获取的预览图像。你可以通过运行以下命令来使用它：


```bash
libcamera-hello
```
运行此命令后，你应该能在终端窗口中看到从相机捕获的实时预览图像。
2. **libcamera-jpeg**：

这个应用允许你通过相机获取高分辨率的JPEG图像。你可以使用以下命令来捕获并保存一张JPEG图像：


```bash
libcamera-jpeg -o output.jpg
```
这将使用相机捕获一张JPEG图像，并将其保存为`output.jpg`。
3. **libcamera-still**：

这个应用的功能类似于raspistill，它用于捕获相机的静态图像。你可以使用类似的命令来捕获图像，并指定输出文件名和格式。
4. **libcamera-vid**：

这是一个视频捕获程序，允许你录制相机的视频流。例如，要录制一个5秒钟的视频，你可以使用以下命令：


```bash
libcamera-vid -t 5 -o output.h264
```
这将录制一个5秒钟的视频，并将其保存为H.264格式的`output.h264`文件。
5. **libcamera-raw**：

这个程序允许你直接从相机中获取未压缩的原始RAW图像。这对于需要最大图像质量和后处理灵活性的用户来说非常有用。
6. **libcamera-detect**：

如果用户在树莓派上安装了TensorFlow Lite软件，则可以使用此程序进行目标检测图像捕获。这允许你使用机器学习模型在实时视频流中检测特定的对象或特征。

请注意，使用libcamera-apps之前，你需要确保你的树莓派已经正确安装了libcamera和相关依赖，并且相机硬件已经正确连接和配置。

为了获得更详细的信息和更多的使用示例，你可以查阅libcamera-apps的官方文档或相关的社区论坛。这些资源通常提供了更深入的指南和常见问题解答，帮助你更好地理解和使用这些应用。
