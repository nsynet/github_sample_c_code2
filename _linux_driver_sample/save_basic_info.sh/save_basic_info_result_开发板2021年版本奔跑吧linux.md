[toc]


#  ===================== system information ======================

##  cat /etc/os-release 
```
PRETTY_NAME="Debian GNU/Linux buster/sid"
NAME="Debian GNU/Linux"
ID=debian
HOME_URL="https://www.debian.org/"
SUPPORT_URL="https://www.debian.org/support"
BUG_REPORT_URL="https://bugs.debian.org/" 
```

##  uname -a 
```
Linux benshushu 5.0.0+ #1 SMP Sat Aug 23 23:48:26 CST 2025 aarch64 GNU/Linux 
```

#  =====================CPU information =====================

##  lscpu 
```
Architecture:        aarch64
Byte Order:          Little Endian
CPU(s):              4
On-line CPU(s) list: 0-3
Thread(s) per core:  1
Core(s) per socket:  4
Socket(s):           1
NUMA node(s):        1
Vendor ID:           0x00
Model:               0
Stepping:            0x0
BogoMIPS:            125.00
NUMA node0 CPU(s):   0-3
Flags:               fp asimd evtstrm aes pmull sha1 sha2 crc32 atomics fphp asimdhp cpuid asimdrdm jscvt fcma dcpop sha3 sm3 sm4 asimddp sha512 sve asimdfhm flagm sb paca pacg 
```

#  ===================== KERNEL config =====================

##  zcat /proc/config.gz 
```
 
```

#  =====================内存信息=====================

##  free -h 
```
              total        used        free      shared  buff/cache   available
Mem:          719Mi        58Mi       508Mi       4.0Mi       151Mi       580Mi
Swap:            0B          0B          0B 
```

#  =====================磁盘使用情况=====================

##  df -h 
```
Filesystem      Size  Used Avail Use% Mounted on
/dev/root       2.0G  1.1G  792M  57% /
devtmpfs        326M     0  326M   0% /dev
tmpfs           360M     0  360M   0% /dev/shm
tmpfs           360M  4.8M  355M   2% /run
tmpfs           5.0M     0  5.0M   0% /run/lock
tmpfs           360M     0  360M   0% /sys/fs/cgroup
kmod_mount      982G   35G  898G   4% /mnt
tmpfs            72M     0   72M   0% /run/user/1000 
```

#  =====================网络接口信息=====================
    link/ether 52:54:00:12:34:56 brd ff:ff:ff:ff:ff:ff

##  ifconfig 
```
 
```

#  =====================当前登录用户信息=====================

##  w 
```
 02:52:17 up 15 min,  1 user,  load average: 3.51, 3.37, 2.69
USER     TTY      FROM             LOGIN@   IDLE   JCPU   PCPU WHAT
benshush ttyAMA0  -                02:43   16.00s 35.64s 24.16s -bash 
```

#  =====================显示系统进程信息=====================

##  ps -ef 
```
UID        PID  PPID  C STIME TTY          TIME CMD
root         1     0 15 02:37 ?        00:02:22 /sbin/init noinitrd nokaslr
root         2     0  0 02:37 ?        00:00:00 [kthreadd]
root         3     2  0 02:37 ?        00:00:00 [rcu_gp]
root         4     2  0 02:37 ?        00:00:00 [rcu_par_gp]
root         5     2  0 02:37 ?        00:00:04 [kworker/0:0-mm_percpu_wq]
root         6     2  0 02:37 ?        00:00:00 [kworker/0:0H]
root         7     2  1 02:37 ?        00:00:11 [kworker/u8:0+events_unbound]
root         8     2  0 02:37 ?        00:00:00 [mm_percpu_wq]
root         9     2  2 02:37 ?        00:00:23 [ksoftirqd/0]
root        10     2 10 02:37 ?        00:01:34 [rcu_sched]
root        11     2  0 02:37 ?        00:00:01 [migration/0]
root        12     2  0 02:37 ?        00:00:00 [kworker/0:1-cgroup_destroy]
root        13     2  0 02:37 ?        00:00:00 [cpuhp/0]
root        14     2  0 02:37 ?        00:00:00 [cpuhp/1]
root        15     2  0 02:37 ?        00:00:01 [migration/1]
root        16     2  1 02:37 ?        00:00:10 [ksoftirqd/1]
root        18     2  0 02:37 ?        00:00:00 [kworker/1:0H]
root        19     2  0 02:37 ?        00:00:00 [cpuhp/2]
root        20     2  0 02:37 ?        00:00:00 [migration/2]
root        21     2  1 02:37 ?        00:00:09 [ksoftirqd/2]
root        23     2  0 02:37 ?        00:00:00 [kworker/2:0H-kblockd]
root        24     2  0 02:37 ?        00:00:00 [cpuhp/3]
root        25     2  0 02:37 ?        00:00:00 [migration/3]
root        26     2  1 02:37 ?        00:00:09 [ksoftirqd/3]
root        28     2  0 02:37 ?        00:00:00 [kworker/3:0H]
root        29     2  0 02:37 ?        00:00:00 [kdevtmpfs]
root        30     2  0 02:37 ?        00:00:00 [netns]
root        31     2  0 02:37 ?        00:00:01 [kworker/2:1-cgroup_destroy]
root        32     2  0 02:37 ?        00:00:03 [kworker/1:1-mm_percpu_wq]
root        33     2  0 02:37 ?        00:00:03 [kworker/3:1-memcg_kmem_cache]
root        34     2  0 02:37 ?        00:00:00 [khungtaskd]
root        35     2  0 02:37 ?        00:00:00 [oom_reaper]
root        36     2  0 02:37 ?        00:00:00 [writeback]
root        37     2  0 02:37 ?        00:00:00 [kcompactd0]
root        38     2  0 02:37 ?        00:00:00 [ksmd]
root        39     2  0 02:37 ?        00:00:00 [khugepaged]
root        40     2  0 02:37 ?        00:00:00 [crypto]
root        41     2  0 02:37 ?        00:00:00 [kintegrityd]
root        42     2  0 02:37 ?        00:00:00 [kblockd]
root        43     2  0 02:37 ?        00:00:00 [devfreq_wq]
root        44     2  0 02:37 ?        00:00:00 [watchdogd]
root        45     2  0 02:37 ?        00:00:00 [kswapd0]
root       110     2  0 02:37 ?        00:00:00 [kthrotld]
root       112     2  0 02:37 ?        00:00:00 [irq/38-arm-smmu]
root       113     2  0 02:37 ?        00:00:04 [kworker/1:1H-kblockd]
root       114     2  0 02:37 ?        00:00:00 [vfio-irqfd-clea]
root       115     2  0 02:37 ?        00:00:00 [ion_system_heap]
root       116     2  0 02:37 ?        00:00:00 [ipv6_addrconf]
root       122     2  0 02:37 ?        00:00:01 [kworker/3:2-mm_percpu_wq]
root       123     2  0 02:37 ?        00:00:05 [kworker/2:1H-kblockd]
root       124     2  0 02:37 ?        00:00:03 [kworker/0:1H-kblockd]
root       125     2  0 02:37 ?        00:00:05 [kworker/3:1H-kblockd]
root       126     2  0 02:37 ?        00:00:06 [jbd2/vda-8]
root       127     2  0 02:37 ?        00:00:00 [ext4-rsv-conver]
root       144     1  5 02:38 ?        00:00:47 /lib/systemd/systemd-journald
root       151     2  0 02:38 ?        00:00:02 [kworker/u8:2-flush-254:0]
root       153     2  0 02:38 ?        00:00:00 [kworker/1:2-cgroup_destroy]
root       154     2  0 02:38 ?        00:00:02 [kworker/2:2-mm_percpu_wq]
root       162     1  2 02:38 ?        00:00:22 /lib/systemd/systemd-udevd
root       190     1  0 02:38 ?        00:00:02 /usr/sbin/cron -f
root       194     1  1 02:38 ?        00:00:12 /lib/systemd/systemd-logind
avahi      197     1  0 02:38 ?        00:00:07 avahi-daemon: running [benshushu.local]
message+   199     1  1 02:38 ?        00:00:15 /usr/bin/dbus-daemon --system --address=systemd: --nofork --nopidfile --systemd-activation --syslog-only
root       204     1  0 02:39 ?        00:00:04 /sbin/wpa_supplicant -u -s -O /run/wpa_supplicant
avahi      206   197  0 02:39 ?        00:00:00 avahi-daemon: chroot helper
root       209     1  1 02:39 ?        00:00:11 /usr/sbin/rsyslogd -n -iNONE
root       339     1  0 02:39 tty1     00:00:01 /sbin/agetty -o -p -- \u --noclear tty1 linux
root       416     1  1 02:40 ?        00:00:10 /usr/sbin/dhcpcd
systemd+   548     1  1 02:41 ?        00:00:10 /lib/systemd/systemd-timesyncd
root       560     1  0 02:41 ?        00:00:02 /sbin/dhclient -4 -v -i -pf /run/dhclient.enp0s1.pid -lf /var/lib/dhcp/dhclient.enp0s1.leases -I -df /var/lib/dhcp/dhclient6.enp0s1.leases enp0s1
root      1060     1  0 02:43 ttyAMA0  00:00:03 /bin/login -p --
benshus+  1064     1  1 02:43 ?        00:00:08 /lib/systemd/systemd --user
benshus+  1072  1064  0 02:43 ?        00:00:00 (sd-pam)
root      1118     1  0 02:43 ?        00:00:03 /usr/sbin/sshd -D
benshus+  1120  1060  4 02:43 ttyAMA0  00:00:24 -bash
root      1556     2  1 02:46 ?        00:00:06 [kworker/u8:3-flush-254:0]
root      2425  1120  5 02:51 ttyAMA0  00:00:01 su
root      2440     2  0 02:51 ?        00:00:00 [kworker/u8:1-flush-9p-1]
root      2450  2425  7 02:51 ttyAMA0  00:00:02 bash
root      2505  2450 22 02:52 ttyAMA0  00:00:02 bash
root      2537  2505  0 02:52 ttyAMA0  00:00:02 ps -ef 
```

