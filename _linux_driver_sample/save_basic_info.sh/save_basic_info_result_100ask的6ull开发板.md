
##  主机名: 
 imx6ull

##  操作系统版本: 
 Buildroot 2019.02

##  内核版本: 
 4.9.88


##  CPU 型号: 
 

##  CPU 核心数: 
 

##  CPU 逻辑处理器数: 
 0

##  df -h 
 Filesystem                Size      Used Available Use% Mounted on
/dev/root                 1.9G    436.9M      1.4G  23% /
devtmpfs                 84.1M         0     84.1M   0% /dev
tmpfs                   244.6M         0    244.6M   0% /dev/shm
tmpfs                   244.6M      1.1M    243.5M   0% /tmp
tmpfs                   244.6M    160.0K    244.4M   0% /run
    link/ether 00:01:3f:2d:3e:4d brd ff:ff:ff:ff:ff:ff

##  w 
 USER		TTY		IDLE	TIME		 HOST
root            ttymxc0         00:00   Jan  1 00:00:52  

##  ps -ef 
 PID   USER     COMMAND
    1 root     init [3]
    2 root     [kthreadd]
    3 root     [ksoftirqd/0]
    5 root     [kworker/0:0H]
    6 root     [kworker/u2:0]
    7 root     [rcu_preempt]
    8 root     [rcu_sched]
    9 root     [rcu_bh]
   10 root     [migration/0]
   11 root     [lru-add-drain]
   12 root     [cpuhp/0]
   13 root     [kdevtmpfs]
   14 root     [oom_reaper]
   15 root     [writeback]
   16 root     [kcompactd0]
   17 root     [crypto]
   18 root     [bioset]
   19 root     [kblockd]
   20 root     [kworker/0:1]
   21 root     [ata_sff]
   22 root     [cfg80211]
   23 root     [watchdogd]
   24 root     [rpciod]
   25 root     [xprtiod]
   26 root     [kswapd0]
   27 root     [vmstat]
   28 root     [nfsiod]
   74 root     [bioset]
   75 root     [bioset]
   76 root     [bioset]
   77 root     [bioset]
   78 root     [bioset]
   79 root     [bioset]
   80 root     [bioset]
   81 root     [bioset]
   82 root     [bioset]
   83 root     [bioset]
   84 root     [bioset]
   85 root     [bioset]
   86 root     [bioset]
   87 root     [bioset]
   88 root     [bioset]
   89 root     [bioset]
   90 root     [bioset]
   91 root     [bioset]
   92 root     [bioset]
   93 root     [bioset]
   94 root     [bioset]
   95 root     [bioset]
   96 root     [bioset]
   97 root     [bioset]
   98 root     [spi32766]
   99 root     [spi0]
  100 root     [spi2]
  104 root     [ci_otg]
  105 root     [kworker/0:2]
  106 root     [kworker/u3:0]
  107 root     [hci0]
  108 root     [hci0]
  110 root     [cfinteractive]
  111 root     [kworker/u3:2]
  112 root     [irq/64-mmc0]
  113 root     [irq/98-2190000.]
  114 root     [irq/65-mmc1]
  115 root     [mxs_dcp_chan/sh]
  116 root     [mxs_dcp_chan/ae]
  121 root     [bioset]
  122 root     [mmcqd/1]
  123 root     [bioset]
  124 root     [mmcqd/1boot0]
  125 root     [bioset]
  126 root     [mmcqd/1boot1]
  127 root     [bioset]
  128 root     [mmcqd/1rpmb]
  129 root     [kworker/u2:2]
  130 root     [ipv6_addrconf]
  131 root     [krfcommd]
  132 root     [pxp_dispatch]
  133 root     [irq/44-imx_ther]
  134 root     [kworker/0:1H]
  135 root     [jbd2/mmcblk1p2-]
  136 root     [ext4-rsv-conver]
  170 root     /sbin/syslogd -m 0
  173 root     /sbin/klogd
  184 root     /usr/bin/dbus-daemon --syslog --fork --print-pid 4 --print-address 6 --session
  185 root     /home/myir/mxbackend
  186 root     /home/myir/mxapp --platform linuxfb
  199 root     /sbin/udevd -d
  231 dbus     dbus-daemon --system
  262 root     /usr/sbin/connmand -n
  266 root     /usr/sbin/ofonod -n
  273 root     /usr/sbin/wpa_supplicant -u
  275 root     /usr/sbin/ntpd -g
  283 root     nginx: master process /usr/sbin/nginx
  285 www-data nginx: worker process
  288 root     /usr/sbin/sshd
  300 root     smbd -D
  303 root     {smbd-notifyd} smbd -D
  304 root     {cleanupd} smbd -D
  305 root     {lpqd} smbd -D
  306 root     nmbd -D
  311 root     -sh
  324 root     [kworker/0:0]
  334 root     {save_basic_info} /bin/bash ./save_basic_info.sh
  374 root     ps -ef

