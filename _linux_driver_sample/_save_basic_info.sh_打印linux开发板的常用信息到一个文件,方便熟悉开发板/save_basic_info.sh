#!/bin/bash

# 检测是否是安卓系统
is_android() {
  if [ -f "/system/build.prop" ] || [ -f "/etc/build.prop" ]; then
    # 如果存在 build.prop 文件，可能是安卓系统
    ANDROID_VERSION=$(grep "ro.build.version.release" "/system/build.prop" 2>/dev/null | awk -F "=" '{print $2}' | sed 's/"//g')
    if [ -z "$ANDROID_VERSION" ]; then
      ANDROID_VERSION=$(grep "ro.build.version.release" "/etc/build.prop" 2>/dev/null | awk -F "=" '{print $2}' | sed 's/"//g')
    fi
    if [ -n "$ANDROID_VERSION" ]; then
      echo -e "\n ##  当前环境是安卓 $ANDROID_VERSION 系统"
      return 0
    fi
  fi
  return 1
}

# 检测是否是纯 Linux 系统
is_linux() {
  if [ -f "/etc/os-release" ]; then
    LINUX_VERSION=$(grep "PRETTY_NAME" "/etc/os-release" 2>/dev/null | awk -F "=" '{print $2}' | sed 's/"//g')
    if [ -n "$LINUX_VERSION" ]; then
      echo -e "\n ##  当前环境是纯 Linux 系统，版本为：$LINUX_VERSION"
      return 0
    fi
  fi
  return 1
}

# 显示系统信息
echo -e "\n #  =====================系统信息======================"  >>./save_basic_info_result.txt
echo -e "\n ##  主机名: \n $(hostname)" >>./save_basic_info_result.txt
echo -e "\n ##  操作系统版本: \n $(cat /etc/os-release)" >>./save_basic_info_result.txt
echo -e "\n ##  内核版本: \n $(uname -r)" >>./save_basic_info_result.txt
echo -e "\n ##  系统运行时间: \n $(uptime -p)" >>./save_basic_info_result.txt


# 显示 CPU 信息
echo -e "\n #  =====================CPU 信息====================="  >>./save_basic_info_result.txt
echo -e "\n ##  CPU 型号: \n $(lscpu | grep 'Model name' | awk -F: '{print $2}' | xargs)" >>./save_basic_info_result.txt
echo -e "\n ##  CPU 核心数: \n $(lscpu | grep 'CPU(s):' | head -1 | awk -F: '{print $2}' | xargs)" >>./save_basic_info_result.txt
echo -e "\n ##  CPU 逻辑处理器数: \n $(lscpu | grep 'Thread(s) per core:' | awk -F: '{print $2}' | xargs | sed 's/ /x/' | awk -F 'x' '{print $1*$2*$3}' | xargs)" >>./save_basic_info_result.txt

# 显示内存信息
echo -e "\n #  =====================内存信息====================="  >>./save_basic_info_result.txt
free -h | grep Mem | awk '{printf "总内存: %s\n可用内存: %s\n已用内存: %s\n", $2, $7, $3}' >>./save_basic_info_result.txt

# 显示磁盘使用情况
echo -e "\n #  =====================磁盘使用情况====================="  >>./save_basic_info_result.txt
echo -e "\n ##  df -h \n $(df -h)" >>./save_basic_info_result.txt

# 显示网络接口信息
echo -e "\n #  =====================网络接口信息====================="  >>./save_basic_info_result.txt
ip addr | grep 'state UP' -A 2 | grep -v 'state UP' | grep -v 'lo' >>./save_basic_info_result.txt

# 显示当前登录用户信息
echo -e "\n #  =====================当前登录用户信息====================="  >>./save_basic_info_result.txt
echo -e "\n ##  w \n $(w)" >>./save_basic_info_result.txt