#  =====================常用命令 =====================

##  lspci 
```
00:00.0 Host bridge: Red Hat, Inc. QEMU PCIe Host bridge
00:01.0 Ethernet controller: Red Hat, Inc Virtio network device
00:02.0 Unclassified device [0002]: Red Hat, Inc Virtio filesystem 
```

##  lsusb 
```
 
```

##  lsipc 
```
RESOURCE DESCRIPTION                                              LIMIT USED  USE%
MSGMNI   Number of message queues                                 32000    0 0.00%
MSGMAX   Max size of message (bytes)                               8192    -     -
MSGMNB   Default max size of queue (bytes)                        16384    -     -
SHMMNI   Shared memory segments                                    4096    0 0.00%
SHMALL   Shared memory pages                       18446744073692774399    0 0.00%
SHMMAX   Max size of shared memory segment (bytes) 18446744073692774399    -     -
SHMMIN   Min size of shared memory segment (bytes)                    1    -     -
SEMMNI   Number of semaphore identifiers                          32000    0 0.00%
SEMMNS   Total number of semaphores                          1024000000    0 0.00%
SEMMSL   Max semaphores per semaphore set.                        32000    -     -
SEMOPM   Max number of operations per semop(2)                      500    -     -
SEMVMX   Semaphore max value                                      32767    -     - 
```

##  lsblk 
```
NAME MAJ:MIN RM SIZE RO TYPE MOUNTPOINT
vda  254:0    0   2G  0 disk / 
```

##  fdisk -l 
```
 
```

##  i2cdetect -l 
```
 
```

##  i2cdetect -y 0 
```
 
```

##  i2cdetect -y 1 
```
 
```

##  i2cdetect -y 2 
```
 
```

##  i2cdetect -y 3 
```
 
```

##  i2cdetect -y 4 
```
 
```

##  i2cdetect -y 5 
```
 
```

##  i2cdetect -y 6 
```
 
```

##  i2cdetect -y 7 
```
 
```

##  blkid 
```
 
```

##  lsmod 
```
Module                  Size  Used by
binfmt_misc            28672  1 
```