##  lspci 
 

##  lsusb 
 Bus 001 Device 003: ID 0bda:b720  
Bus 001 Device 002: ID 0424:2514  
Bus 001 Device 001: ID 1d6b:0002  

##  i2cdetect -l 
 i2c-1	i2c       	21a4000.i2c                     	I2C adapter
i2c-0	i2c       	21a0000.i2c                     	I2C adapter

##  i2cdetect -y 0 
      0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
00:          -- -- -- -- -- -- -- -- -- -- -- -- -- 
10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- 1e -- 
20: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
30: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
40: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
50: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
60: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
70: -- -- -- -- -- -- -- --                         

##  i2cdetect -y 1 
      0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
00:          -- -- -- -- -- -- -- -- -- -- -- -- -- 
10: -- -- -- -- -- -- -- -- -- -- UU -- -- -- -- -- 
20: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
30: -- -- -- -- -- -- -- -- -- UU -- -- -- -- -- -- 
40: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
50: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
60: 60 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
70: -- -- -- -- -- -- -- --                         

##  i2cdetect -y 2 
 

##  i2cdetect -y 3 
 

##  blkid 
 /dev/mmcblk1p2: UUID="687f76b7-a401-4467-ae0b-7080fc94aaa8"

##  lsmod 
 Module                  Size  Used by

##  ls -al /bin 
 total 1707
drwxr-xr-x    2 root     root          2048 Jun  3  2020 .
drwxr-xr-x   24 root     root          1024 Jan  1  1970 ..
lrwxrwxrwx    1 root     root             7 Jun  3  2020 arch -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 ash -> busybox
-rwxr-xr-x    1 root     root        603060 Jun  3  2020 bash
-rwsr-xr-x    1 root     root        699664 Jun  3  2020 busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 cat -> busybox
-rwxr-xr-x    1 root     root          6952 Jun  3  2020 chattr
lrwxrwxrwx    1 root     root             7 Jun  3  2020 chgrp -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 chmod -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 chown -> busybox
-rwxr-xr-x    1 root     root          1342 Jun  3  2020 compile_et
lrwxrwxrwx    1 root     root             7 Jun  3  2020 cp -> busybox
-rwxr-xr-x    1 root     root        108236 Jun  3  2020 cpio
lrwxrwxrwx    1 root     root             7 Jun  3  2020 date -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 dd -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 df -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 dmesg -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 dnsdomainname -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 dumpkmap -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 echo -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 egrep -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 false -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 fdflush -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 fgrep -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 getopt -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 grep -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 gunzip -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 gzip -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 hostname -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 kill -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 link -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 linux32 -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 linux64 -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 ln -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 login -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 ls -> busybox
-rwxr-xr-x    1 root     root          5968 Jun  3  2020 lsattr
-rwxr-xr-x    1 root     root          1102 Jun  3  2020 mk_cmds
lrwxrwxrwx    1 root     root             7 Jun  3  2020 mkdir -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 mknod -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 mktemp -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 more -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 mount -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 mountpoint -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 mt -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 mv -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 netstat -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 nice -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 nuke -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 pidof -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 ping -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 pipe_progress -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 printenv -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 ps -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 pwd -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 resume -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 rm -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 rmdir -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 run-parts -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 sed -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 setarch -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 setpriv -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 setserial -> busybox
lrwxrwxrwx    1 root     root             4 Jun  3  2020 sh -> bash
lrwxrwxrwx    1 root     root             7 Jun  3  2020 sleep -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 stty -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 su -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 sync -> busybox
-rwxr-xr-x    1 root     root        316584 Jun  3  2020 tar
lrwxrwxrwx    1 root     root             7 Jun  3  2020 touch -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 true -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 umount -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 uname -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 usleep -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 vi -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 watch -> busybox
lrwxrwxrwx    1 root     root             7 Jun  3  2020 zcat -> busybox

##  busybox BusyBox v1.29.3 (2020-06-03 12:03:16 CST) multi-call binary.
BusyBox is copyrighted by many authors between 1998-2015.
Licensed under GPLv2. See source distribution for detailed
copyright notices.

Usage: busybox [function [arguments]...]
   or: busybox --list[-full]
   or: busybox --install [-s] [DIR]
   or: function [arguments]...

	BusyBox is a multi-call binary that combines many common Unix
	utilities into a single executable.  Most people will create a
	link to busybox for each function they wish to use and BusyBox
	will act like whatever it was invoked as.

