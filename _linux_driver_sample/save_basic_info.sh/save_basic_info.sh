####!/bin/bash

# detect if android
is_android() {
  if [ -f "/system/build.prop" ] || [ -f "/etc/build.prop" ]; then
    # 如果存在 build.prop 文件，可能是安卓系统
    ANDROID_VERSION=$(grep "ro.build.version.release" "/system/build.prop" 2>/dev/null | awk -F "=" '{print $2}' | sed 's/"//g')
    if [ -z "$ANDROID_VERSION" ]; then
      ANDROID_VERSION=$(grep "ro.build.version.release" "/etc/build.prop" 2>/dev/null | awk -F "=" '{print $2}' | sed 's/"//g')
    fi
    if [ -n "$ANDROID_VERSION" ]; then
      echo -e "\n##  当前环境是安卓 $ANDROID_VERSION 系统"
      return 0
    fi
  fi
  return 1
}


echo -e "[toc]\n"  >./save_basic_info_result.md
echo -e "\n#  ===================== system information ======================"  >>./save_basic_info_result.md
if is_android; then
else
echo -e "\n##  cat /etc/os-release \n\`\`\`\n$(cat /etc/os-release) \n\`\`\`"  >>./save_basic_info_result.md
fi
echo -e "\n##  uname -a \n\`\`\`\n$(uname -a) \n\`\`\`"  >>./save_basic_info_result.md


echo -e "\n#  =====================CPU information ====================="  >>./save_basic_info_result.md
echo -e "\n##  lscpu \n\`\`\`\n$(lscpu) \n\`\`\`"  >>./save_basic_info_result.md


# kenerl configure
echo -e "\n#  ===================== KERNEL config ====================="  >>./save_basic_info_result.md
echo -e "\n##  zcat /proc/config.gz \n\`\`\`\n$(zcat /proc/config.gz) \n\`\`\`"  >>./save_basic_info_result.md

# 显示内存信息
echo -e "\n#  =====================内存信息====================="  >>./save_basic_info_result.md
#free -h | grep Mem | awk '{printf "总内存: %s\n可用内存: %s\n已用内存: %s\n", $2, $7, $3}' >>./save_basic_info_result.md
echo -e "\n##  free -h \n\`\`\`\n$(free -h) \n\`\`\`"  >>./save_basic_info_result.md

# 显示磁盘使用情况
echo -e "\n#  =====================磁盘使用情况====================="  >>./save_basic_info_result.md
echo -e "\n##  df -h \n\`\`\`\n$(df -h) \n\`\`\`"  >>./save_basic_info_result.md

# 显示网络接口信息
echo -e "\n#  =====================网络接口信息====================="  >>./save_basic_info_result.md
ip addr | grep 'state UP' -A 2 | grep -v 'state UP' | grep -v 'lo' >>./save_basic_info_result.md
echo -e "\n##  ifconfig \n\`\`\`\n$(ifconfig) \n\`\`\`"  >>./save_basic_info_result.md

# 显示当前登录用户信息
echo -e "\n#  =====================当前登录用户信息====================="  >>./save_basic_info_result.md
echo -e "\n##  w \n\`\`\`\n$(w) \n\`\`\`"  >>./save_basic_info_result.md

# 显示系统进程信息
echo -e "\n#  =====================显示系统进程信息====================="  >>./save_basic_info_result.md
## show %CPU,%MEM
#echo -e "\n##  ps aux \n\`\`\`\n$(ps aux --sort=-%cpu | head -5)"  >>./save_basic_info_result.md

## show PPID
echo -e "\n##  ps -ef \n\`\`\`\n$(ps -ef) \n\`\`\`"  >>./save_basic_info_result.md

## common cmman
echo -e "\n#  =====================常用命令 ====================="  >>./save_basic_info_result.md
echo -e "\n##  lspci \n\`\`\`\n$(lspci) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  lsusb \n\`\`\`\n$(lsusb) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  lsipc \n\`\`\`\n$(lsipc) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  lsblk \n\`\`\`\n$(lsblk) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  fdisk -l \n\`\`\`\n$(fdisk -l) \n\`\`\`"  >>./save_basic_info_result.md

echo -e "\n##  i2cdetect -l \n\`\`\`\n$(i2cdetect -l) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  i2cdetect -y 0 \n\`\`\`\n$(i2cdetect -y 0) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  i2cdetect -y 1 \n\`\`\`\n$(i2cdetect -y 1) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  i2cdetect -y 2 \n\`\`\`\n$(i2cdetect -y 2) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  i2cdetect -y 3 \n\`\`\`\n$(i2cdetect -y 3) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  i2cdetect -y 4 \n\`\`\`\n$(i2cdetect -y 4) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  i2cdetect -y 5 \n\`\`\`\n$(i2cdetect -y 5) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  i2cdetect -y 6 \n\`\`\`\n$(i2cdetect -y 6) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  i2cdetect -y 7 \n\`\`\`\n$(i2cdetect -y 7) \n\`\`\`"  >>./save_basic_info_result.md