##  ls -al /bin 
```
total 12752
drwxr-xr-x  2 root root    4096 Nov 13  2019 .
drwxr-xr-x 21 root root    4096 Aug 23 16:39 ..
-rwxr-xr-x  1 root root 1225120 Apr  4  2019 bash
-rwxr-xr-x  1 root root  767112 Mar 12  2019 btrfs
-rwxr-xr-x  1 root root  409560 Mar 12  2019 btrfs-find-root
-rwxr-xr-x  1 root root  434304 Mar 12  2019 btrfs-image
-rwxr-xr-x  1 root root  413672 Mar 12  2019 btrfs-map-logical
-rwxr-xr-x  1 root root  409568 Mar 12  2019 btrfs-select-super
lrwxrwxrwx  1 root root       5 Mar 12  2019 btrfsck -> btrfs
-rwxr-xr-x  1 root root  417760 Mar 12  2019 btrfstune
-rwxr-xr-x  3 root root   34808 Sep  5  2019 bunzip2
-rwxr-xr-x  1 root root  748168 Apr  1  2019 busybox
-rwxr-xr-x  3 root root   34808 Sep  5  2019 bzcat
lrwxrwxrwx  1 root root       6 Sep  5  2019 bzcmp -> bzdiff
-rwxr-xr-x  1 root root    2227 Sep  5  2019 bzdiff
lrwxrwxrwx  1 root root       6 Sep  5  2019 bzegrep -> bzgrep
-rwxr-xr-x  1 root root    4877 Sep  4  2019 bzexe
lrwxrwxrwx  1 root root       6 Sep  5  2019 bzfgrep -> bzgrep
-rwxr-xr-x  1 root root    3775 Sep  5  2019 bzgrep
-rwxr-xr-x  3 root root   34808 Sep  5  2019 bzip2
-rwxr-xr-x  1 root root   14264 Sep  5  2019 bzip2recover
lrwxrwxrwx  1 root root       6 Sep  5  2019 bzless -> bzmore
-rwxr-xr-x  1 root root    1297 Sep  5  2019 bzmore
-rwxr-xr-x  1 root root   35576 Feb 28  2019 cat
-rwxr-xr-x  1 root root   60256 Feb 28  2019 chgrp
-rwxr-xr-x  1 root root   56096 Feb 28  2019 chmod
-rwxr-xr-x  1 root root   64368 Feb 28  2019 chown
-rwxr-xr-x  1 root root  134632 Feb 28  2019 cp
-rwxr-xr-x  1 root root  141624 Dec  2  2017 cpio
-rwxr-xr-x  1 root root  129536 Jan 17  2019 dash
-rwxr-xr-x  1 root root   97136 Feb 28  2019 date
-rwxr-xr-x  1 root root   76736 Feb 28  2019 dd
-rwxr-xr-x  1 root root   93752 Feb 28  2019 df
-rwxr-xr-x  1 root root  138848 Feb 28  2019 dir
-rwxr-xr-x  1 root root   75984 Jan 10  2019 dmesg
lrwxrwxrwx  1 root root       8 Sep 27  2018 dnsdomainname -> hostname
lrwxrwxrwx  1 root root       8 Sep 27  2018 domainname -> hostname
-rwxr-xr-x  1 root root   31368 Feb 28  2019 echo
-rwxr-xr-x  1 root root      28 Jan  7  2019 egrep
-rwxr-xr-x  1 root root   27256 Feb 28  2019 false
-rwxr-xr-x  1 root root      28 Jan  7  2019 fgrep
-rwxr-xr-x  1 root root   68792 Jan 10  2019 findmnt
-rwxr-xr-x  1 root root    1185 Mar 12  2019 fsck.btrfs
-rwxr-xr-x  1 root root  174304 Jan  7  2019 grep
-rwxr-xr-x  2 root root    2345 Jan  5  2019 gunzip
-rwxr-xr-x  1 root root    6375 Jan  5  2019 gzexe
-rwxr-xr-x  1 root root   89656 Jan  5  2019 gzip
-rwxr-xr-x  1 root root   18440 Sep 27  2018 hostname
-rwxr-xr-x  1 root root  587176 Jan 10  2019 ip
-rwxr-xr-x  1 root root   67600 Mar 15  2019 journalctl
-rwxr-xr-x  1 root root   34744 May 31  2018 kill
-rwxr-xr-x  1 root root  157880 Feb  9  2019 kmod
-rwxr-xr-x  1 root root  154000 May  7  2018 less
-rwxr-xr-x  1 root root   10112 May  7  2018 lessecho
lrwxrwxrwx  1 root root       8 May  7  2018 lessfile -> lesspipe
-rwxr-xr-x  1 root root   19680 May  7  2018 lesskey
-rwxr-xr-x  1 root root    8564 May  7  2018 lesspipe
-rwxr-xr-x  1 root root   64472 Feb 28  2019 ln
-rwxr-xr-x  1 root root   52544 Jul 27  2018 login
-rwxr-xr-x  1 root root   51352 Mar 15  2019 loginctl
-rwxr-xr-x  1 root root  138848 Feb 28  2019 ls
-rwxr-xr-x  1 root root  108552 Jan 10  2019 lsblk
lrwxrwxrwx  1 root root       4 Feb  9  2019 lsmod -> kmod
-rwxr-xr-x  1 root root   76840 Feb 28  2019 mkdir
-rwxr-xr-x  1 root root  434288 Mar 12  2019 mkfs.btrfs
-rwxr-xr-x  1 root root   64480 Feb 28  2019 mknod
-rwxr-xr-x  1 root root   39736 Feb 28  2019 mktemp
-rwxr-xr-x  1 root root   38840 Jan 10  2019 more
-rwsr-xr-x  1 root root   47112 Jan 10  2019 mount
-rwxr-xr-x  1 root root   14344 Jan 10  2019 mountpoint
lrwxrwxrwx  1 root root      20 Apr  8  2019 mt -> /etc/alternatives/mt
-rwxr-xr-x  1 root root   68624 Dec  2  2017 mt-gnu
-rwxr-xr-x  1 root root  138736 Feb 28  2019 mv
-rwxr-xr-x  1 root root  258424 Feb 20  2019 nano
-rwxr-xr-x  1 root root  150704 Sep 24  2018 netstat
-rwxr-xr-x  1 root root   43040 Mar 15  2019 networkctl
lrwxrwxrwx  1 root root       8 Sep 27  2018 nisdomainname -> hostname
lrwxrwxrwx  1 root root      14 Feb 14  2019 pidof -> /sbin/killall5
-rwxr-xr-x  1 root root   73280 Aug  3  2018 ping
lrwxrwxrwx  1 root root       4 Aug  3  2018 ping4 -> ping
lrwxrwxrwx  1 root root       4 Aug  3  2018 ping6 -> ping
-rwxr-xr-x  1 root root  125088 May 31  2018 ps
-rwxr-xr-x  1 root root   35560 Feb 28  2019 pwd
lrwxrwxrwx  1 root root       4 Apr  4  2019 rbash -> bash
-rwxr-xr-x  1 root root   43712 Feb 28  2019 readlink
-rwxr-xr-x  1 root root   68440 Feb 28  2019 rm
-rwxr-xr-x  1 root root   39624 Feb 28  2019 rmdir
lrwxrwxrwx  1 root root       4 Feb 20  2019 rnano -> nano
-rwxr-xr-x  1 root root   19144 Jan 21  2019 run-parts
-rwxr-xr-x  1 root root  114016 Dec 22  2018 sed
lrwxrwxrwx  1 root root       4 Apr  8  2019 sh -> dash
-rwxr-xr-x  1 root root   31384 Feb 28  2019 sleep
-rwxr-xr-x  1 root root  157256 Jan 10  2019 ss
-rwxr-xr-x  1 root root   72480 Feb 28  2019 stty
-rwsr-xr-x  1 root root   59424 Jan 10  2019 su
-rwxr-xr-x  1 root root   31416 Feb 28  2019 sync
-rwxr-xr-x  1 root root  851608 Mar 15  2019 systemctl
lrwxrwxrwx  1 root root      20 Mar 15  2019 systemd -> /lib/systemd/systemd
-rwxr-xr-x  1 root root   14456 Mar 15  2019 systemd-ask-password
-rwxr-xr-x  1 root root   14336 Mar 15  2019 systemd-escape
-rwxr-xr-x  1 root root   92576 Mar 15  2019 systemd-hwdb
-rwxr-xr-x  1 root root   18456 Mar 15  2019 systemd-inhibit
-rwxr-xr-x  1 root root   18536 Mar 15  2019 systemd-machine-id-setup
-rwxr-xr-x  1 root root   14344 Mar 15  2019 systemd-notify
-rwxr-xr-x  1 root root   47456 Mar 15  2019 systemd-sysusers
-rwxr-xr-x  1 root root   76000 Mar 15  2019 systemd-tmpfiles
-rwxr-xr-x  1 root root   30720 Mar 15  2019 systemd-tty-ask-password-agent
-rwxr-xr-x  1 root root  453512 Feb  4  2019 tar
-rwxr-xr-x  1 root root   10560 Jan 21  2019 tempfile
-rwxr-xr-x  1 root root   88968 Feb 28  2019 touch
-rwxr-xr-x  1 root root   27256 Feb 28  2019 true
-rwxr-xr-x  1 root root  654232 Mar 15  2019 udevadm
-rwsr-xr-x  1 root root   30728 Jan 10  2019 umount
-rwxr-xr-x  1 root root   31384 Feb 28  2019 uname
-rwxr-xr-x  2 root root    2345 Jan  5  2019 uncompress
-rwxr-xr-x  1 root root  138848 Feb 28  2019 vdir
-rwxr-xr-x  1 root root   34824 Jan 10  2019 wdctl
-rwxr-xr-x  1 root root     946 Jan 21  2019 which
lrwxrwxrwx  1 root root       8 Sep 27  2018 ypdomainname -> hostname
-rwxr-xr-x  1 root root    1983 Jan  5  2019 zcat
-rwxr-xr-x  1 root root    1677 Jan  5  2019 zcmp
-rwxr-xr-x  1 root root    5879 Jan  5  2019 zdiff
-rwxr-xr-x  1 root root      29 Jan  5  2019 zegrep
-rwxr-xr-x  1 root root      29 Jan  5  2019 zfgrep
-rwxr-xr-x  1 root root    2080 Jan  5  2019 zforce
-rwxr-xr-x  1 root root    7584 Jan  5  2019 zgrep
-rwxr-xr-x  1 root root    2205 Jan  5  2019 zless
-rwxr-xr-x  1 root root    1841 Jan  5  2019 zmore
-rwxr-xr-x  1 root root    4552 Jan  5  2019 znew 
```