# 显示系统进程信息
echo -e "\n #  =====================显示系统进程信息====================="  >>./save_basic_info_result.txt
## show %CPU,%MEM
#echo -e "\n ##  ps aux \n $(ps aux --sort=-%cpu | head -5)"  >>./save_basic_info_result.txt

## show PPID
echo -e "\n ##  ps -ef \n $(ps -ef)" >>./save_basic_info_result.txt

## common cmman
echo -e "\n #  =====================常用命令 ====================="  >>./save_basic_info_result.txt
echo -e "\n ##  lspci \n $(lspci)" >>./save_basic_info_result.txt
echo -e "\n ##  lsusb \n $(lsusb)" >>./save_basic_info_result.txt
echo -e "\n ##  fdisk -l \n $(fdisk -l)" >>./save_basic_info_result.txt

echo -e "\n ##  i2cdetect -l \n $(i2cdetect -l)" >>./save_basic_info_result.txt
echo -e "\n ##  i2cdetect -y 0 \n $(i2cdetect -y 0)" >>./save_basic_info_result.txt
echo -e "\n ##  i2cdetect -y 1 \n $(i2cdetect -y 1)" >>./save_basic_info_result.txt
echo -e "\n ##  i2cdetect -y 2 \n $(i2cdetect -y 2)" >>./save_basic_info_result.txt
echo -e "\n ##  i2cdetect -y 3 \n $(i2cdetect -y 3)" >>./save_basic_info_result.txt
echo -e "\n ##  i2cdetect -y 4 \n $(i2cdetect -y 4)" >>./save_basic_info_result.txt
echo -e "\n ##  i2cdetect -y 5 \n $(i2cdetect -y 5)" >>./save_basic_info_result.txt
echo -e "\n ##  i2cdetect -y 6 \n $(i2cdetect -y 6)" >>./save_basic_info_result.txt
echo -e "\n ##  i2cdetect -y 7 \n $(i2cdetect -y 7)" >>./save_basic_info_result.txt

echo -e "\n ##  blkid \n $(blkid)" >>./save_basic_info_result.txt
echo -e "\n ##  lsmod \n $(lsmod)" >>./save_basic_info_result.txt
echo -e "\n ##  ls -al /bin \n $(ls -al /bin)" >>./save_basic_info_result.txt
echo -e "\n ##  busybox $(busybox)" >>./save_basic_info_result.txt
if is_android; then
	echo -e "\n ##  ls -al /vendor/bin \n $(ls -al /vendor/bin)" >>./save_basic_info_result.txt
	echo -e "\n ##  ls -al /system/bin \n $(ls -al /system/bin)" >>./save_basic_info_result.txt
	echo -e "\n ##  adb shell getprop \n $(adb shell getprop)" >>./save_basic_info_result.txt
	echo -e "\n ##  dumpsys -l \n $(dumpsys -l)" >>./save_basic_info_result.txt
	echo -e "\n ##  toybox $(toybox)" >>./save_basic_info_result.txt
fi



## sysfs
echo -e "\n #  ===================== /sys/ 文件系统 ====================="  >>./save_basic_info_result.txt
echo -e "\n ##  ls -al /sys/devices/platform/ \n $(ls -al /sys/devices/platform/)" >>./save_basic_info_result.txt
echo -e "\n ##  cat /sys/devices/system/cpu/cpu*/cpufreq/cpuinfo_cur_freq \n $(cat /sys/devices/system/cpu/cpu*/cpufreq/cpuinfo_cur_freq)" >>./save_basic_info_result.txt
echo -e "\n ##  ls -al /sys/kernel/debug \n $(ls -al /sys/kernel/debug)" >>./save_basic_info_result.txt
echo -e "\n ##  cat /sys/kernel/debug/gpio \n $(cat /sys/kernel/debug/gpio)" >>./save_basic_info_result.txt