echo -e "\n##  blkid \n\`\`\`\n$(blkid) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  lsmod \n\`\`\`\n$(lsmod) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  ls -al /bin \n\`\`\`\n$(ls -al /bin) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  busybox \n\`\`\`\n$(busybox) \n\`\`\`"  >>./save_basic_info_result.md
if is_android; then
	echo -e "\n##  ls -al /vendor/bin \n\`\`\`\n$(ls -al /vendor/bin) \n\`\`\`"  >>./save_basic_info_result.md
	echo -e "\n##  ls -al /system/bin \n\`\`\`\n$(ls -al /system/bin) \n\`\`\`"  >>./save_basic_info_result.md
	echo -e "\n##  adb shell getprop \n\`\`\`\n$(adb shell getprop) \n\`\`\`"  >>./save_basic_info_result.md
	echo -e "\n##  dumpsys -l \n\`\`\`\n$(dumpsys -l) \n\`\`\`"  >>./save_basic_info_result.md
	echo -e "\n##  toybox  \n\`\`\`\n$(toybox) \n\`\`\`"  >>./save_basic_info_result.md
fi



## sysfs
echo -e "\n#  ===================== /sys/ 文件系统 ====================="  >>./save_basic_info_result.md
echo -e "\n##  ls -al /sys/devices/platform/ \n\`\`\`\n$(ls -al /sys/devices/platform/) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  cat /sys/devices/system/cpu/cpu*/cpufreq/cpuinfo_cur_freq \n\`\`\`\n$(cat /sys/devices/system/cpu/cpu*/cpufreq/cpuinfo_cur_freq) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  ls -al /sys/kernel/debug \n\`\`\`\n$(ls -al /sys/kernel/debug) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  cat /sys/kernel/debug/gpio \n\`\`\`\n$(cat /sys/kernel/debug/gpio) \n\`\`\`"  >>./save_basic_info_result.md

echo -e "\n##  ===================== 打印 /sys/class/video4linux/video* ====================="  >>./save_basic_info_result.md
echo -e "\n##  ls -al /sys/class/video4linux \n\`\`\`\n$(ls -al /sys/class/video4linux) \n\`\`\`"  >>./save_basic_info_result.md
for i in /sys/class/video4linux/video* ; do echo $i ;echo dev:$(cat $i/dev); echo name:$(cat $i/name);echo index:$(cat $i/index);echo link_name:$(cat $i/link_name);echo; done  >>./save_basic_info_result.md
echo -e "\n##  ===================== 打印 /sys/class/video4linux/v4l-subdev* ====================="  >>./save_basic_info_result.md
for i in /sys/class/video4linux/v4l-subdev* ; do echo $i ;echo dev:$(cat $i/dev); echo name:$(cat $i/name);echo index:$(cat $i/index);echo link_name:$(cat $i/link_name);echo; done >>./save_basic_info_result.md
echo -e "\n##  ===================== 打印 /sys/bus/media/devices/media* ====================="  >>./save_basic_info_result.md
echo -e "\n##  ls -al /sys/bus/media/ \n\`\`\`\n$(ls -al /sys/bus/media/) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  ls -al /sys/bus/media/devices \n\`\`\`\n$(ls -al /sys/bus/media/devices) \n\`\`\`"  >>./save_basic_info_result.md
for i in /sys/bus/media/devices/media* ; do echo $i ;echo dev:$(cat $i/dev); echo model:$(cat $i/model);echo; done >>./save_basic_info_result.md

echo -e "\n##  ===================== 打印 /sys/ 的thermal相关 ====================="  >>./save_basic_info_result.md
echo -e "\n##  cat /sys/devices/virtual/thermal/thermal_zone*/type \n\`\`\`\n$(cat /sys/devices/virtual/thermal/thermal_zone*/type) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  cat /sys/devices/virtual/thermal/cooling_device*/type \n\`\`\`\n$(cat /sys/devices/virtual/thermal/cooling_device*/type) \n\`\`\`"  >>./save_basic_info_result.md


if is_android; then
	echo -e "\n##  dumpsys media.camera \n\`\`\`\n$(dumpsys media.camera) \n\`\`\`"  >>./save_basic_info_result.md
	echo -e "\n##  dumpsys thermalservice \n\`\`\`\n$(dumpsys thermalservice) \n\`\`\`"  >>./save_basic_info_result.md
fi

## procfs
echo -e "\n#  ===================== /proc/ 文件系统 ====================="  >>./save_basic_info_result.md
echo -e "\n##  cat /proc/cmdline \n\`\`\`\n$(cat /proc/cmdline) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  cat /proc/cpuinfo \n\`\`\`\n$(cat /proc/cpuinfo) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  cat /proc/meminfo \n\`\`\`\n$(cat /proc/meminfo) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  cat /proc/driver \n\`\`\`\n$(cat /proc/driver) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  cat /proc/iomem \n\`\`\`\n$(cat /proc/iomem) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  cat /proc/mounts \n\`\`\`\n$(cat /proc/mounts) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  cat /proc/interrupts \n\`\`\`\n$(cat /proc/interrupts) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  cat /proc/devices \n\`\`\`\n$(cat /proc/devices) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  cat /proc/sys/kernel/printk \n\`\`\`\n$(cat /proc/sys/kernel/printk) \n\`\`\`"  >>./save_basic_info_result.md
#echo -e "\n##  =====================kernel config ====================="  >>./save_basic_info_result.md
#zcat /proc/config.gz  >>./save_basic_info_result.md

## other fs
echo -e "\n#  ===================== 其他 ====================="  >>./save_basic_info_result.md
echo -e "\n##  ls -al /dev/ \n\`\`\`\n$(ls -al /dev) \n\`\`\`"  >>./save_basic_info_result.md
echo -e "\n##  ls -al /dev/block/by-name/ \n\`\`\`\n$(ls -al /dev/block/by-name/) \n\`\`\`"  >>./save_basic_info_result.md