##  busybox 
```
BusyBox v1.30.1 (Debian 1:1.30.1-4) multi-call binary.
BusyBox is copyrighted by many authors between 1998-2015.
Licensed under GPLv2. See source distribution for detailed
copyright notices.

Usage: busybox [function [arguments]...]
   or: busybox --list[-full]
   or: busybox --show SCRIPT
   or: busybox --install [-s] [DIR]
   or: function [arguments]...

	BusyBox is a multi-call binary that combines many common Unix
	utilities into a single executable.  Most people will create a
	link to busybox for each function they wish to use and BusyBox
	will act like whatever it was invoked as.

Currently defined functions:
	[, [[, acpid, adjtimex, ar, arch, arp, arping, ash, awk, basename, bc,
	blkdiscard, blockdev, brctl, bunzip2, bzcat, bzip2, cal, cat, chgrp,
	chmod, chown, chroot, chvt, clear, cmp, cp, cpio, cttyhack, cut, date,
	dc, dd, deallocvt, depmod, devmem, df, diff, dirname, dmesg,
	dnsdomainname, dos2unix, du, dumpkmap, dumpleases, echo, egrep, env,
	expand, expr, factor, fallocate, false, fatattr, fgrep, find, fold,
	free, freeramdisk, fsfreeze, fstrim, ftpget, ftpput, getopt, getty,
	grep, groups, gunzip, gzip, halt, head, hexdump, hostid, hostname,
	httpd, hwclock, i2cdetect, i2cdump, i2cget, i2cset, id, ifconfig,
	ifdown, ifup, init, insmod, ionice, ip, ipcalc, ipneigh, kill, killall,
	klogd, last, less, link, linux32, linux64, linuxrc, ln, loadfont,
	loadkmap, logger, login, logname, logread, losetup, ls, lsmod, lsscsi,
	lzcat, lzma, lzop, md5sum, mdev, microcom, mkdir, mkdosfs, mke2fs,
	mkfifo, mknod, mkpasswd, mkswap, mktemp, modinfo, modprobe, more,
	mount, mt, mv, nameif, nc, netstat, nl, nologin, nproc, nsenter,
	nslookup, nuke, od, openvt, partprobe, paste, patch, pidof, ping,
	ping6, pivot_root, poweroff, printf, ps, pwd, rdate, readlink,
	realpath, reboot, renice, reset, resume, rev, rm, rmdir, rmmod, route,
	rpm, rpm2cpio, run-init, run-parts, sed, seq, setkeycodes, setpriv,
	setsid, sh, sha1sum, sha256sum, sha512sum, shred, shuf, sleep, sort,
	ssl_client, start-stop-daemon, stat, strings, stty, svc, svok, swapoff,
	swapon, switch_root, sync, sysctl, syslogd, tac, tail, tar, taskset,
	tee, telnet, test, tftp, time, timeout, top, touch, tr, traceroute,
	traceroute6, true, truncate, tty, ubirename, udhcpc, udhcpd, uevent,
	umount, uname, uncompress, unexpand, uniq, unix2dos, unlink, unlzma,
	unshare, unxz, unzip, uptime, usleep, uudecode, uuencode, vconfig, vi,
	w, watch, watchdog, wc, wget, which, who, whoami, xargs, xxd, xz,
	xzcat, yes, zcat 
```

#  ===================== /sys/ 文件系统 =====================

##  ls -al /sys/devices/platform/ 
```
total 0
drwxr-xr-x 49 root root    0 Nov  2 02:49 .
drwxr-xr-x 11 root root    0 Nov  2 02:49 ..
drwxr-xr-x  3 root root    0 Nov  2 02:49 0.flash
drwxr-xr-x  4 root root    0 Nov  2 02:49 4010000000.pcie
drwxr-xr-x  4 root root    0 Nov  2 02:49 9000000.pl011
drwxr-xr-x  4 root root    0 Nov  2 02:49 9010000.pl031
drwxr-xr-x  3 root root    0 Nov  2 02:49 9020000.fw-cfg
drwxr-xr-x  5 root root    0 Nov  2 02:49 9030000.pl061
drwxr-xr-x  4 root root    0 Nov  2 02:49 9050000.smmuv3
drwxr-xr-x  3 root root    0 Nov  2 02:49 a000000.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a000200.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a000400.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a000600.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a000800.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a000a00.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a000c00.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a000e00.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a001000.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a001200.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a001400.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a001600.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a001800.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a001a00.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a001c00.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a001e00.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a002000.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a002200.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a002400.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a002600.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a002800.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a002a00.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a002c00.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a002e00.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a003000.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a003200.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a003400.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a003600.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a003800.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a003a00.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 a003c00.virtio_mmio
drwxr-xr-x  4 root root    0 Nov  2 02:49 a003e00.virtio_mmio
drwxr-xr-x  3 root root    0 Nov  2 02:49 alarmtimer
drwxr-xr-x  3 root root    0 Nov  2 02:49 gpio-keys
drwxr-xr-x  3 root root    0 Nov  2 02:49 platform@c000000
drwxr-xr-x  3 root root    0 Nov  2 02:49 pmu
drwxr-xr-x  2 root root    0 Nov  2 02:49 power
drwxr-xr-x  3 root root    0 Nov  2 02:49 psci
drwxr-xr-x  4 root root    0 Nov  2 02:49 serial8250
drwxr-xr-x  3 root root    0 Nov  2 02:49 timer
-rw-r--r--  1 root root 4096 Nov  2 02:49 uevent 
```