Currently defined functions:
	[, [[, addgroup, adduser, ar, arch, arp, arping, ash, awk, basename, blkid, bunzip2, bzcat, cat, chattr, chgrp, chmod, chown, chroot, chrt, chvt, cksum, clear, cmp, cp,
	cpio, crond, crontab, cut, date, dc, dd, deallocvt, delgroup, deluser, depmod, devmem, df, diff, dirname, dmesg, dnsd, dnsdomainname, dos2unix, du, dumpkmap, echo, egrep,
	eject, env, ether-wake, expr, factor, fallocate, false, fbset, fdflush, fdformat, fdisk, fgrep, find, flock, fold, free, freeramdisk, fsck, fsfreeze, fstrim, fuser, getopt,
	getty, grep, gunzip, gzip, halt, hdparm, head, hexdump, hexedit, hostid, hostname, hwclock, i2cdetect, i2cdump, i2cget, i2cset, id, ifconfig, ifdown, ifup, inetd, init,
	insmod, install, ip, ipaddr, ipcrm, ipcs, iplink, ipneigh, iproute, iprule, iptunnel, kill, killall, killall5, klogd, last, less, link, linux32, linux64, linuxrc, ln,
	loadfont, loadkmap, logger, login, logname, losetup, ls, lsattr, lsmod, lsof, lspci, lsscsi, lsusb, lzcat, lzma, lzopcat, makedevs, md5sum, mdev, mesg, microcom, mkdir,
	mkdosfs, mke2fs, mkfifo, mknod, mkpasswd, mkswap, mktemp, modinfo, modprobe, more, mount, mountpoint, mt, mv, nameif, netstat, nice, nl, nohup, nproc, nslookup, nuke, od,
	openvt, partprobe, passwd, paste, patch, pidof, ping, pipe_progress, pivot_root, poweroff, printenv, printf, ps, pwd, rdate, readlink, readprofile, realpath, reboot, renice,
	reset, resize, resume, rm, rmdir, rmmod, route, run-init, run-parts, runlevel, sed, seq, setarch, setconsole, setfattr, setkeycodes, setlogcons, setpriv, setserial, setsid,
	sh, sha1sum, sha256sum, sha3sum, sha512sum, shred, sleep, sort, start-stop-daemon, strings, stty, su, sulogin, svc, svok, swapoff, swapon, switch_root, sync, sysctl,
	syslogd, tail, tar, tc, tee, telnet, test, tftp, time, top, touch, tr, traceroute, true, truncate, tty, ubirename, udhcpc, uevent, umount, uname, uniq, unix2dos, unlink,
	unlzma, unlzop, unxz, unzip, uptime, usleep, uudecode, uuencode, vconfig, vi, vlock, w, watch, watchdog, wc, wget, which, who, whoami, xargs, xxd, xz, xzcat, yes, zcat

##  ls -al /sys/devices/platform/ 
 total 0
drwxr-xr-x   10 root     root             0 Jan  1 00:00 .
drwxr-xr-x   10 root     root             0 Jan  1 00:00 ..
drwxr-xr-x    4 root     root             0 Jan  1 00:00 Fixed MDIO bus.0
drwxr-xr-x    4 root     root             0 Jan  1 00:00 Vivante GCCore
drwxr-xr-x    3 root     root             0 Jan  1 00:00 alarmtimer
drwxr-xr-x    3 root     root             0 Jan  1 00:00 imx6q-cpufreq
drwxr-xr-x    2 root     root             0 Jan  1 00:24 power
drwxr-xr-x    4 root     root             0 Jan  1 00:00 reg-dummy
drwxr-xr-x    3 root     root             0 Jan  1 00:00 regulatory.0
drwxr-xr-x    3 root     root             0 Jan  1 00:00 snd-soc-dummy
-rw-r--r--    1 root     root          4096 Jan  1 00:00 uevent

##  cat /sys/devices/system/cpu/cpu*/cpufreq/cpuinfo_cur_freq 
 792000

##  ls -al /sys/kernel/debug 
 total 0
dr-xr-xr-x    2 root     root             0 Jan  1 00:24 .
drwxr-xr-x    9 root     root             0 Jan  1 00:24 ..

##  cat /sys/kernel/debug/gpio 
 
/sys/class/video4linux/video0
dev:81:0
name:PxP
index:0
link_name:

/sys/class/video4linux/v4l-subdev*
dev:
name:
index:
link_name:

/sys/bus/media/devices/media*
dev:
model:


##  cat /sys/devices/virtual/thermal/thermal_zone*/type 
 imx_thermal_zone

##  cat /sys/devices/virtual/thermal/cooling_device*/type 
 thermal-cpufreq-0
thermal-devfreq-0

##  cat /proc/cmdline 
 console=ttymxc0,115200 root=/dev/mmcblk1p2 rootwait rw

##  cat /proc/cpuinfo 
 processor	: 0
model name	: ARMv7 Processor rev 5 (v7l)
BogoMIPS	: 12.00
Features	: half thumb fastmult vfp edsp neon vfpv3 tls vfpv4 idiva idivt vfpd32 lpae 
CPU implementer	: 0x41
CPU architecture: 7
CPU variant	: 0x0
CPU part	: 0xc07
CPU revision	: 5

Hardware	: Freescale i.MX6 UltraLite (Device Tree)
Revision	: 0000
Serial		: 0000000000000000

##  cat /proc/mounts 
 /dev/root / ext4 rw,relatime,data=ordered 0 0
devtmpfs /dev devtmpfs rw,relatime,size=86120k,nr_inodes=21530,mode=755 0 0
proc /proc proc rw,relatime 0 0
devpts /dev/pts devpts rw,relatime,gid=5,mode=620,ptmxmode=666 0 0
tmpfs /dev/shm tmpfs rw,relatime,mode=777 0 0
tmpfs /tmp tmpfs rw,relatime 0 0
tmpfs /run tmpfs rw,nosuid,nodev,relatime,mode=755 0 0
sysfs /sys sysfs rw,relatime 0 0

##  cat /proc/interrupts 
            CPU0       
 16:      27314       GPC  55 Level     i.MX Timer Tick
 18:          0       GPC  31 Level     2008000.ecspi
 19:          0       GPC  33 Level     2010000.ecspi
 20:       2635       GPC  26 Level     2020000.serial
 21:          0       GPC  98 Level     sai
 22:          0       GPC  50 Level     2034000.asrc
 40:          0       GPC   4 Level     20cc000.snvs:snvs-powerkey
 41:      11232       GPC 120 Level     20b4000.ethernet
 42:          0       GPC 121 Level     20b4000.ethernet
 43:          0       GPC  80 Level     20bc000.wdog
 44:          0       GPC  49 Level     imx_thermal
 49:          0       GPC  19 Level     rtc alarm
 55:          0       GPC   2 Level     sdma
 60:          0       GPC  43 Level     2184000.usb
 61:        348       GPC  42 Level     2184200.usb
 62:          0       GPC 118 Level     2188000.ethernet
 63:          0       GPC 119 Level     2188000.ethernet
 64:          0       GPC  22 Level     mmc0
 65:       5277       GPC  23 Level     mmc1
 66:          1       GPC 100 Level     2198000.adc
 67:        117       GPC  36 Level     21a0000.i2c
 68:        406       GPC  37 Level     21a4000.i2c
 70:          3       GPC   5 Level     21c8000.lcdif
 71:          0       GPC   8 Level     pxp-dmaengine-legacy
 72:          0       GPC  18 Level     pxp-dmaengine-std
 73:          0       GPC  28 Level     21ec000.serial
 74:          0       GPC  17 Level     21fc000.serial
 75:          0       GPC  46 Level     dcp-vmi-irq
 76:          0       GPC  47 Level     dcp-irq
 78:          2       GPC   6 Level     imx-rng
 97:          0  gpio-mxc  18 Edge      SII902x_det
 98:          0  gpio-mxc  19 Edge      2190000.usdhc cd
189:          0  gpio-mxc  14 Edge      User2 Button
208:          0  gpio-mxc   1 Edge      User1 Button
IPI0:          0  CPU wakeup interrupts
IPI1:          0  Timer broadcast interrupts
IPI2:          0  Rescheduling interrupts
IPI3:          0  Function call interrupts
IPI4:          0  CPU stop interrupts
IPI5:      14324  IRQ work interrupts
IPI6:          0  completion interrupts
Err:          0

##  cat /proc/devices 
 Character devices:
  1 mem
  4 /dev/vc/0
  4 tty
  5 /dev/tty
  5 /dev/console
  5 /dev/ptmx
  7 vcs
 10 misc
 13 input
 29 fb
 81 video4linux
 89 i2c
 90 mtd
108 ppp
116 alsa
128 ptm
136 pts
166 ttyACM
180 usb
188 ttyUSB
189 usb_device
207 ttymxc
216 rfcomm
226 drm
246 ttyGS
247 ttyLP
248 watchdog
249 tee
250 iio
251 ptp
252 pps
253 rtc
254 gpiochip

Block devices:
  1 ramdisk
259 blkext
  7 loop
  8 sd
 31 mtdblock
 65 sd
 66 sd
 67 sd
 68 sd
 69 sd
 70 sd
 71 sd
128 sd
129 sd
130 sd
131 sd
132 sd
133 sd
134 sd
135 sd
179 mmc

##  cat /proc/sys/kernel/printk 
 7	7	1	7

##  ls -al /dev/block/by-name/ 
 