echo -e "\n ##  ===================== 打印 /sys/class/video4linux/video* ====================="  >>./save_basic_info_result.txt
echo -e "\n ##  ls -al /sys/class/video4linux \n $(ls -al /sys/class/video4linux)" >>./save_basic_info_result.txt
for i in /sys/class/video4linux/video* ; do echo $i ;echo dev:$(cat $i/dev); echo name:$(cat $i/name);echo index:$(cat $i/index);echo link_name:$(cat $i/link_name);echo; done  >>./save_basic_info_result.txt
echo -e "\n ##  ===================== 打印 /sys/class/video4linux/v4l-subdev* ====================="  >>./save_basic_info_result.txt
for i in /sys/class/video4linux/v4l-subdev* ; do echo $i ;echo dev:$(cat $i/dev); echo name:$(cat $i/name);echo index:$(cat $i/index);echo link_name:$(cat $i/link_name);echo; done >>./save_basic_info_result.txt
echo -e "\n ##  ===================== 打印 /sys/bus/media/devices/media* ====================="  >>./save_basic_info_result.txt
echo -e "\n ##  ls -al /sys/bus/media/devices \n $(ls -al /sys/bus/media/devices)" >>./save_basic_info_result.txt
for i in /sys/bus/media/devices/media* ; do echo $i ;echo dev:$(cat $i/dev); echo model:$(cat $i/model);echo; done >>./save_basic_info_result.txt

echo -e "\n ##  ===================== 打印 /sys/ 的thermal相关 ====================="  >>./save_basic_info_result.txt
echo -e "\n ##  cat /sys/devices/virtual/thermal/thermal_zone*/type \n $(cat /sys/devices/virtual/thermal/thermal_zone*/type)" >>./save_basic_info_result.txt
echo -e "\n ##  cat /sys/devices/virtual/thermal/cooling_device*/type \n $(cat /sys/devices/virtual/thermal/cooling_device*/type)" >>./save_basic_info_result.txt


if is_android; then
	echo -e "\n ##  dumpsys media.camera \n $(dumpsys media.camera)" >>./save_basic_info_result.txt
	echo -e "\n ##  dumpsys thermalservice \n $(dumpsys thermalservice)" >>./save_basic_info_result.txt
fi

## procfs
echo -e "\n #  ===================== /proc/ 文件系统 ====================="  >>./save_basic_info_result.txt
echo -e "\n ##  cat /proc/cmdline \n $(cat /proc/cmdline)"  >>./save_basic_info_result.txt
echo -e "\n ##  cat /proc/cpuinfo \n $(cat /proc/cpuinfo)" >>./save_basic_info_result.txt
echo -e "\n ##  cat /proc/meminfo \n $(cat /proc/meminfo)" >>./save_basic_info_result.txt
echo -e "\n ##  cat /proc/driver \n $(cat /proc/driver)" >>./save_basic_info_result.txt
echo -e "\n ##  cat /proc/iomem \n $(cat /proc/iomem)" >>./save_basic_info_result.txt
echo -e "\n ##  cat /proc/mounts \n $(cat /proc/mounts)" >>./save_basic_info_result.txt
echo -e "\n ##  cat /proc/interrupts \n $(cat /proc/interrupts)" >>./save_basic_info_result.txt
echo -e "\n ##  cat /proc/devices \n $(cat /proc/devices)" >>./save_basic_info_result.txt
echo -e "\n ##  cat /proc/sys/kernel/printk \n $(cat /proc/sys/kernel/printk)" >>./save_basic_info_result.txt
#echo -e "\n ##  =====================kernel config ====================="  >>./save_basic_info_result.txt
#zcat /proc/config.gz  >>./save_basic_info_result.txt

## other fs
echo -e "\n #  ===================== 其他 ====================="  >>./save_basic_info_result.txt
echo -e "\n ##  ls -al /dev/ \n $(ls -al /dev)" >>./save_basic_info_result.txt
echo -e "\n ##  ls -al /dev/block/by-name/ \n $(ls -al /dev/block/by-name/)" >>./save_basic_info_result.txt