##  cat /sys/devices/system/cpu/cpu*/cpufreq/cpuinfo_cur_freq 
```
 
```

##  ls -al /sys/kernel/debug 
```
total 0
drwx------ 24 root root 0 Jan  1  1970 .
drwxr-xr-x 11 root root 0 Nov  2 02:37 ..
drwxr-xr-x 12 root root 0 Jan  1  1970 bdi
drwxr-xr-x  3 root root 0 Jan  1  1970 binder
drwxr-xr-x 11 root root 0 Jan  1  1970 block
--w-------  1 root root 0 Jan  1  1970 clear_warn_once
drwxr-xr-x  3 root root 0 Jan  1  1970 clk
-rw-r--r--  1 root root 0 Jan  1  1970 debug_enabled
drwxr-xr-x  2 root root 0 Jan  1  1970 device_component
-r--r--r--  1 root root 0 Jan  1  1970 devices_deferred
drwxr-xr-x  2 root root 0 Jan  1  1970 dma_buf
drwxr-xr-x  2 root root 0 Jan  1  1970 dynamic_debug
drwxr-xr-x  2 root root 0 Jan  1  1970 extfrag
drwxr-xr-x  2 root root 0 Jan  1  1970 f2fs
-rw-r--r--  1 root root 0 Jan  1  1970 fault_around_bytes
drwxr-xr-x  2 root root 0 Jan  1  1970 frontswap
-r--r--r--  1 root root 0 Jan  1  1970 gpio
drwxr-xr-x  5 root root 0 Jan  1  1970 ion
-r--------  1 root root 0 Jan  1  1970 kernel_page_tables
drwxr-xr-x  2 root root 0 Jan  1  1970 kprobes
drwxr-xr-x  2 root root 0 Jan  1  1970 memblock
drwxr-xr-x  2 root root 0 Jan  1  1970 opp
drwxr-xr-x  2 root root 0 Jan  1  1970 pm_genpd
drwxr-xr-x  2 root root 0 Jan  1  1970 pm_qos
drwxr-xr-x  2 root root 0 Jan  1  1970 ras
drwxr-xr-x  2 root root 0 Jan  1  1970 regmap
-rw-r--r--  1 root root 0 Jan  1  1970 sched_debug
-rw-r--r--  1 root root 0 Jan  1  1970 sched_features
-r--r--r--  1 root root 0 Jan  1  1970 sleep_time
--w-------  1 root root 0 Jan  1  1970 split_huge_pages
-r--r--r--  1 root root 0 Jan  1  1970 suspend_stats
drwxr-xr-x  2 root root 0 Jan  1  1970 sync
dr-xr-xr-x  3 root root 0 Jan  1  1970 tracing
drwxr-xr-x  2 root root 0 Jan  1  1970 virtio-ports
-r--r--r--  1 root root 0 Jan  1  1970 wakeup_sources
drwxr-xr-x  2 root root 0 Jan  1  1970 zswap 
```

##  cat /sys/kernel/debug/gpio 
```
gpiochip0: GPIOs 504-511, parent: amba/9030000.pl061, 9030000.pl061: 
```

##  ===================== 打印 /sys/class/video4linux/video* =====================

##  ls -al /sys/class/video4linux 
```
 
```
/sys/class/video4linux/video*
dev:
name:
index:
link_name:


##  ===================== 打印 /sys/class/video4linux/v4l-subdev* =====================
/sys/class/video4linux/v4l-subdev*
dev:
name:
index:
link_name:


##  ===================== 打印 /sys/bus/media/devices/media* =====================

##  ls -al /sys/bus/media/ 
```
 
```

##  ls -al /sys/bus/media/devices 
```
 
```
/sys/bus/media/devices/media*
dev:
model:


##  ===================== 打印 /sys/ 的thermal相关 =====================

##  cat /sys/devices/virtual/thermal/thermal_zone*/type 
```
 
```

##  cat /sys/devices/virtual/thermal/cooling_device*/type 
```
 
```

#  ===================== /proc/ fs =====================

##  cat /proc/cmdline 
```
noinitrd nokaslr loglevel=8 sched_debug root=/dev/vda rootfstype=ext4 rw crashkernel=256M vfio.dyndbg=+pflmt irq_gic_v3_its.dyndbg=+pflmt iommu.dyndbg=+pflmt irqdomain.dyndbg=+pflmt 
```

##  cat /proc/cpuinfo 
```
processor	: 0
BogoMIPS	: 125.00
Features	: fp asimd evtstrm aes pmull sha1 sha2 crc32 atomics fphp asimdhp cpuid asimdrdm jscvt fcma dcpop sha3 sm3 sm4 asimddp sha512 sve asimdfhm flagm sb paca pacg
CPU implementer	: 0x00
CPU architecture: 8
CPU variant	: 0x0
CPU part	: 0x051
CPU revision	: 0

processor	: 1
BogoMIPS	: 125.00
Features	: fp asimd evtstrm aes pmull sha1 sha2 crc32 atomics fphp asimdhp cpuid asimdrdm jscvt fcma dcpop sha3 sm3 sm4 asimddp sha512 sve asimdfhm flagm sb paca pacg
CPU implementer	: 0x00
CPU architecture: 8
CPU variant	: 0x0
CPU part	: 0x051
CPU revision	: 0

processor	: 2
BogoMIPS	: 125.00
Features	: fp asimd evtstrm aes pmull sha1 sha2 crc32 atomics fphp asimdhp cpuid asimdrdm jscvt fcma dcpop sha3 sm3 sm4 asimddp sha512 sve asimdfhm flagm sb paca pacg
CPU implementer	: 0x00
CPU architecture: 8
CPU variant	: 0x0
CPU part	: 0x051
CPU revision	: 0

processor	: 3
BogoMIPS	: 125.00
Features	: fp asimd evtstrm aes pmull sha1 sha2 crc32 atomics fphp asimdhp cpuid asimdrdm jscvt fcma dcpop sha3 sm3 sm4 asimddp sha512 sve asimdfhm flagm sb paca pacg
CPU implementer	: 0x00
CPU architecture: 8
CPU variant	: 0x0
CPU part	: 0x051
CPU revision	: 0 
```

##  cat /proc/meminfo 
```
MemTotal:         736564 kB
MemFree:          520932 kB
MemAvailable:     594160 kB
Buffers:           28564 kB
Cached:            95912 kB
SwapCached:            0 kB
Active:            73664 kB
Inactive:          67984 kB
Active(anon):      17328 kB
Inactive(anon):     4708 kB
Active(file):      56336 kB
Inactive(file):    63276 kB
Unevictable:           0 kB
Mlocked:               0 kB
SwapTotal:             0 kB
SwapFree:              0 kB
Dirty:                16 kB
Writeback:             0 kB
AnonPages:         17204 kB
Mapped:            19788 kB
Shmem:              4868 kB
KReclaimable:      31132 kB
Slab:              53256 kB
SReclaimable:      31132 kB
SUnreclaim:        22124 kB
KernelStack:        2880 kB
PageTables:          928 kB
NFS_Unstable:          0 kB
Bounce:                0 kB
WritebackTmp:          0 kB
CommitLimit:      368280 kB
Committed_AS:      93252 kB
VmallocTotal:   135290159040 kB
VmallocUsed:           0 kB
VmallocChunk:          0 kB
Percpu:              960 kB
HardwareCorrupted:     0 kB
AnonHugePages:         0 kB
ShmemHugePages:        0 kB
ShmemPmdMapped:        0 kB
CmaTotal:          65536 kB
CmaFree:           65244 kB
HugePages_Total:       0
HugePages_Free:        0
HugePages_Rsvd:        0
HugePages_Surp:        0
Hugepagesize:       2048 kB
Hugetlb:               0 kB 
```

##  cat /proc/driver 
```
 
```

##  cat /proc/iomem 
```
09000000-09000fff : pl011@9000000
  09000000-09000fff : pl011@9000000
09010000-09010fff : pl031@9010000
  09010000-09010fff : rtc-pl031
09030000-09030fff : pl061@9030000
  09030000-09030fff : pl061@9030000
09050000-0906ffff : smmuv3@9050000
0a003e00-0a003fff : a003e00.virtio_mmio
10000000-3efeffff : pcie@10000000
  10000000-1003ffff : 0000:00:01.0
40000000-7fffffff : System RAM
  40080000-41bfffff : Kernel code
  41c00000-4208ffff : reserved
  42090000-42240fff : Kernel data
  48000000-480fffff : reserved
  6ac00000-6fbfffff : reserved
  6fd77000-6fdeefff : reserved
  6fdf1000-6fdf2fff : reserved
  6fdf3000-6fdf7fff : reserved
  6fdf8000-6fdfffff : reserved
  6fe00000-7fdfffff : Crash kernel
  7fe00000-7fe00fff : reserved
  7fe01000-7fe03fff : reserved
  7fe04000-7fffffff : reserved
4010000000-401fffffff : PCI ECAM
8000000000-ffffffffff : pcie@10000000
  8000000000-8000003fff : 0000:00:01.0
    8000000000-8000003fff : virtio-pci-modern
  8000004000-8000007fff : 0000:00:02.0
    8000004000-8000007fff : virtio-pci-modern 
```

##  cat /proc/mounts 
```
/dev/root / ext4 rw,relatime 0 0
sysfs /sys sysfs rw,nosuid,nodev,noexec,relatime 0 0
proc /proc proc rw,nosuid,nodev,noexec,relatime 0 0
devtmpfs /dev devtmpfs rw,nosuid,size=333176k,nr_inodes=83294,mode=755 0 0
tmpfs /dev/shm tmpfs rw,nosuid,nodev 0 0
devpts /dev/pts devpts rw,nosuid,noexec,relatime,gid=5,mode=620,ptmxmode=000 0 0
tmpfs /run tmpfs rw,nosuid,nodev,mode=755 0 0
tmpfs /run/lock tmpfs rw,nosuid,nodev,noexec,relatime,size=5120k 0 0
tmpfs /sys/fs/cgroup tmpfs ro,nosuid,nodev,noexec,mode=755 0 0
cgroup2 /sys/fs/cgroup/unified cgroup2 rw,nosuid,nodev,noexec,relatime,nsdelegate 0 0
cgroup /sys/fs/cgroup/systemd cgroup rw,nosuid,nodev,noexec,relatime,xattr,name=systemd 0 0
pstore /sys/fs/pstore pstore rw,nosuid,nodev,noexec,relatime 0 0
bpf /sys/fs/bpf bpf rw,nosuid,nodev,noexec,relatime,mode=700 0 0
cgroup /sys/fs/cgroup/cpu,cpuacct cgroup rw,nosuid,nodev,noexec,relatime,cpu,cpuacct 0 0
cgroup /sys/fs/cgroup/memory cgroup rw,nosuid,nodev,noexec,relatime,memory 0 0
cgroup /sys/fs/cgroup/blkio cgroup rw,nosuid,nodev,noexec,relatime,blkio 0 0
cgroup /sys/fs/cgroup/perf_event cgroup rw,nosuid,nodev,noexec,relatime,perf_event 0 0
cgroup /sys/fs/cgroup/devices cgroup rw,nosuid,nodev,noexec,relatime,devices 0 0
cgroup /sys/fs/cgroup/freezer cgroup rw,nosuid,nodev,noexec,relatime,freezer 0 0
cgroup /sys/fs/cgroup/pids cgroup rw,nosuid,nodev,noexec,relatime,pids 0 0
cgroup /sys/fs/cgroup/cpuset cgroup rw,nosuid,nodev,noexec,relatime,cpuset 0 0
systemd-1 /proc/sys/fs/binfmt_misc autofs rw,relatime,fd=38,pgrp=1,timeout=0,minproto=5,maxproto=5,direct,pipe_ino=10457 0 0
hugetlbfs /dev/hugepages hugetlbfs rw,relatime,pagesize=2M 0 0
debugfs /sys/kernel/debug debugfs rw,relatime 0 0
kmod_mount /mnt 9p rw,sync,dirsync,relatime,access=client,trans=virtio 0 0
tmpfs /run/user/1000 tmpfs rw,nosuid,nodev,relatime,size=73656k,mode=700,uid=1000,gid=1000 0 0
binfmt_misc /proc/sys/fs/binfmt_misc binfmt_misc rw,relatime 0 0 
```

##  cat /proc/interrupts 
```
           CPU0       CPU1       CPU2       CPU3       
  3:     107958     119871     118268     121461     GICv3  27 Level     arch_timer
 36:       7589          0          0          0     GICv3  79 Edge      virtio0
 38:          0          0          0          0     GICv3 106 Edge      arm-smmu-v3-evtq
 41:          0          0          0          0     GICv3 109 Edge      arm-smmu-v3-gerror
 42:          0          0          0          0     GICv3  34 Level     rtc-pl031
 43:        348          0          0          0     GICv3  33 Level     uart-pl011
 44:          0          0          0          0     GICv3  23 Level     arm-pmu
 45:         32          0          0          0     GICv3  36 Level     virtio1
 46:       3357          0          0          0     GICv3  37 Level     virtio2
IPI0:     32319      22878      20219      16681       Rescheduling interrupts
IPI1:       274        325        267        264       Function call interrupts
IPI2:         0          0          0          0       CPU stop interrupts
IPI3:         0          0          0          0       CPU stop (for crash dump) interrupts
IPI4:         0          0          0          0       Timer broadcast interrupts
IPI5:         0          0          0          0       IRQ work interrupts
IPI6:         0          0          0          0       CPU wake-up interrupts
Err:          0 
```

##  cat /proc/devices 
```
Character devices:
  1 mem
  4 /dev/vc/0
  4 tty
  4 ttyS
  5 /dev/tty
  5 /dev/console
  5 /dev/ptmx
  5 ttyprintk
  7 vcs
 10 misc
 13 input
 29 fb
128 ptm
136 pts
204 ttyAMA
248 binder
249 vfio
250 bsg
251 watchdog
252 rtc
253 dax
254 gpiochip

Block devices:
  7 loop
254 virtblk
259 blkext 
```

##  cat /proc/sys/kernel/printk 
```
8	4	1	7 
```

#  ===================== other =====================

##  ls -al /dev/ 
```
total 4
drwxr-xr-x 10 root      root        2940 Nov  2 02:39 .
drwxr-xr-x 21 root      root        4096 Aug 23 16:39 ..
crw-r--r--  1 root      root     10, 235 Nov  2 02:39 autofs
crw-------  1 root      root     10,  60 Nov  2 02:39 binder
drwxr-xr-x  2 root      root         220 Nov  2 02:39 block
drwxr-xr-x  2 root      root        2440 Nov  2 02:41 char
crw-------  1 root      root      5,   1 Nov  2 02:41 console
lrwxrwxrwx  1 root      root          11 Nov  2 02:37 core -> /proc/kcore
crw-------  1 root      root     10,  57 Nov  2 02:39 cpu_dma_latency
crw-------  1 root      root     10, 203 Nov  2 02:38 cuse
drwxr-xr-x  4 root      root          80 Nov  2 02:39 disk
lrwxrwxrwx  1 root      root          13 Nov  2 02:37 fd -> /proc/self/fd
crw-rw-rw-  1 root      root      1,   7 Nov  2 02:39 full
crw-rw-rw-  1 root      root     10, 229 Nov  2 02:38 fuse
crw-------  1 root      root    254,   0 Nov  2 02:38 gpiochip0
drwxr-xr-x  2 root      root           0 Nov  2 02:38 hugepages
crw-------  1 root      root     10,  59 Nov  2 02:39 hwbinder
lrwxrwxrwx  1 root      root          12 Nov  2 02:38 initctl -> /run/initctl
drwxr-xr-x  2 root      root          60 Jan  1  1970 input
crw-------  1 root      root     10,  62 Nov  2 02:39 ion
crw-r--r--  1 root      root      1,  11 Nov  2 02:39 kmsg
lrwxrwxrwx  1 root      root          28 Nov  2 02:38 log -> /run/systemd/journal/dev-log
crw-rw----  1 root      disk     10, 237 Nov  2 02:39 loop-control
brw-rw----  1 root      disk      7,   0 Nov  2 02:39 loop0
brw-rw----  1 root      disk      7,   1 Nov  2 02:39 loop1
brw-rw----  1 root      disk      7,   2 Nov  2 02:39 loop2
brw-rw----  1 root      disk      7,   3 Nov  2 02:39 loop3
brw-rw----  1 root      disk      7,   4 Nov  2 02:39 loop4
brw-rw----  1 root      disk      7,   5 Nov  2 02:39 loop5
brw-rw----  1 root      disk      7,   6 Nov  2 02:39 loop6
brw-rw----  1 root      disk      7,   7 Nov  2 02:39 loop7
crw-r-----  1 root      kmem      1,   1 Nov  2 02:39 mem
crw-------  1 root      root     10,  54 Nov  2 02:39 memory_bandwidth
crw-------  1 root      root     10,  56 Nov  2 02:39 network_latency
crw-------  1 root      root     10,  55 Nov  2 02:39 network_throughput
crw-rw-rw-  1 root      root      1,   3 Nov  2 02:39 null
crw-r-----  1 root      kmem      1,   4 Nov  2 02:39 port
crw-------  1 root      root     10,   1 Nov  2 02:39 psaux
crw-rw-rw-  1 root      tty       5,   2 Nov  2 02:40 ptmx
drwxr-xr-x  2 root      root           0 Nov  2 02:37 pts
crw-rw-rw-  1 root      root      1,   8 Nov  2 02:39 random
lrwxrwxrwx  1 root      root           4 Nov  2 02:38 rtc -> rtc0
crw-------  1 root      root    252,   0 Nov  2 02:38 rtc0
drwxrwxrwt  2 root      root          40 Nov  2 02:37 shm
crw-------  1 root      root     10, 231 Nov  2 02:39 snapshot
lrwxrwxrwx  1 root      root          15 Nov  2 02:37 stderr -> /proc/self/fd/2
lrwxrwxrwx  1 root      root          15 Nov  2 02:37 stdin -> /proc/self/fd/0
lrwxrwxrwx  1 root      root          15 Nov  2 02:37 stdout -> /proc/self/fd/1
crw-rw-rw-  1 root      tty       5,   0 Nov  2 02:40 tty
crw--w----  1 root      tty       4,   0 Nov  2 02:40 tty0
crw--w----  1 root      tty       4,   1 Nov  2 02:40 tty1
crw--w----  1 root      tty       4,  10 Nov  2 02:40 tty10
crw--w----  1 root      tty       4,  11 Nov  2 02:40 tty11
crw--w----  1 root      tty       4,  12 Nov  2 02:40 tty12
crw--w----  1 root      tty       4,  13 Nov  2 02:40 tty13
crw--w----  1 root      tty       4,  14 Nov  2 02:40 tty14
crw--w----  1 root      tty       4,  15 Nov  2 02:40 tty15
crw--w----  1 root      tty       4,  16 Nov  2 02:40 tty16
crw--w----  1 root      tty       4,  17 Nov  2 02:40 tty17
crw--w----  1 root      tty       4,  18 Nov  2 02:40 tty18
crw--w----  1 root      tty       4,  19 Nov  2 02:40 tty19
crw--w----  1 root      tty       4,   2 Nov  2 02:40 tty2
crw--w----  1 root      tty       4,  20 Nov  2 02:40 tty20
crw--w----  1 root      tty       4,  21 Nov  2 02:40 tty21
crw--w----  1 root      tty       4,  22 Nov  2 02:40 tty22
crw--w----  1 root      tty       4,  23 Nov  2 02:40 tty23
crw--w----  1 root      tty       4,  24 Nov  2 02:40 tty24
crw--w----  1 root      tty       4,  25 Nov  2 02:40 tty25
crw--w----  1 root      tty       4,  26 Nov  2 02:40 tty26
crw--w----  1 root      tty       4,  27 Nov  2 02:40 tty27
crw--w----  1 root      tty       4,  28 Nov  2 02:40 tty28
crw--w----  1 root      tty       4,  29 Nov  2 02:40 tty29
crw--w----  1 root      tty       4,   3 Nov  2 02:40 tty3
crw--w----  1 root      tty       4,  30 Nov  2 02:40 tty30
crw--w----  1 root      tty       4,  31 Nov  2 02:40 tty31
crw--w----  1 root      tty       4,  32 Nov  2 02:40 tty32
crw--w----  1 root      tty       4,  33 Nov  2 02:40 tty33
crw--w----  1 root      tty       4,  34 Nov  2 02:40 tty34
crw--w----  1 root      tty       4,  35 Nov  2 02:40 tty35
crw--w----  1 root      tty       4,  36 Nov  2 02:40 tty36
crw--w----  1 root      tty       4,  37 Nov  2 02:40 tty37
crw--w----  1 root      tty       4,  38 Nov  2 02:40 tty38
crw--w----  1 root      tty       4,  39 Nov  2 02:40 tty39
crw--w----  1 root      tty       4,   4 Nov  2 02:40 tty4
crw--w----  1 root      tty       4,  40 Nov  2 02:40 tty40
crw--w----  1 root      tty       4,  41 Nov  2 02:40 tty41
crw--w----  1 root      tty       4,  42 Nov  2 02:40 tty42
crw--w----  1 root      tty       4,  43 Nov  2 02:40 tty43
crw--w----  1 root      tty       4,  44 Nov  2 02:40 tty44
crw--w----  1 root      tty       4,  45 Nov  2 02:40 tty45
crw--w----  1 root      tty       4,  46 Nov  2 02:40 tty46
crw--w----  1 root      tty       4,  47 Nov  2 02:40 tty47
crw--w----  1 root      tty       4,  48 Nov  2 02:40 tty48
crw--w----  1 root      tty       4,  49 Nov  2 02:40 tty49
crw--w----  1 root      tty       4,   5 Nov  2 02:40 tty5
crw--w----  1 root      tty       4,  50 Nov  2 02:40 tty50
crw--w----  1 root      tty       4,  51 Nov  2 02:40 tty51
crw--w----  1 root      tty       4,  52 Nov  2 02:40 tty52
crw--w----  1 root      tty       4,  53 Nov  2 02:40 tty53
crw--w----  1 root      tty       4,  54 Nov  2 02:40 tty54
crw--w----  1 root      tty       4,  55 Nov  2 02:40 tty55
crw--w----  1 root      tty       4,  56 Nov  2 02:40 tty56
crw--w----  1 root      tty       4,  57 Nov  2 02:40 tty57
crw--w----  1 root      tty       4,  58 Nov  2 02:40 tty58
crw--w----  1 root      tty       4,  59 Nov  2 02:40 tty59
crw--w----  1 root      tty       4,   6 Nov  2 02:40 tty6
crw--w----  1 root      tty       4,  60 Nov  2 02:40 tty60
crw--w----  1 root      tty       4,  61 Nov  2 02:40 tty61
crw--w----  1 root      tty       4,  62 Nov  2 02:40 tty62
crw--w----  1 root      tty       4,  63 Nov  2 02:40 tty63
crw--w----  1 root      tty       4,   7 Nov  2 02:40 tty7
crw--w----  1 root      tty       4,   8 Nov  2 02:40 tty8
crw--w----  1 root      tty       4,   9 Nov  2 02:40 tty9
crw-------  1 benshushu tty     204,  64 Nov  2 02:52 ttyAMA0
crw-rw----  1 root      dialout   4,  64 Nov  2 02:39 ttyS0
crw-rw----  1 root      dialout   4,  65 Nov  2 02:39 ttyS1
crw-rw----  1 root      dialout   4,  66 Nov  2 02:39 ttyS2
crw-rw----  1 root      dialout   4,  67 Nov  2 02:39 ttyS3
crw-------  1 root      root      5,   3 Nov  2 02:40 ttyprintk
crw-------  1 root      root     10,  61 Nov  2 02:39 udmabuf
crw-rw-rw-  1 root      root      1,   9 Nov  2 02:39 urandom
crw-rw----  1 root      tty       7,   0 Nov  2 02:40 vcs
crw-rw----  1 root      tty       7,   1 Nov  2 02:40 vcs1
crw-rw----  1 root      tty       7,   2 Nov  2 02:41 vcs2
crw-rw----  1 root      tty       7,   3 Nov  2 02:41 vcs3
crw-rw----  1 root      tty       7,   4 Nov  2 02:41 vcs4
crw-rw----  1 root      tty       7,   5 Nov  2 02:41 vcs5
crw-rw----  1 root      tty       7,   6 Nov  2 02:41 vcs6
crw-rw----  1 root      tty       7, 128 Nov  2 02:40 vcsa
crw-rw----  1 root      tty       7, 129 Nov  2 02:40 vcsa1
crw-rw----  1 root      tty       7, 130 Nov  2 02:41 vcsa2
crw-rw----  1 root      tty       7, 131 Nov  2 02:41 vcsa3
crw-rw----  1 root      tty       7, 132 Nov  2 02:41 vcsa4
crw-rw----  1 root      tty       7, 133 Nov  2 02:41 vcsa5
crw-rw----  1 root      tty       7, 134 Nov  2 02:41 vcsa6
crw-rw----  1 root      tty       7,  64 Nov  2 02:40 vcsu
crw-rw----  1 root      tty       7,  65 Nov  2 02:40 vcsu1
crw-rw----  1 root      tty       7,  66 Nov  2 02:41 vcsu2
crw-rw----  1 root      tty       7,  67 Nov  2 02:41 vcsu3
crw-rw----  1 root      tty       7,  68 Nov  2 02:41 vcsu4
crw-rw----  1 root      tty       7,  69 Nov  2 02:41 vcsu5
crw-rw----  1 root      tty       7,  70 Nov  2 02:41 vcsu6
brw-rw----  1 root      disk    254,   0 Nov  2 02:39 vda
drwxr-xr-x  2 root      root          60 Jan  1  1970 vfio
crw-------  1 root      root     10,  63 Nov  2 02:39 vga_arbiter
crw-------  1 root      root     10,  58 Nov  2 02:39 vndbinder
crw-rw-rw-  1 root      root      1,   5 Nov  2 02:39 zero 
```

##  ls -al /dev/block/by-name/ 
```
 
```

##  find / -iname "\*camera\*"  2\>/dev/null \|xargs ls -al 
```
-rw-rw-r-- 1 benshushu benshushu  1556 Aug 23 14:56 /usr/src/linux/include/linux/platform_data/media/camera-mx2.h
-rw-rw-r-- 1 benshushu benshushu  1677 Aug 23 14:56 /usr/src/linux/include/linux/platform_data/media/camera-mx3.h
-rw-rw-r-- 1 benshushu benshushu  1525 Aug 23 14:56 /usr/src/linux/include/linux/platform_data/media/camera-pxa.h
-rw-rw-r-- 1 benshushu benshushu   756 Aug 23 14:56 /usr/src/linux/include/linux/platform_data/media/mmp-camera.h
-rw-rw-r-- 1 benshushu benshushu   880 Aug 23 14:56 /usr/src/linux/include/linux/platform_data/media/omap1_camera.h
-rw-rw-r-- 1 benshushu benshushu  1974 Aug 23 14:56 /usr/src/linux/include/linux/platform_data/media/soc_camera_platform.h
-rw-rw-r-- 1 benshushu benshushu 13300 Aug 23 14:56 /usr/src/linux/include/media/soc_camera.h 
```

#  ===================== manual add commnd =====================
