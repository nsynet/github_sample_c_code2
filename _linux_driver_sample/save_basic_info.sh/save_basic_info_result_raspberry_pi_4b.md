
 #  =====================系统信息======================

##  主机名: 
 raspberrypi

##  操作系统版本: 
 PRETTY_NAME="Raspbian GNU/Linux 12 (bookworm)"
NAME="Raspbian GNU/Linux"
VERSION_ID="12"
VERSION="12 (bookworm)"
VERSION_CODENAME=bookworm
ID=raspbian
ID_LIKE=debian
HOME_URL="http://www.raspbian.org/"
SUPPORT_URL="http://www.raspbian.org/RaspbianForums"
BUG_REPORT_URL="http://www.raspbian.org/RaspbianBugs"

##  内核版本: 
 6.6.51+rpt-rpi-v8


 #  =====================CPU 信息=====================

##  CPU 型号: 
 Cortex-A72

##  CPU 核心数: 
 4

##  CPU 逻辑处理器数: 
 0

 #  =====================内存信息=====================
总内存: 3.7Gi
可用内存: 3.3Gi
已用内存: 459Mi

 #  =====================磁盘使用情况=====================

##  df -h 
 Filesystem      Size  Used Avail Use% Mounted on
udev            1.6G     0  1.6G   0% /dev
tmpfs           380M  1.4M  378M   1% /run
/dev/mmcblk0p2   14G  7.0G  6.0G  54% /
tmpfs           1.9G  396K  1.9G   1% /dev/shm
tmpfs           5.0M   16K  5.0M   1% /run/lock
/dev/mmcblk0p1  510M  117M  394M  23% /boot/firmware
tmpfs           380M   56K  380M   1% /run/user/1000

 #  =====================网络接口信息=====================
    link/ether dc:a6:32:18:d8:e4 brd ff:ff:ff:ff:ff:ff

 #  =====================当前登录用户信息=====================

##  w 
  20:29:48 up 48 min,  3 users,  load average: 0.74, 2.50, 4.16
USER     TTY      FROM             LOGIN@   IDLE   JCPU   PCPU WHAT
nisy              -                05Feb25 38:21   5:46   1:23  /usr/bin/labwc -m
nisy     tty1     -                05Feb25 157days  0.09s  0.06s -bash
nisy     pts/2    -                20:29    0.00s  0.06s   ?    sudo ./save_basic_info.sh

 #  =====================显示系统进程信息=====================

##  ps -ef 
 UID        PID  PPID  C STIME TTY          TIME CMD
root         1     0  0 19:41 ?        00:00:03 /sbin/init splash
root         2     0  0 19:41 ?        00:00:00 [kthreadd]
root         3     2  0 19:41 ?        00:00:00 [pool_workqueue_release]
root         4     2  0 19:41 ?        00:00:00 [kworker/R-rcu_g]
root         5     2  0 19:41 ?        00:00:00 [kworker/R-rcu_p]
root         6     2  0 19:41 ?        00:00:00 [kworker/R-slub_]
root         7     2  0 19:41 ?        00:00:00 [kworker/R-netns]
root        12     2  0 19:41 ?        00:00:00 [kworker/R-mm_pe]
root        13     2  0 19:41 ?        00:00:00 [rcu_tasks_kthread]
root        14     2  0 19:41 ?        00:00:00 [rcu_tasks_rude_kthread]
root        15     2  0 19:41 ?        00:00:00 [rcu_tasks_trace_kthread]
root        16     2  0 19:41 ?        00:00:00 [ksoftirqd/0]
root        17     2  0 19:41 ?        00:00:01 [rcu_preempt]
root        18     2  0 19:41 ?        00:00:00 [migration/0]
root        19     2  0 19:41 ?        00:00:00 [cpuhp/0]
root        20     2  0 19:41 ?        00:00:00 [cpuhp/1]
root        21     2  0 19:41 ?        00:00:00 [migration/1]
root        22     2  0 19:41 ?        00:00:00 [ksoftirqd/1]
root        25     2  0 19:41 ?        00:00:00 [cpuhp/2]
root        26     2  0 19:41 ?        00:00:00 [migration/2]
root        27     2  0 19:41 ?        00:00:00 [ksoftirqd/2]
root        30     2  0 19:41 ?        00:00:00 [cpuhp/3]
root        31     2  0 19:41 ?        00:00:00 [migration/3]
root        32     2  0 19:41 ?        00:00:00 [ksoftirqd/3]
root        38     2  0 19:41 ?        00:00:01 [kworker/u12:0-events_unbound]
root        39     2  0 19:41 ?        00:00:00 [kdevtmpfs]
root        40     2  0 19:41 ?        00:00:00 [kworker/R-inet_]
root        42     2  0 19:41 ?        00:00:00 [kauditd]
root        44     2  0 19:41 ?        00:00:00 [khungtaskd]
root        45     2  0 19:41 ?        00:00:00 [oom_reaper]
root        46     2  0 19:41 ?        00:00:00 [kworker/R-write]
root        47     2  0 19:41 ?        00:00:00 [kcompactd0]
root        48     2  0 19:41 ?        00:00:00 [kworker/R-kinte]
root        49     2  0 19:41 ?        00:00:00 [kworker/R-kbloc]
root        50     2  0 19:41 ?        00:00:00 [kworker/R-blkcg]
root        52     2  0 19:41 ?        00:00:02 [kworker/u11:2-events_unbound]
root        54     2  0 19:41 ?        00:00:00 [watchdogd]
root        56     2  0 19:41 ?        00:00:00 [kworker/2:1H-kblockd]
root        57     2  0 19:41 ?        00:00:00 [kworker/R-rpcio]
root        58     2  0 19:41 ?        00:00:00 [kworker/R-xprti]
root        60     2  0 19:41 ?        00:00:00 [kworker/1:1-events]
root        62     2  0 19:41 ?        00:00:00 [kswapd0]
root        63     2  0 19:41 ?        00:00:00 [kworker/R-nfsio]
root        64     2  0 19:41 ?        00:00:00 [kworker/R-kthro]
root        66     2  0 19:41 ?        00:00:00 [kworker/2:3-ipv6_addrconf]
root        70     2  0 19:41 ?        00:00:00 [irq/27-aerdrv]
root        72     2  0 19:41 ?        00:00:00 [hwrng]
root        73     2  0 19:41 ?        00:00:00 [kworker/R-iscsi]
root        74     2  0 19:41 ?        00:00:00 [kworker/R-nvme-]
root        75     2  0 19:41 ?        00:00:00 [kworker/R-nvme-]
root        76     2  0 19:41 ?        00:00:00 [kworker/R-nvme-]
root        78     2  0 19:41 ?        00:00:00 [kworker/R-DWC N]
root        79     2  0 19:41 ?        00:00:00 [kworker/R-uas]
root        80     2  0 19:41 ?        00:00:00 [vchiq-slot/0]
root        81     2  0 19:41 ?        00:00:00 [vchiq-recy/0]
root        82     2  0 19:41 ?        00:00:00 [vchiq-sync/0]
root        83     2  0 19:41 ?        00:00:01 [kworker/0:1H-kblockd]
root        84     2  0 19:41 ?        00:00:11 [kworker/u13:0-brcmf_wq/mmc1:0001:1]
root        85     2  0 19:41 ?        00:00:00 [kworker/u14:0]
root        86     2  0 19:41 ?        00:00:00 [kworker/u15:0]
root        87     2  0 19:41 ?        00:00:00 [kworker/u16:0]
root        88     2  0 19:41 ?        00:00:00 [kworker/u17:0]
root        90     2  0 19:41 ?        00:00:00 [kworker/u10:1-events_unbound]
root        91     2  0 19:41 ?        00:00:00 [kworker/R-sdhci]
root        92     2  0 19:41 ?        00:00:00 [irq/37-mmc0]
root       100     2  0 19:41 ?        00:00:00 [kworker/R-mmc_c]
root       132     2  0 19:41 ?        00:00:00 [kworker/1:1H-kblockd]
root       134     2  0 19:41 ?        00:00:00 [kworker/3:1H-kblockd]
root       168     2  0 19:41 ?        00:00:01 [v3d_bin]
root       169     2  0 19:41 ?        00:00:02 [v3d_render]
root       170     2  0 19:41 ?        00:00:00 [v3d_tfu]
root       171     2  0 19:41 ?        00:00:00 [v3d_csd]
root       172     2  0 19:41 ?        00:00:00 [v3d_cache_clean]
root       177     2  0 19:41 ?        00:00:00 [irq/41-vc4 hdmi hpd connected]
root       178     2  0 19:41 ?        00:00:00 [irq/42-vc4 hdmi hpd disconnected]
root       179     2  0 19:41 ?        00:00:00 [cec-vc4-hdmi-0]
root       180     2  0 19:41 ?        00:00:00 [irq/43-vc4 hdmi cec rx]
root       181     2  0 19:41 ?        00:00:00 [irq/44-vc4 hdmi cec tx]
root       182     2  0 19:41 ?        00:00:00 [irq/45-vc4 hdmi hpd connected]
root       183     2  0 19:41 ?        00:00:00 [irq/46-vc4 hdmi hpd disconnected]
root       184     2  0 19:41 ?        00:00:00 [cec-vc4-hdmi-1]
root       185     2  0 19:41 ?        00:00:00 [irq/47-vc4 hdmi cec rx]
root       186     2  0 19:41 ?        00:00:00 [irq/48-vc4 hdmi cec tx]
root       187     2  0 19:41 ?        00:00:00 [card1-crtc0]
root       188     2  0 19:41 ?        00:00:00 [card1-crtc1]
root       189     2  0 19:41 ?        00:00:00 [card1-crtc2]
root       190     2  0 19:41 ?        00:00:00 [card1-crtc3]
root       191     2  0 19:41 ?        00:00:00 [card1-crtc4]
root       192     2  0 19:41 ?        00:00:00 [card1-crtc5]
root       221     2  0 19:41 ?        00:00:00 [jbd2/mmcblk0p2-8]
root       222     2  0 19:41 ?        00:00:00 [kworker/R-ext4-]
root       240     2  0 19:41 ?        00:00:00 [kworker/R-mld]
root       241     2  0 19:41 ?        00:00:00 [kworker/R-ipv6_]
root       278     1  0 19:41 ?        00:00:01 /lib/systemd/systemd-journald
root       303     2  0 19:41 ?        00:00:00 [kworker/u8:1-ext4-rsv-conversion]
root       308     1  0 19:41 ?        00:00:01 /lib/systemd/systemd-udevd
root       397     2  0 19:41 ?        00:00:00 [vchiq-keep/0]
root       398     2  0 19:41 ?        00:00:00 [SMIO]
root       447     2  0 19:41 ?        00:00:00 [kworker/R-mmal-]
root       449     2  0 19:41 ?        00:00:00 [kworker/R-mmal-]
root       452     2  0 19:41 ?        00:00:00 [kworker/R-mmal-]
root       453     2  0 19:41 ?        00:00:01 [kworker/u10:3-events_unbound]
root       457     2  0 19:41 ?        00:00:00 [kworker/u13:2-hci0]
root       460     2  0 19:41 ?        00:00:00 [kworker/R-mmal-]
systemd+   463     1  0 19:41 ?        00:00:00 /lib/systemd/systemd-timesyncd
root       464     2  0 19:41 ?        00:00:00 [kworker/R-mmal-]
root       466     2  0 19:41 ?        00:00:00 [kworker/R-mmal-]
root       467     2  0 19:41 ?        00:00:00 [kworker/R-mmal-]
root       469     2  0 19:41 ?        00:00:00 [irq/55-feb10000.codec]
root       480     2  0 19:41 ?        00:00:00 [kworker/R-cfg80]
root       484     2  0 19:41 ?        00:00:00 [kworker/R-brcmf]
root       485     2  0 19:41 ?        00:00:00 [brcmf_wdog/mmc1:0001:1]
root       488     1  0 19:41 ?        00:00:00 /usr/libexec/accounts-daemon
avahi      490     1  0 19:41 ?        00:00:00 avahi-daemon: running [raspberrypi.local]
root       491     1  0 19:41 ?        00:00:00 /usr/sbin/cron -f
message+   492     1  0 19:41 ?        00:00:03 /usr/bin/dbus-daemon --system --address=systemd: --nofork --nopidfile --systemd-activation --syslog-only
avahi      506   490  0 19:41 ?        00:00:00 avahi-daemon: chroot helper
polkitd    510     1  0 19:41 ?        00:00:00 /usr/lib/polkit-1/polkitd --no-debug
root       542     1  0 19:41 ?        00:00:00 /lib/systemd/systemd-logind
nobody     554     1  0 19:41 ?        00:00:02 /usr/sbin/thd --triggers /etc/triggerhappy/triggers.d/ --socket /run/thd.socket --user nobody --deviceglob /dev/input/event*
root       558     1  0 19:41 ?        00:00:00 /usr/libexec/udisks2/udisksd
root       675     1  0 19:41 ?        00:00:00 /usr/sbin/ModemManager
root       676     1  0 19:41 ?        00:00:01 /usr/sbin/NetworkManager --no-daemon
root       677     1  0 19:41 ?        00:00:00 /usr/libexec/bluetooth/bluetoothd
root       678     1  0 19:41 ?        00:00:00 /sbin/wpa_supplicant -u -s -O DIR=/run/wpa_supplicant GROUP=netdev
root       737     1  0 19:41 ?        00:00:00 /usr/sbin/lightdm
root       765     1  0 19:41 tty1     00:00:00 /bin/login -f
root       767   737  0 19:41 ?        00:00:00 lightdm --session-child 11 14
nisy       774     1  0 19:41 ?        00:00:00 /lib/systemd/systemd --user
nisy       775   774  0 19:41 ?        00:00:00 (sd-pam)
nisy       790   774  0 19:41 ?        00:00:01 /usr/bin/pipewire
nisy       791   774  0 19:41 ?        00:00:00 /usr/bin/pipewire -c filter-chain.conf
nisy       792   774  0 19:41 ?        00:00:00 /usr/bin/wireplumber
nisy       793   774  0 19:41 ?        00:00:00 /usr/bin/pipewire-pulse
nisy       794   767  2 19:41 ?        00:01:23 /usr/bin/labwc -m
nisy       805   774  0 19:41 ?        00:00:00 /usr/bin/dbus-daemon --session --address=systemd: --nofork --nopidfile --systemd-activation --syslog-only
rtkit      810     1  0 19:41 ?        00:00:00 /usr/libexec/rtkit-daemon
nisy       862   794  0 19:41 ?        00:00:00 /usr/bin/ssh-agent /usr/bin/labwc-pi
root       916     2  0 19:41 ?        00:00:00 [krfcommd]
nisy       922   774  0 19:41 ?        00:00:00 /usr/libexec/xdg-permission-store
nisy       930   765  0 19:41 tty1     00:00:00 -bash
nisy       961     1  0 19:42 ?        00:00:00 /bin/sh /usr/bin/lwrespawn /usr/bin/pcmanfm --desktop --profile LXDE-pi
nisy       962     1  0 19:42 ?        00:00:00 /bin/sh /usr/bin/lwrespawn /usr/bin/wf-panel-pi
nisy       963     1  0 19:42 ?        00:00:00 /usr/bin/kanshi
nisy       976     1  0 19:42 ?        00:00:01 /usr/libexec/polkit-mate-authentication-agent-1
nisy       988     1  0 19:42 ?        00:00:00 systemd-inhibit --what=handle-power-key gtk-nop
nisy       991     1  0 19:42 ?        00:00:00 /usr/bin/python3 /usr/share/system-config-printer/applet.py
nisy      1011   962  1 19:42 ?        00:00:37 /usr/bin/wf-panel-pi
nisy      1020   961  0 19:42 ?        00:00:17 /usr/bin/pcmanfm --desktop --profile LXDE-pi
nisy      1021   988  0 19:42 ?        00:00:00 gtk-nop
nisy      1047   774  0 19:42 ?        00:00:00 /usr/libexec/gvfsd
nisy      1056   774  0 19:42 ?        00:00:00 /usr/libexec/gvfsd-fuse /run/user/1000/gvfs -f
nisy      1070   774  0 19:42 ?        00:00:00 /usr/libexec/xdg-desktop-portal
nisy      1088   774  0 19:42 ?        00:00:00 /usr/libexec/gvfs-udisks2-volume-monitor
nisy      1089   774  0 19:42 ?        00:00:00 /usr/libexec/xdg-desktop-portal-gtk
nisy      1101   774  0 19:42 ?        00:00:00 /usr/libexec/gvfs-goa-volume-monitor
nisy      1106   774  0 19:42 ?        00:00:00 /usr/libexec/gvfs-mtp-volume-monitor
nisy      1112   774  0 19:42 ?        00:00:00 /usr/libexec/gvfs-gphoto2-volume-monitor
nisy      1113   774  0 19:42 ?        00:00:00 /usr/libexec/xdg-desktop-portal-wlr
nisy      1117   774  0 19:42 ?        00:00:00 /usr/libexec/gvfs-afc-volume-monitor
nisy      1125   774  0 19:42 ?        00:00:00 /usr/bin/gnome-keyring-daemon --start --foreground --components=secrets
nisy      1126  1047  0 19:42 ?        00:00:00 /usr/libexec/gvfsd-trash --spawner :1.18 /org/gtk/gvfs/exec_spaw/0
nisy      1127   774  0 19:42 ?        00:00:00 /usr/bin/gnome-keyring-daemon --foreground --components=pkcs11,secrets --control-directory=/run/user/1000/keyring
nisy      1145     1  0 19:42 ?        00:00:00 /usr/lib/menu-cache/menu-cached /run/user/1000/menu-cached-:0
nisy      1342     1  2 19:42 ?        00:00:59 lxterminal
nisy      1352  1342  0 19:42 pts/0    00:00:00 bash
nisy      1393  1047  0 19:42 ?        00:00:00 /usr/libexec/gvfsd-network --spawner :1.18 /org/gtk/gvfs/exec_spaw/1
nisy      1406  1047  0 19:42 ?        00:00:00 /usr/libexec/gvfsd-dnssd --spawner :1.18 /org/gtk/gvfs/exec_spaw/3
nisy      1413   774  0 19:42 ?        00:00:00 /usr/libexec/dconf-service
root      1480     1  0 19:42 ?        00:00:00 /usr/sbin/cupsd -l
root      1481     1  0 19:42 ?        00:00:00 /usr/sbin/cups-browsed
root      1640     2  0 19:46 ?        00:00:01 [kworker/u9:3-events_unbound]
nisy      1809   774  0 19:51 ?        00:00:00 /usr/libexec/gvfsd-metadata
nisy      1842  1342  0 19:51 pts/1    00:00:00 bash
nisy      2394  1011  1 19:54 ?        00:00:39 lxtask
root      2574     2  0 19:56 ?        00:00:00 [kworker/u8:2]
root      2640     2  0 19:57 ?        00:00:01 [kworker/u9:1-events_unbound]
root      3188     2  0 20:04 ?        00:00:00 [kworker/2:0-events_power_efficient]
root      3219     2  0 20:04 ?        00:00:00 [kworker/u12:1-events_unbound]
root      3240     2  0 20:04 ?        00:00:01 [kworker/u11:1-events_unbound]
root      4056     2  0 20:08 ?        00:00:00 [kworker/1:0H-kblockd]
root      4335     2  0 20:11 ?        00:00:00 [kworker/0:2H-mmc_complete]
root      4410     2  0 20:12 ?        00:00:00 [kworker/0:2-events]
root      4415     2  0 20:12 ?        00:00:00 [kworker/u10:2-events_unbound]
root      4550     1  0 20:13 ?        00:00:00 /usr/libexec/upowerd
root      4558     2  0 20:13 ?        00:00:00 [kworker/3:3-events]
root      4696     2  0 20:16 ?        00:00:00 [kworker/1:2-inet_frag_wq]
root      4716     2  0 20:17 ?        00:00:00 [kworker/3:0H-kblockd]
root      4718     2  0 20:17 ?        00:00:00 [kworker/u10:0-events_unbound]
root      4719     2  0 20:18 ?        00:00:00 [kworker/0:1-events]
root      4720     2  0 20:18 ?        00:00:00 [kworker/u11:3-events_unbound]
root      4728     2  0 20:19 ?        00:00:00 [kworker/3:1-mm_percpu_wq]
root      4734     2  0 20:19 ?        00:00:00 [kworker/2:0H-kblockd]
root      4748     2  0 20:20 ?        00:00:00 [kworker/u9:0-events_unbound]
root      4756     2  0 20:20 ?        00:00:00 [kworker/2:2-mm_percpu_wq]
nisy      4794  1020 10 20:22 ?        00:00:46 geany /home/nisy/_code/github_sample_c_code2/_linux_driver_sample/_save_basic_info.sh_??????linux???????????????????????????????????????,?????????????????????/save_basic_info.sh
root      4831     2  0 20:22 ?        00:00:00 [kworker/1:0-mm_percpu_wq]
nisy      4997  4794  0 20:22 pts/3    00:00:00 /bin/bash
root      5160     2  0 20:22 ?        00:00:00 [kworker/u12:2]
root      5515     2  0 20:25 ?        00:00:00 [kworker/3:0-events]
root      5534     2  0 20:26 ?        00:00:00 [kworker/1:2H]
root      5535     2  0 20:26 ?        00:00:00 [kworker/2:2H-kblockd]
root      5537     2  0 20:26 ?        00:00:00 [kworker/2:1-events]
root      5579     2  0 20:26 ?        00:00:00 [kworker/1:3-cgroup_destroy]
root      5632     2  0 20:26 ?        00:00:00 [kworker/u11:0-events_unbound]
root      5704     2  0 20:27 ?        00:00:00 [kworker/u9:2-events_unbound]
root      5715     2  0 20:29 ?        00:00:00 [kworker/0:0-events]
root      5720  1842  0 20:29 pts/1    00:00:00 sudo ./save_basic_info.sh
root      5721  5720  0 20:29 pts/2    00:00:00 sudo ./save_basic_info.sh
root      5722  5721  6 20:29 pts/2    00:00:00 /bin/bash ./save_basic_info.sh
root      5762  5722 99 20:29 pts/2    00:00:00 ps -ef

 #  =====================常用命令 =====================

##  lspci 
 00:00.0 PCI bridge: Broadcom Inc. and subsidiaries BCM2711 PCIe Bridge (rev 10)
01:00.0 USB controller: VIA Technologies, Inc. VL805/806 xHCI USB 3.0 Controller (rev 01)

##  lsusb 
 Bus 002 Device 001: ID 1d6b:0003 Linux Foundation 3.0 root hub
Bus 001 Device 003: ID 13ba:0018 PCPlay Barcode PCP-BCG4209
Bus 001 Device 002: ID 2109:3431 VIA Labs, Inc. Hub
Bus 001 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub

##  fdisk -l 
 Disk /dev/ram0: 4 MiB, 4194304 bytes, 8192 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 4096 bytes
I/O size (minimum/optimal): 4096 bytes / 4096 bytes


Disk /dev/ram1: 4 MiB, 4194304 bytes, 8192 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 4096 bytes
I/O size (minimum/optimal): 4096 bytes / 4096 bytes


Disk /dev/ram2: 4 MiB, 4194304 bytes, 8192 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 4096 bytes
I/O size (minimum/optimal): 4096 bytes / 4096 bytes


Disk /dev/ram3: 4 MiB, 4194304 bytes, 8192 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 4096 bytes
I/O size (minimum/optimal): 4096 bytes / 4096 bytes


Disk /dev/ram4: 4 MiB, 4194304 bytes, 8192 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 4096 bytes
I/O size (minimum/optimal): 4096 bytes / 4096 bytes


Disk /dev/ram5: 4 MiB, 4194304 bytes, 8192 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 4096 bytes
I/O size (minimum/optimal): 4096 bytes / 4096 bytes


Disk /dev/ram6: 4 MiB, 4194304 bytes, 8192 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 4096 bytes
I/O size (minimum/optimal): 4096 bytes / 4096 bytes


Disk /dev/ram7: 4 MiB, 4194304 bytes, 8192 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 4096 bytes
I/O size (minimum/optimal): 4096 bytes / 4096 bytes


Disk /dev/ram8: 4 MiB, 4194304 bytes, 8192 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 4096 bytes
I/O size (minimum/optimal): 4096 bytes / 4096 bytes


Disk /dev/ram9: 4 MiB, 4194304 bytes, 8192 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 4096 bytes
I/O size (minimum/optimal): 4096 bytes / 4096 bytes


Disk /dev/ram10: 4 MiB, 4194304 bytes, 8192 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 4096 bytes
I/O size (minimum/optimal): 4096 bytes / 4096 bytes


Disk /dev/ram11: 4 MiB, 4194304 bytes, 8192 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 4096 bytes
I/O size (minimum/optimal): 4096 bytes / 4096 bytes


Disk /dev/ram12: 4 MiB, 4194304 bytes, 8192 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 4096 bytes
I/O size (minimum/optimal): 4096 bytes / 4096 bytes


Disk /dev/ram13: 4 MiB, 4194304 bytes, 8192 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 4096 bytes
I/O size (minimum/optimal): 4096 bytes / 4096 bytes


Disk /dev/ram14: 4 MiB, 4194304 bytes, 8192 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 4096 bytes
I/O size (minimum/optimal): 4096 bytes / 4096 bytes


Disk /dev/ram15: 4 MiB, 4194304 bytes, 8192 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 4096 bytes
I/O size (minimum/optimal): 4096 bytes / 4096 bytes


Disk /dev/mmcblk0: 14.48 GiB, 15548284928 bytes, 30367744 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disklabel type: dos
Disk identifier: 0x0f9618e8

Device         Boot   Start      End  Sectors  Size Id Type
/dev/mmcblk0p1         8192  1056767  1048576  512M  c W95 FAT32 (LBA)
/dev/mmcblk0p2      1056768 30367743 29310976   14G 83 Linux

##  i2cdetect -l 
 i2c-0	i2c       	i2c-22-mux (chan_id 0)          	I2C adapter
i2c-1	i2c       	bcm2835 (i2c@7e804000)          	I2C adapter
i2c-10	i2c       	i2c-22-mux (chan_id 1)          	I2C adapter
i2c-20	i2c       	fef04500.i2c                    	I2C adapter
i2c-21	i2c       	fef09500.i2c                    	I2C adapter
i2c-22	i2c       	bcm2835 (i2c@7e205000)          	I2C adapter

##  i2cdetect -y 0 
      0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
00:                         -- -- -- -- -- -- -- -- 
10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
20: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
30: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
40: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
50: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
60: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
70: -- -- -- -- -- -- -- --                         

##  i2cdetect -y 1 
      0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
00:                         -- -- -- -- -- -- -- -- 
10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
20: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
30: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
40: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
50: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
60: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
70: -- -- -- -- -- -- -- --                         

##  i2cdetect -y 2 
 

##  i2cdetect -y 3 
 

##  i2cdetect -y 4 
 

##  i2cdetect -y 5 
 

##  i2cdetect -y 6 
 

##  i2cdetect -y 7 
 

##  blkid 
 /dev/mmcblk0p1: LABEL_FATBOOT="bootfs" LABEL="bootfs" UUID="60E3-BF60" BLOCK_SIZE="512" TYPE="vfat" PARTUUID="0f9618e8-01"
/dev/mmcblk0p2: LABEL="rootfs" UUID="74f968bb-7c40-44cd-8d3e-6963921bf08b" BLOCK_SIZE="4096" TYPE="ext4" PARTUUID="0f9618e8-02"

##  lsmod 
 Module                  Size  Used by
rfcomm                 53248  4
snd_seq_dummy          12288  0
snd_hrtimer            12288  1
snd_seq                81920  7 snd_seq_dummy
snd_seq_device         16384  1 snd_seq
cmac                   12288  2
algif_hash             12288  1
aes_arm64              12288  2
aes_generic            32768  1 aes_arm64
algif_skcipher         12288  1
af_alg                 24576  6 algif_hash,algif_skcipher
bnep                   24576  2
brcmfmac_wcc           12288  0
brcmfmac              348160  1 brcmfmac_wcc
brcmutil               24576  1 brcmfmac
cfg80211              983040  1 brcmfmac
bcm2835_codec          45056  0
rpivid_hevc            45056  0
bcm2835_unicam         49152  6
binfmt_misc            16384  1
bcm2835_isp            28672  10
ov5647                 20480  3
hci_uart               49152  0
bcm2835_v4l2           40960  0
v4l2_mem2mem           45056  2 bcm2835_codec,rpivid_hevc
v4l2_dv_timings        32768  1 bcm2835_unicam
bcm2835_mmal_vchiq     36864  3 bcm2835_codec,bcm2835_v4l2,bcm2835_isp
v4l2_fwnode            20480  2 ov5647,bcm2835_unicam
videobuf2_vmalloc      12288  1 bcm2835_v4l2
v4l2_async             20480  3 v4l2_fwnode,ov5647,bcm2835_unicam
btbcm                  24576  1 hci_uart
videobuf2_dma_contig    16384  4 bcm2835_codec,bcm2835_unicam,rpivid_hevc,bcm2835_isp
videobuf2_memops       12288  2 videobuf2_vmalloc,videobuf2_dma_contig
videobuf2_v4l2         32768  6 bcm2835_codec,bcm2835_unicam,bcm2835_v4l2,rpivid_hevc,v4l2_mem2mem,bcm2835_isp
bluetooth             606208  33 hci_uart,btbcm,bnep,rfcomm
videodev              303104  22 v4l2_async,bcm2835_codec,v4l2_fwnode,ov5647,videobuf2_v4l2,bcm2835_unicam,bcm2835_v4l2,rpivid_hevc,v4l2_mem2mem,bcm2835_isp
raspberrypi_hwmon      12288  0
ecdh_generic           16384  1 bluetooth
videobuf2_common       69632  10 bcm2835_codec,videobuf2_vmalloc,videobuf2_dma_contig,videobuf2_v4l2,bcm2835_unicam,bcm2835_v4l2,rpivid_hevc,v4l2_mem2mem,videobuf2_memops,bcm2835_isp
ecc                    36864  1 ecdh_generic
rfkill                 32768  6 bluetooth,cfg80211
snd_bcm2835            24576  1
mc                     61440  14 v4l2_async,videodev,bcm2835_codec,ov5647,videobuf2_v4l2,bcm2835_unicam,videobuf2_common,rpivid_hevc,v4l2_mem2mem,bcm2835_isp
vc_sm_cma              28672  2 bcm2835_mmal_vchiq,bcm2835_isp
libaes                 12288  3 aes_arm64,bluetooth,aes_generic
joydev                 24576  0
raspberrypi_gpiomem    12288  0
nvmem_rmem             12288  0
uio_pdrv_genirq        12288  0
uio                    20480  1 uio_pdrv_genirq
i2c_dev                16384  0
ledtrig_pattern        12288  0
fuse                  139264  4
dm_mod                143360  0
ip_tables              32768  0
x_tables               49152  1 ip_tables
ipv6                  565248  42
vc4                   376832  15
v3d                    90112  3
snd_soc_hdmi_codec     20480  2
gpu_sched              49152  1 v3d
drm_display_helper     16384  1 vc4
cec                    53248  1 vc4
drm_dma_helper         24576  3 vc4
drm_kms_helper        212992  2 drm_dma_helper,vc4
i2c_mux_pinctrl        12288  0
drm_shmem_helper       24576  1 v3d
drm                   643072  15 gpu_sched,drm_kms_helper,drm_dma_helper,v3d,vc4,drm_shmem_helper,drm_display_helper
snd_soc_core          286720  2 vc4,snd_soc_hdmi_codec
i2c_mux                12288  1 i2c_mux_pinctrl
drm_panel_orientation_quirks    28672  1 drm
i2c_brcmstb            12288  0
snd_compress           16384  1 snd_soc_core
i2c_bcm2835            16384  1
snd_pcm_dmaengine      16384  1 snd_soc_core
snd_pcm               139264  5 snd_bcm2835,snd_soc_hdmi_codec,snd_compress,snd_soc_core,snd_pcm_dmaengine
snd_timer              36864  3 snd_seq,snd_hrtimer,snd_pcm
snd                   110592  14 snd_seq,snd_seq_device,snd_bcm2835,snd_soc_hdmi_codec,snd_timer,snd_compress,snd_soc_core,snd_pcm
backlight              24576  2 drm_kms_helper,drm

##  ls -al /bin 
 lrwxrwxrwx 1 root root 7 Nov 19  2024 /bin -> usr/bin

##  busybox BusyBox v1.35.0 (Raspbian 1:1.35.0-4) multi-call binary.
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
	[, [[, acpid, adjtimex, ar, arch, arp, arping, ascii, ash, awk, base64, basename, bc, blkdiscard, blkid, blockdev, brctl, bunzip2, bzcat, bzip2, cal, cat, chgrp, chmod, chown, chroot, chvt, clear, cmp,
	cp, cpio, crc32, cttyhack, cut, date, dc, dd, deallocvt, depmod, devmem, df, diff, dirname, dmesg, dnsdomainname, dos2unix, du, dumpkmap, dumpleases, echo, egrep, env, expand, expr, factor, fallocate,
	false, fatattr, fdisk, fgrep, find, findfs, fold, free, freeramdisk, fsfreeze, fstrim, ftpget, ftpput, getopt, getty, grep, groups, gunzip, gzip, halt, head, hexdump, hostid, hostname, httpd, hwclock,
	i2cdetect, i2cdump, i2cget, i2cset, i2ctransfer, id, ifconfig, ifdown, ifup, init, insmod, ionice, ip, ipcalc, ipneigh, kill, killall, klogd, last, less, link, linux32, linux64, linuxrc, ln, loadfont,
	loadkmap, logger, login, logname, logread, losetup, ls, lsmod, lsscsi, lzcat, lzma, lzop, md5sum, mdev, microcom, mim, mkdir, mkdosfs, mke2fs, mkfifo, mknod, mkpasswd, mkswap, mktemp, modinfo, modprobe,
	more, mount, mt, mv, nameif, nc, netstat, nl, nologin, nproc, nsenter, nslookup, nuke, od, openvt, partprobe, paste, patch, pidof, ping, ping6, pivot_root, poweroff, printf, ps, pwd, rdate, readlink,
	realpath, reboot, renice, reset, resume, rev, rm, rmdir, rmmod, route, rpm, rpm2cpio, run-init, run-parts, sed, seq, setkeycodes, setpriv, setsid, sh, sha1sum, sha256sum, sha3sum, sha512sum, shred,
	shuf, sleep, sort, ssl_client, start-stop-daemon, stat, strings, stty, svc, svok, swapoff, swapon, switch_root, sync, sysctl, syslogd, tac, tail, tar, taskset, tee, telnet, test, tftp, time, timeout,
	top, touch, tr, traceroute, traceroute6, true, truncate, ts, tty, ubirename, udhcpc, udhcpd, uevent, umount, uname, uncompress, unexpand, uniq, unix2dos, unlink, unlzma, unshare, unxz, unzip, uptime,
	usleep, uudecode, uuencode, vconfig, vi, w, watch, watchdog, wc, wget, which, who, whoami, xargs, xxd, xz, xzcat, yes, zcat

 #  ===================== /sys/ 文件系统 =====================

##  ls -al /sys/devices/platform/ 
 total 0
drwxr-xr-x 27 root root    0 Jan  1  1970 .
drwxr-xr-x 10 root root    0 Jan  1  1970 ..
drwxr-xr-x  4 root root    0 Jan  1  1970 3ef64de0.nvram
drwxr-xr-x  3 root root    0 Jan  1  1970 arm-pmu
drwxr-xr-x  4 root root    0 Jan  1  1970 cam1_regulator
drwxr-xr-x  4 root root    0 Jan  1  1970 cam_dummy_reg
drwxr-xr-x  3 root root    0 Jan  1  1970 chosen
drwxr-xr-x  3 root root    0 Jan  1  1970 clocks
drwxr-xr-x  3 root root    0 Jan  1  1970 cpufreq-dt
drwxr-xr-x  4 root root    0 Jan  1  1970 emmc2bus
drwxr-xr-x  4 root root    0 Jan  1  1970 Fixed MDIO bus.0
drwxr-xr-x  4 root root    0 Jan  1  1970 fixedregulator_3v3
drwxr-xr-x  4 root root    0 Jan  1  1970 fixedregulator_5v0
drwxr-xr-x  5 root root    0 Jan  1  1970 gpu
drwxr-xr-x  3 root root    0 Jan  1  1970 kgdboc
drwxr-xr-x  4 root root    0 Jan  1  1970 leds
drwxr-xr-x  3 root root    0 Jan  1  1970 phy
drwxr-xr-x  2 root root    0 Jul 13 20:22 power
drwxr-xr-x  4 root root    0 Jan  1  1970 reg-dummy
drwxr-xr-x  4 root root    0 Jan  1  1970 regulator-sd-io-1v8
drwxr-xr-x  4 root root    0 Jan  1  1970 regulator-sd-vcc
drwxr-xr-x  3 root root    0 Feb  5 22:35 regulatory.0
drwxr-xr-x  7 root root    0 Jan  1  1970 scb
drwxr-xr-x  3 root root    0 Jan  1  1970 snd-soc-dummy
drwxr-xr-x 36 root root    0 Jan  1  1970 soc
drwxr-xr-x  3 root root    0 Jan  1  1970 timer
-rw-r--r--  1 root root 4096 Jan  1  1970 uevent
drwxr-xr-x  4 root root    0 Jan  1  1970 v3dbus

##  cat /sys/devices/system/cpu/cpu*/cpufreq/cpuinfo_cur_freq 
 1500000
1500000
1500000
1500000

##  ls -al /sys/kernel/debug 
 total 0
drwxr-x--- 42 root sudo 0 Jan  1  1970 .
drwxr-xr-x 14 root root 0 Jan  1  1970 ..
drwxr-xr-x  4 root root 0 Jan  1  1970 asoc
drwxr-xr-x  2 root root 0 Jan  1  1970 bcm7271-uart
drwxr-xr-x 29 root root 0 Jan  1  1970 bdi
drwxr-xr-x  3 root root 0 Jan  1  1970 binder
drwxr-xr-x 27 root root 0 Jan  1  1970 block
drwxr-xr-x  3 root root 0 Feb  5 22:35 bluetooth
drwxr-xr-x  4 root root 0 Jan  1  1970 cec
--w-------  1 root root 0 Jan  1  1970 clear_warn_once
drwxr-xr-x 68 root root 0 Jan  1  1970 clk
-rw-r--r--  1 root root 0 Jan  1  1970 debug_enabled
drwxr-xr-x  2 root root 0 Jan  1  1970 device_component
-r--r--r--  1 root root 0 Jan  1  1970 devices_deferred
drwxr-xr-x  2 root root 0 Jan  1  1970 dma_buf
drwxr-xr-x  4 root root 0 Jan  1  1970 dmaengine
drwxr-xr-x  2 root root 0 Jan  1  1970 dma_pools
drwxr-xr-x  5 root root 0 Jan  1  1970 dri
drwxr-xr-x  2 root root 0 Jan  1  1970 extfrag
drwxr-xr-x  2 root root 0 Jan  1  1970 f2fs
-rw-r--r--  1 root root 0 Jan  1  1970 fault_around_bytes
-r--r--r--  1 root root 0 Jan  1  1970 gpio
drwxr-xr-x  4 root root 0 Jan  1  1970 hid
drwxr-xr-x  3 root root 0 Feb  5 22:35 ieee80211
drwxr-xr-x  4 root root 0 Jan  1  1970 irq
drwxr-xr-x  2 root root 0 Jan  1  1970 kprobes
drwxr-xr-x  2 root root 0 Jan  1  1970 kvm
-rw-r--r--  1 root root 0 Jan  1  1970 lru_gen
-r--r--r--  1 root root 0 Jan  1  1970 lru_gen_full
drwxr-xr-x  2 root root 0 Jan  1  1970 memblock
drwxr-xr-x  3 root root 0 Jan  1  1970 mmc0
drwxr-xr-x  3 root root 0 Jan  1  1970 mmc1
drwxr-xr-x  3 root root 0 Jan  1  1970 opp
drwxr-xr-x  2 root root 0 Jan  1  1970 phy
drwxr-xr-x  3 root root 0 Jan  1  1970 pinctrl
drwxr-xr-x 38 root root 0 Jan  1  1970 pm_genpd
-r--r--r--  1 root root 0 Jan  1  1970 pwm
drwxr-xr-x  2 root root 0 Jan  1  1970 ramdisk_pages
drwxr-xr-x  2 root root 0 Jan  1  1970 ras
drwxr-xr-x  3 root root 0 Jan  1  1970 regmap
drwxr-xr-x  9 root root 0 Jan  1  1970 regulator
drwxr-xr-x  2 root root 0 Jan  1  1970 sched
drwxr-xr-x  2 root root 0 Jan  1  1970 slab
-r--r--r--  1 root root 0 Jan  1  1970 sleep_time
drwxr-xr-x  2 root root 0 Jan  1  1970 swiotlb
dr-xr-xr-x  3 root root 0 Jan  1  1970 tracing
drwxr-xr-x  3 root root 0 Jan  1  1970 usb
drwxr-xr-x  2 root root 0 Feb  5 22:35 v4l2-async
drwxr-xr-x  4 root root 0 Jan  1  1970 vchiq
drwxr-xr-x  2 root root 0 Jan  1  1970 vc-mem
drwxr-xr-x  2 root root 0 Feb  5 22:35 vcsm-cma

##  cat /sys/kernel/debug/gpio 
 gpiochip0: GPIOs 512-569, parent: platform/fe200000.gpio, pinctrl-bcm2711:
 gpio-512 (ID_SDA              )
 gpio-513 (ID_SCL              )
 gpio-514 (GPIO2               )
 gpio-515 (GPIO3               )
 gpio-516 (GPIO4               )
 gpio-517 (GPIO5               )
 gpio-518 (GPIO6               )
 gpio-519 (GPIO7               )
 gpio-520 (GPIO8               )
 gpio-521 (GPIO9               )
 gpio-522 (GPIO10              )
 gpio-523 (GPIO11              )
 gpio-524 (GPIO12              )
 gpio-525 (GPIO13              )
 gpio-526 (GPIO14              )
 gpio-527 (GPIO15              )
 gpio-528 (GPIO16              )
 gpio-529 (GPIO17              )
 gpio-530 (GPIO18              )
 gpio-531 (GPIO19              )
 gpio-532 (GPIO20              )
 gpio-533 (GPIO21              )
 gpio-534 (GPIO22              )
 gpio-535 (GPIO23              )
 gpio-536 (GPIO24              )
 gpio-537 (GPIO25              )
 gpio-538 (GPIO26              )
 gpio-539 (GPIO27              )
 gpio-540 (RGMII_MDIO          )
 gpio-541 (RGMIO_MDC           )
 gpio-542 (CTS0                )
 gpio-543 (RTS0                )
 gpio-544 (TXD0                )
 gpio-545 (RXD0                )
 gpio-546 (SD1_CLK             )
 gpio-547 (SD1_CMD             )
 gpio-548 (SD1_DATA0           )
 gpio-549 (SD1_DATA1           )
 gpio-550 (SD1_DATA2           )
 gpio-551 (SD1_DATA3           )
 gpio-552 (PWM0_MISO           )
 gpio-553 (PWM1_MOSI           )
 gpio-554 (STATUS_LED_G_CLK    |ACT                 ) out lo 
 gpio-555 (SPIFLASH_CE_N       )
 gpio-556 (SDA0                )
 gpio-557 (SCL0                )
 gpio-558 (RGMII_RXCLK         )
 gpio-559 (RGMII_RXCTL         )
 gpio-560 (RGMII_RXD0          )
 gpio-561 (RGMII_RXD1          )
 gpio-562 (RGMII_RXD2          )
 gpio-563 (RGMII_RXD3          )
 gpio-564 (RGMII_TXCLK         )
 gpio-565 (RGMII_TXCTL         )
 gpio-566 (RGMII_TXD0          )
 gpio-567 (RGMII_TXD1          )
 gpio-568 (RGMII_TXD2          )
 gpio-569 (RGMII_TXD3          )

gpiochip1: GPIOs 570-577, parent: platform/soc:firmware:gpio, raspberrypi-exp-gpio, can sleep:
 gpio-570 (BT_ON               |shutdown            ) out hi 
 gpio-571 (WL_ON               )
 gpio-572 (PWR_LED_OFF         |PWR                 ) out lo ACTIVE LOW
 gpio-573 (GLOBAL_RESET        )
 gpio-574 (VDD_SD_IO_SEL       |vdd-sd-io           ) out lo 
 gpio-575 (CAM_GPIO            |cam1_regulator      ) out lo 
 gpio-576 (SD_PWR_ON           |regulator-sd-vcc    ) out hi 
 gpio-577 (SD_OC_N             )

##  ===================== 打印 /sys/class/video4linux/video* =====================

##  ls -al /sys/class/video4linux 
 total 0
drwxr-xr-x  2 root root 0 Feb  5 22:35 .
drwxr-xr-x 66 root root 0 Jan  1  1970 ..
lrwxrwxrwx  1 root root 0 Feb  5 22:36 v4l-subdev0 -> ../../devices/platform/soc/fe205000.i2c/i2c-22/i2c-10/10-0036/video4linux/v4l-subdev0
lrwxrwxrwx  1 root root 0 Feb  5 22:36 video0 -> ../../devices/platform/soc/fe801000.csi/video4linux/video0
lrwxrwxrwx  1 root root 0 Feb  5 22:36 video10 -> ../../devices/platform/soc/fe00b840.mailbox/bcm2835-codec/video4linux/video10
lrwxrwxrwx  1 root root 0 Feb  5 22:36 video11 -> ../../devices/platform/soc/fe00b840.mailbox/bcm2835-codec/video4linux/video11
lrwxrwxrwx  1 root root 0 Feb  5 22:36 video12 -> ../../devices/platform/soc/fe00b840.mailbox/bcm2835-codec/video4linux/video12
lrwxrwxrwx  1 root root 0 Feb  5 22:36 video13 -> ../../devices/platform/soc/fe00b840.mailbox/bcm2835-isp/video4linux/video13
lrwxrwxrwx  1 root root 0 Feb  5 22:36 video14 -> ../../devices/platform/soc/fe00b840.mailbox/bcm2835-isp/video4linux/video14
lrwxrwxrwx  1 root root 0 Feb  5 22:36 video15 -> ../../devices/platform/soc/fe00b840.mailbox/bcm2835-isp/video4linux/video15
lrwxrwxrwx  1 root root 0 Feb  5 22:36 video16 -> ../../devices/platform/soc/fe00b840.mailbox/bcm2835-isp/video4linux/video16
lrwxrwxrwx  1 root root 0 Feb  5 22:36 video18 -> ../../devices/platform/soc/fe00b840.mailbox/bcm2835-codec/video4linux/video18
lrwxrwxrwx  1 root root 0 Feb  5 22:36 video19 -> ../../devices/platform/scb/feb10000.codec/video4linux/video19
lrwxrwxrwx  1 root root 0 Feb  5 22:36 video20 -> ../../devices/platform/soc/fe00b840.mailbox/bcm2835-isp/video4linux/video20
lrwxrwxrwx  1 root root 0 Feb  5 22:36 video21 -> ../../devices/platform/soc/fe00b840.mailbox/bcm2835-isp/video4linux/video21
lrwxrwxrwx  1 root root 0 Feb  5 22:36 video22 -> ../../devices/platform/soc/fe00b840.mailbox/bcm2835-isp/video4linux/video22
lrwxrwxrwx  1 root root 0 Feb  5 22:36 video23 -> ../../devices/platform/soc/fe00b840.mailbox/bcm2835-isp/video4linux/video23
lrwxrwxrwx  1 root root 0 Feb  5 22:36 video31 -> ../../devices/platform/soc/fe00b840.mailbox/bcm2835-codec/video4linux/video31
/sys/class/video4linux/video0
dev:81:1
name:unicam-image
index:0
link_name:

/sys/class/video4linux/video10
dev:81:10
name:bcm2835-codec-decode
index:0
link_name:

/sys/class/video4linux/video11
dev:81:11
name:bcm2835-codec-encode
index:0
link_name:

/sys/class/video4linux/video12
dev:81:12
name:bcm2835-codec-isp
index:0
link_name:

/sys/class/video4linux/video13
dev:81:0
name:bcm2835-isp-output0
index:0
link_name:

/sys/class/video4linux/video14
dev:81:3
name:bcm2835-isp-capture0
index:1
link_name:

/sys/class/video4linux/video15
dev:81:4
name:bcm2835-isp-capture1
index:2
link_name:

/sys/class/video4linux/video16
dev:81:5
name:bcm2835-isp-stats2
index:3
link_name:

/sys/class/video4linux/video18
dev:81:13
name:bcm2835-codec-image_fx
index:0
link_name:

/sys/class/video4linux/video19
dev:81:15
name:rpivid
index:0
link_name:

/sys/class/video4linux/video20
dev:81:6
name:bcm2835-isp-output0
index:0
link_name:

/sys/class/video4linux/video21
dev:81:7
name:bcm2835-isp-capture0
index:1
link_name:

/sys/class/video4linux/video22
dev:81:8
name:bcm2835-isp-capture1
index:2
link_name:

/sys/class/video4linux/video23
dev:81:9
name:bcm2835-isp-stats2
index:3
link_name:

/sys/class/video4linux/video31
dev:81:14
name:bcm2835-codec-encode_image
index:0
link_name:


##  ===================== 打印 /sys/class/video4linux/v4l-subdev* =====================
/sys/class/video4linux/v4l-subdev0
dev:81:2
name:ov5647 10-0036
index:1
link_name:


##  ===================== 打印 /sys/bus/media/devices/media* =====================

##  ls -al /sys/bus/media/devices 
 total 0
drwxr-xr-x 2 root root 0 Feb  5 22:36 .
drwxr-xr-x 4 root root 0 Feb  5 22:35 ..
lrwxrwxrwx 1 root root 0 Feb  5 22:36 media0 -> ../../../devices/platform/soc/fe801000.csi/media0
lrwxrwxrwx 1 root root 0 Feb  5 22:36 media1 -> ../../../devices/platform/soc/fe00b840.mailbox/bcm2835-isp/media1
lrwxrwxrwx 1 root root 0 Feb  5 22:36 media2 -> ../../../devices/platform/soc/fe00b840.mailbox/bcm2835-isp/media2
lrwxrwxrwx 1 root root 0 Feb  5 22:36 media3 -> ../../../devices/platform/soc/fe00b840.mailbox/bcm2835-codec/media3
lrwxrwxrwx 1 root root 0 Feb  5 22:36 media4 -> ../../../devices/platform/scb/feb10000.codec/media4
/sys/bus/media/devices/media0
dev:237:0
model:unicam

/sys/bus/media/devices/media1
dev:237:1
model:bcm2835-isp

/sys/bus/media/devices/media2
dev:237:2
model:bcm2835-isp

/sys/bus/media/devices/media3
dev:237:3
model:bcm2835-codec

/sys/bus/media/devices/media4
dev:237:4
model:rpivid


##  ===================== 打印 /sys/ 的thermal相关 =====================

##  cat /sys/devices/virtual/thermal/thermal_zone*/type 
 cpu-thermal

##  cat /sys/devices/virtual/thermal/cooling_device*/type 
 

 #  ===================== /proc/ 文件系统 =====================

##  cat /proc/cmdline 
 coherent_pool=1M 8250.nr_uarts=0 snd_bcm2835.enable_headphones=0 snd_bcm2835.enable_headphones=1 snd_bcm2835.enable_hdmi=1 snd_bcm2835.enable_hdmi=0  smsc95xx.macaddr=DC:A6:32:17:19:A2 vc_mem.mem_base=0x3ec00000 vc_mem.mem_size=0x40000000  console=ttyS0,115200 console=tty1 root=PARTUUID=0f9618e8-02 rootfstype=ext4 fsck.repair=yes rootwait quiet splash plymouth.ignore-serial-consoles cfg80211.ieee80211_regdom=GB

##  cat /proc/cpuinfo 
 processor	: 0
BogoMIPS	: 108.00
Features	: fp asimd evtstrm crc32 cpuid
CPU implementer	: 0x41
CPU architecture: 8
CPU variant	: 0x0
CPU part	: 0xd08
CPU revision	: 3

processor	: 1
BogoMIPS	: 108.00
Features	: fp asimd evtstrm crc32 cpuid
CPU implementer	: 0x41
CPU architecture: 8
CPU variant	: 0x0
CPU part	: 0xd08
CPU revision	: 3

processor	: 2
BogoMIPS	: 108.00
Features	: fp asimd evtstrm crc32 cpuid
CPU implementer	: 0x41
CPU architecture: 8
CPU variant	: 0x0
CPU part	: 0xd08
CPU revision	: 3

processor	: 3
BogoMIPS	: 108.00
Features	: fp asimd evtstrm crc32 cpuid
CPU implementer	: 0x41
CPU architecture: 8
CPU variant	: 0x0
CPU part	: 0xd08
CPU revision	: 3

Revision	: c03111
Serial		: 10000000bafb5028
Model		: Raspberry Pi 4 Model B Rev 1.1

##  cat /proc/meminfo 
 MemTotal:        3882988 kB
MemFree:         1742228 kB
MemAvailable:    3412232 kB
Buffers:           51724 kB
Cached:          1717040 kB
SwapCached:            0 kB
Active:           960624 kB
Inactive:         945896 kB
Active(anon):     241404 kB
Inactive(anon):        0 kB
Active(file):     719220 kB
Inactive(file):   945896 kB
Unevictable:       50812 kB
Mlocked:               0 kB
SwapTotal:        524284 kB
SwapFree:         524284 kB
Zswap:                 0 kB
Zswapped:              0 kB
Dirty:               160 kB
Writeback:             0 kB
AnonPages:        188524 kB
Mapped:           216852 kB
Shmem:            103648 kB
KReclaimable:      82364 kB
Slab:             116120 kB
SReclaimable:      82364 kB
SUnreclaim:        33756 kB
KernelStack:        5320 kB
PageTables:         6504 kB
SecPageTables:         0 kB
NFS_Unstable:          0 kB
Bounce:                0 kB
WritebackTmp:          0 kB
CommitLimit:     2465776 kB
Committed_AS:    1770196 kB
VmallocTotal:   257687552 kB
VmallocUsed:       13484 kB
VmallocChunk:          0 kB
Percpu:              816 kB
CmaTotal:         524288 kB
CmaFree:          492256 kB

##  cat /proc/driver 
 

##  cat /proc/iomem 
 00000000-3b3fffff : System RAM
  00000000-00000fff : reserved
  00210000-0136ffff : Kernel code
  01370000-0182ffff : reserved
  01830000-01b6ffff : Kernel data
  0dc00000-2dbfffff : reserved
  2dfff000-2e00dfff : reserved
  2e00e000-2effffff : reserved
  37400000-3b3fffff : reserved
40000000-fbffffff : System RAM
  f7000000-fb5fffff : reserved
  fb6a7000-fb766fff : reserved
  fb767000-fb767fff : reserved
  fb768000-fb7dffff : reserved
  fb7e2000-fb7e2fff : reserved
  fb7e3000-fb7e3fff : reserved
  fb7e4000-fb7f4fff : reserved
  fb7f5000-fb7f5fff : reserved
  fb7f6000-fbffffff : reserved
fd500000-fd50930f : fd500000.pcie pcie@7d500000
fd580000-fd58ffff : fd580000.ethernet ethernet@7d580000
  fd580e14-fd580e1c : unimac-mdio.-19
fe004000-fe00401f : fe004000.txp txp@7e004000
fe007000-fe007aff : fe007000.dma-controller dma-controller@7e007000
fe007b00-fe007eff : fe007b00.dma dma@7e007b00
fe00a000-fe00a023 : fe100000.watchdog asb
fe00b840-fe00b87b : fe00b840.mailbox mailbox@7e00b840
fe00b880-fe00b8bf : fe00b880.mailbox mailbox@7e00b880
fe100000-fe100113 : fe100000.watchdog pm
fe101000-fe102fff : fe101000.cprman cprman@7e101000
fe104000-fe104027 : fe104000.rng rng@7e104000
fe200000-fe2000b3 : fe200000.gpio gpio@7e200000
fe201000-fe2011ff : serial@7e201000
  fe201000-fe2011ff : fe201000.serial serial@7e201000
fe205000-fe2051ff : fe205000.i2c i2c@7e205000
fe206000-fe2060ff : fe206000.pixelvalve pixelvalve@7e206000
fe207000-fe2070ff : fe207000.pixelvalve pixelvalve@7e207000
fe20a000-fe20a0ff : fe20a000.pixelvalve pixelvalve@7e20a000
fe215000-fe215007 : fe215000.aux aux@7e215000
fe216000-fe2160ff : fe216000.pixelvalve pixelvalve@7e216000
fe300000-fe3000ff : fe300000.mmcnr mmcnr@7e300000
fe340000-fe3400ff : fe340000.mmc mmc@7e340000
fe400000-fe407fff : fe400000.hvs hvs@7e400000
fe801000-fe8017ff : fe801000.csi csi@7e801000
fe802004-fe802007 : fe801000.csi csi@7e801000
fe804000-fe804fff : fe804000.i2c i2c@7e804000
fec00000-fec03fff : fec00000.v3d hub
fec04000-fec07fff : fec00000.v3d core0
fec11000-fec1101f : fe100000.watchdog rpivid_asb
fec12000-fec120ff : fec12000.pixelvalve pixelvalve@7ec12000
fef00000-fef0000f : fef00000.clock clock@7ef00000
fef00b00-fef00dff : fef04500.i2c auto-i2c
fef04500-fef045ff : fef04500.i2c bsc
fef05b00-fef05dff : fef09500.i2c auto-i2c
fef09500-fef095ff : fef09500.i2c bsc
600000000-67fffffff : pcie@7d500000
  600000000-6000fffff : PCI Bus 0000:01
    600000000-600000fff : 0000:01:00.0
      600000000-600000fff : xhci-hcd

##  cat /proc/mounts 
 sysfs /sys sysfs rw,nosuid,nodev,noexec,relatime 0 0
proc /proc proc rw,relatime 0 0
udev /dev devtmpfs rw,nosuid,relatime,size=1668756k,nr_inodes=417189,mode=755 0 0
devpts /dev/pts devpts rw,nosuid,noexec,relatime,gid=5,mode=620,ptmxmode=000 0 0
tmpfs /run tmpfs rw,nosuid,nodev,noexec,relatime,size=388300k,mode=755 0 0
/dev/mmcblk0p2 / ext4 rw,noatime 0 0
securityfs /sys/kernel/security securityfs rw,nosuid,nodev,noexec,relatime 0 0
tmpfs /dev/shm tmpfs rw,nosuid,nodev 0 0
tmpfs /run/lock tmpfs rw,nosuid,nodev,noexec,relatime,size=5120k 0 0
cgroup2 /sys/fs/cgroup cgroup2 rw,nosuid,nodev,noexec,relatime,nsdelegate,memory_recursiveprot 0 0
pstore /sys/fs/pstore pstore rw,nosuid,nodev,noexec,relatime 0 0
bpf /sys/fs/bpf bpf rw,nosuid,nodev,noexec,relatime,mode=700 0 0
systemd-1 /proc/sys/fs/binfmt_misc autofs rw,relatime,fd=29,pgrp=1,timeout=0,minproto=5,maxproto=5,direct,pipe_ino=4756 0 0
mqueue /dev/mqueue mqueue rw,nosuid,nodev,noexec,relatime 0 0
debugfs /sys/kernel/debug debugfs rw,nosuid,nodev,noexec,relatime 0 0
tracefs /sys/kernel/tracing tracefs rw,nosuid,nodev,noexec,relatime 0 0
configfs /sys/kernel/config configfs rw,nosuid,nodev,noexec,relatime 0 0
fusectl /sys/fs/fuse/connections fusectl rw,nosuid,nodev,noexec,relatime 0 0
ramfs /run/credentials/systemd-sysusers.service ramfs ro,nosuid,nodev,noexec,relatime,mode=700 0 0
ramfs /run/credentials/systemd-sysctl.service ramfs ro,nosuid,nodev,noexec,relatime,mode=700 0 0
ramfs /run/credentials/systemd-tmpfiles-setup-dev.service ramfs ro,nosuid,nodev,noexec,relatime,mode=700 0 0
/dev/mmcblk0p1 /boot/firmware vfat rw,relatime,fmask=0022,dmask=0022,codepage=437,iocharset=ascii,shortname=mixed,errors=remount-ro 0 0
ramfs /run/credentials/systemd-tmpfiles-setup.service ramfs ro,nosuid,nodev,noexec,relatime,mode=700 0 0
sunrpc /run/rpc_pipefs rpc_pipefs rw,relatime 0 0
binfmt_misc /proc/sys/fs/binfmt_misc binfmt_misc rw,nosuid,nodev,noexec,relatime 0 0
tmpfs /run/user/1000 tmpfs rw,nosuid,nodev,relatime,size=388296k,nr_inodes=97074,mode=700,uid=1000,gid=1000 0 0
gvfsd-fuse /run/user/1000/gvfs fuse.gvfsd-fuse rw,nosuid,nodev,relatime,user_id=1000,group_id=1000 0 0
portal /run/user/1000/doc fuse.portal rw,nosuid,nodev,relatime,user_id=1000,group_id=1000 0 0

##  cat /proc/interrupts 
            CPU0       CPU1       CPU2       CPU3       
  9:          0          0          0          0     GICv2  25 Level     vgic
 11:     320323     316857     392155     252908     GICv2  30 Level     arch_timer
 12:          0          0          0          0     GICv2  27 Level     kvm guest vtimer
 14:     437410          0          0          0     GICv2  65 Level     fe00b880.mailbox
 15:      49535          0          0          0     GICv2 114 Level     DMA IRQ
 21:          0          0          0          0     GICv2 122 Level     DMA IRQ
 22:       3693          0          0          0     GICv2 123 Level     DMA IRQ
 27:          0          0          0          0     GICv2 175 Level     PCIe PME, aerdrv
 28:      14132          0          0          0     GICv2 189 Level     eth0
 29:          0          0          0          0     GICv2 190 Level     eth0
 30:      34078          0          0          0  BRCM STB PCIe MSI 524288 Edge      xhci_hcd
 31:        280          0          0          0     GICv2  66 Level     VCHIQ doorbell
 32:          0          0          0          0     GICv2  48 Level     arm-pmu
 33:          0          0          0          0     GICv2  49 Level     arm-pmu
 34:          0          0          0          0     GICv2  50 Level     arm-pmu
 35:          0          0          0          0     GICv2  51 Level     arm-pmu
 36:       7163          0          0          0     GICv2 153 Level     uart-pl011
 37:     722574          0          0          0     GICv2 158 Level     mmc1, mmc0
 38:       1374          0          0          0     GICv2 149 Level     fe205000.i2c, fe804000.i2c
 39:      84088          0          0          0     GICv2 106 Level     v3d
 40:      57042          0          0          0     GICv2 129 Level     vc4 hvs
 41:          0          0          0          0  interrupt-controller@7ef00100   4 Level     vc4 hdmi hpd connected
 42:          0          0          0          0  interrupt-controller@7ef00100   5 Level     vc4 hdmi hpd disconnected
 43:          0          0          0          0  interrupt-controller@7ef00100   1 Level     vc4 hdmi cec rx
 44:          0          0          0          0  interrupt-controller@7ef00100   0 Level     vc4 hdmi cec tx
 45:          0          0          0          0  interrupt-controller@7ef00100  10 Level     vc4 hdmi hpd connected
 46:          0          0          0          0  interrupt-controller@7ef00100  11 Level     vc4 hdmi hpd disconnected
 47:          0          0          0          0  interrupt-controller@7ef00100   7 Level     vc4 hdmi cec rx
 48:          0          0          0          0  interrupt-controller@7ef00100   8 Level     vc4 hdmi cec tx
 49:          0          0          0          0     GICv2 107 Level     fe004000.txp
 50:          0          0          0          0     GICv2 141 Level     vc4 crtc
 51:      52263          0          0          0     GICv2 142 Level     vc4 crtc, vc4 crtc
 52:          0          0          0          0     GICv2 133 Level     vc4 crtc
 53:          0          0          0          0     GICv2 138 Level     vc4 crtc
 54:          0          0          0          0     GICv2 135 Level     unicam_capture0
 55:          0          0          0          0     GICv2 130 Level     feb10000.codec
IPI0:      1837       2580       2662       2626       Rescheduling interrupts
IPI1:    138261     353735     425067     295127       Function call interrupts
IPI2:         0          0          0          0       CPU stop interrupts
IPI3:         0          0          0          0       CPU stop (for crash dump) interrupts
IPI4:         0          0          0          0       Timer broadcast interrupts
IPI5:      2515       2320       2940       1908       IRQ work interrupts
IPI6:         0          0          0          0       CPU wake-up interrupts
Err:          0

##  cat /proc/devices 
 Character devices:
  1 mem
  4 /dev/vc/0
  4 tty
  5 /dev/tty
  5 /dev/console
  5 /dev/ptmx
  5 ttyprintk
  7 vcs
 10 misc
 13 input
 14 sound
 29 fb
 81 video4linux
 89 i2c
116 alsa
128 ptm
136 pts
180 usb
189 usb_device
204 ttyAMA
216 rfcomm
226 drm
237 media
238 gpiomem
239 uio
240 cec
241 binder
242 hidraw
243 rpmb
244 nvme-generic
245 nvme
246 vc-mem
247 bsg
248 watchdog
249 ptp
250 pps
251 lirc
252 rtc
253 dma_heap
254 gpiochip

Block devices:
  1 ramdisk
  7 loop
  8 sd
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
254 device-mapper
259 blkext

##  cat /proc/sys/kernel/printk 
 3	4	1	3

 #  ===================== 其他 =====================

##  ls -al /dev/ 
 total 4
drwxr-xr-x  16 root root      4160 Feb  5 22:36 .
drwxr-xr-x  18 root root      4096 Nov 19  2024 ..
crw-r--r--   1 root root   10, 235 Feb  5 22:35 autofs
drwxr-xr-x   2 root root       580 Feb  5 22:35 block
crw-------   1 root root   10, 234 Feb  5 22:35 btrfs-control
drwxr-xr-x   3 root root        60 Jan  1  1970 bus
crw-------   1 root root   10, 126 Feb  5 22:35 cachefiles
crw-rw----   1 root video 240,   0 Feb  5 22:35 cec0
crw-rw----   1 root video 240,   1 Feb  5 22:35 cec1
drwxr-xr-x   2 root root      3600 Feb  5 22:36 char
crw--w----   1 root tty     5,   1 Feb  5 22:35 console
crw-------   1 root root   10, 123 Feb  5 22:35 cpu_dma_latency
crw-------   1 root root   10, 203 Feb  5 22:35 cuse
drwxr-xr-x   8 root root       160 Jan  1  1970 disk
drwxr-xr-x   2 root root       100 Feb  5 22:35 dma_heap
drwxr-xr-x   3 root root       120 Feb  5 22:35 dri
crw-rw----   1 root video  29,   0 Feb  5 22:35 fb0
lrwxrwxrwx   1 root root        13 Jan  1  1970 fd -> /proc/self/fd
crw-rw-rw-   1 root root    1,   7 Feb  5 22:35 full
crw-rw-rw-   1 root root   10, 229 Feb  5 22:35 fuse
crw-rw----+  1 root gpio  254,   0 Feb  5 22:35 gpiochip0
crw-rw----+  1 root gpio  254,   1 Feb  5 22:35 gpiochip1
lrwxrwxrwx   1 root root         9 Feb  5 22:35 gpiochip4 -> gpiochip0
crw-rw----   1 root gpio  238,   0 Feb  5 22:35 gpiomem
crw-------   1 root root  242,   0 Feb  5 22:35 hidraw0
crw-------   1 root root  242,   1 Feb  5 22:35 hidraw1
crw-------   1 root root   10, 183 Feb  5 22:35 hwrng
crw-rw----   1 root i2c    89,   0 Feb  5 22:35 i2c-0
crw-rw----   1 root i2c    89,   1 Feb  5 22:35 i2c-1
crw-rw----   1 root i2c    89,  10 Feb  5 22:35 i2c-10
crw-rw----   1 root i2c    89,  20 Feb  5 22:35 i2c-20
crw-rw----   1 root i2c    89,  21 Feb  5 22:35 i2c-21
crw-rw----   1 root i2c    89,  22 Feb  5 22:35 i2c-22
lrwxrwxrwx   1 root root        12 Nov 13  2024 initctl -> /run/initctl
drwxr-xr-x   4 root root       280 Feb  5 22:35 input
crw-r--r--   1 root root    1,  11 Feb  5 22:35 kmsg
crw-rw----+  1 root kvm    10, 232 Feb  5 22:35 kvm
lrwxrwxrwx   1 root root        28 Nov 13  2024 log -> /run/systemd/journal/dev-log
brw-rw----   1 root disk    7,   0 Feb  5 22:35 loop0
brw-rw----   1 root disk    7,   1 Feb  5 22:35 loop1
brw-rw----   1 root disk    7,   2 Feb  5 22:35 loop2
brw-rw----   1 root disk    7,   3 Feb  5 22:35 loop3
brw-rw----   1 root disk    7,   4 Feb  5 22:35 loop4
brw-rw----   1 root disk    7,   5 Feb  5 22:35 loop5
brw-rw----   1 root disk    7,   6 Feb  5 22:35 loop6
brw-rw----   1 root disk    7,   7 Feb  5 22:35 loop7
crw-rw----   1 root disk   10, 237 Feb  5 22:35 loop-control
drwxr-xr-x   2 root root        60 Nov 13  2024 mapper
crw-rw----+  1 root video 237,   0 Feb  5 22:35 media0
crw-rw----+  1 root video 237,   1 Feb  5 22:35 media1
crw-rw----+  1 root video 237,   2 Feb  5 22:35 media2
crw-rw----+  1 root video 237,   3 Feb  5 22:35 media3
crw-rw----+  1 root video 237,   4 Feb  5 22:35 media4
crw-r-----   1 root kmem    1,   1 Feb  5 22:35 mem
brw-rw----   1 root disk  179,   0 Feb  5 22:35 mmcblk0
brw-rw----   1 root disk  179,   1 Feb  5 22:35 mmcblk0p1
brw-rw----   1 root disk  179,   2 Feb  5 22:35 mmcblk0p2
drwxrwxrwt   2 root root        40 Jan  1  1970 mqueue
drwxr-xr-x   2 root root        60 Feb  5 22:35 net
crw-rw-rw-   1 root root    1,   3 Feb  5 22:35 null
crw-r-----   1 root kmem    1,   4 Feb  5 22:35 port
crw-------   1 root root  108,   0 Feb  5 22:35 ppp
crw-rw-rw-   1 root tty     5,   2 Jul 13 20:29 ptmx
drwxr-xr-x   2 root root         0 Jan  1  1970 pts
brw-rw----   1 root disk    1,   0 Feb  5 22:35 ram0
brw-rw----   1 root disk    1,   1 Feb  5 22:35 ram1
brw-rw----   1 root disk    1,  10 Feb  5 22:35 ram10
brw-rw----   1 root disk    1,  11 Feb  5 22:35 ram11
brw-rw----   1 root disk    1,  12 Feb  5 22:35 ram12
brw-rw----   1 root disk    1,  13 Feb  5 22:35 ram13
brw-rw----   1 root disk    1,  14 Feb  5 22:35 ram14
brw-rw----   1 root disk    1,  15 Feb  5 22:35 ram15
brw-rw----   1 root disk    1,   2 Feb  5 22:35 ram2
brw-rw----   1 root disk    1,   3 Feb  5 22:35 ram3
brw-rw----   1 root disk    1,   4 Feb  5 22:35 ram4
brw-rw----   1 root disk    1,   5 Feb  5 22:35 ram5
brw-rw----   1 root disk    1,   6 Feb  5 22:35 ram6
brw-rw----   1 root disk    1,   7 Feb  5 22:35 ram7
brw-rw----   1 root disk    1,   8 Feb  5 22:35 ram8
brw-rw----   1 root disk    1,   9 Feb  5 22:35 ram9
crw-rw-rw-   1 root root    1,   8 Feb  5 22:35 random
crw-rw-r--+  1 root root   10, 242 Feb  5 22:35 rfkill
drwxrwxrwt   2 root root        80 Jul 13 20:21 shm
drwxr-xr-x   3 root root       220 Feb  5 22:35 snd
lrwxrwxrwx   1 root root        15 Jan  1  1970 stderr -> /proc/self/fd/2
lrwxrwxrwx   1 root root        15 Jan  1  1970 stdin -> /proc/self/fd/0
lrwxrwxrwx   1 root root        15 Jan  1  1970 stdout -> /proc/self/fd/1
crw-rw-rw-   1 root tty     5,   0 Jul 13  2025 tty
crw--w----   1 root tty     4,   0 Feb  5 22:35 tty0
crw-------   1 nisy tty     4,   1 Feb  5 22:36 tty1
crw--w----   1 root tty     4,  10 Feb  5 22:35 tty10
crw--w----   1 root tty     4,  11 Feb  5 22:35 tty11
crw--w----   1 root tty     4,  12 Feb  5 22:35 tty12
crw--w----   1 root tty     4,  13 Feb  5 22:35 tty13
crw--w----   1 root tty     4,  14 Feb  5 22:35 tty14
crw--w----   1 root tty     4,  15 Feb  5 22:35 tty15
crw--w----   1 root tty     4,  16 Feb  5 22:35 tty16
crw--w----   1 root tty     4,  17 Feb  5 22:35 tty17
crw--w----   1 root tty     4,  18 Feb  5 22:35 tty18
crw--w----   1 root tty     4,  19 Feb  5 22:35 tty19
crw--w----   1 root tty     4,   2 Feb  5 22:35 tty2
crw--w----   1 root tty     4,  20 Feb  5 22:35 tty20
crw--w----   1 root tty     4,  21 Feb  5 22:35 tty21
crw--w----   1 root tty     4,  22 Feb  5 22:35 tty22
crw--w----   1 root tty     4,  23 Feb  5 22:35 tty23
crw--w----   1 root tty     4,  24 Feb  5 22:35 tty24
crw--w----   1 root tty     4,  25 Feb  5 22:35 tty25
crw--w----   1 root tty     4,  26 Feb  5 22:35 tty26
crw--w----   1 root tty     4,  27 Feb  5 22:35 tty27
crw--w----   1 root tty     4,  28 Feb  5 22:35 tty28
crw--w----   1 root tty     4,  29 Feb  5 22:35 tty29
crw--w----   1 root tty     4,   3 Feb  5 22:35 tty3
crw--w----   1 root tty     4,  30 Feb  5 22:35 tty30
crw--w----   1 root tty     4,  31 Feb  5 22:35 tty31
crw--w----   1 root tty     4,  32 Feb  5 22:35 tty32
crw--w----   1 root tty     4,  33 Feb  5 22:35 tty33
crw--w----   1 root tty     4,  34 Feb  5 22:35 tty34
crw--w----   1 root tty     4,  35 Feb  5 22:35 tty35
crw--w----   1 root tty     4,  36 Feb  5 22:35 tty36
crw--w----   1 root tty     4,  37 Feb  5 22:35 tty37
crw--w----   1 root tty     4,  38 Feb  5 22:35 tty38
crw--w----   1 root tty     4,  39 Feb  5 22:35 tty39
crw--w----   1 root tty     4,   4 Feb  5 22:35 tty4
crw--w----   1 root tty     4,  40 Feb  5 22:35 tty40
crw--w----   1 root tty     4,  41 Feb  5 22:35 tty41
crw--w----   1 root tty     4,  42 Feb  5 22:35 tty42
crw--w----   1 root tty     4,  43 Feb  5 22:35 tty43
crw--w----   1 root tty     4,  44 Feb  5 22:35 tty44
crw--w----   1 root tty     4,  45 Feb  5 22:35 tty45
crw--w----   1 root tty     4,  46 Feb  5 22:35 tty46
crw--w----   1 root tty     4,  47 Feb  5 22:35 tty47
crw--w----   1 root tty     4,  48 Feb  5 22:35 tty48
crw--w----   1 root tty     4,  49 Feb  5 22:35 tty49
crw--w----   1 root tty     4,   5 Feb  5 22:35 tty5
crw--w----   1 root tty     4,  50 Feb  5 22:35 tty50
crw--w----   1 root tty     4,  51 Feb  5 22:35 tty51
crw--w----   1 root tty     4,  52 Feb  5 22:35 tty52
crw--w----   1 root tty     4,  53 Feb  5 22:35 tty53
crw--w----   1 root tty     4,  54 Feb  5 22:35 tty54
crw--w----   1 root tty     4,  55 Feb  5 22:35 tty55
crw--w----   1 root tty     4,  56 Feb  5 22:35 tty56
crw--w----   1 root tty     4,  57 Feb  5 22:35 tty57
crw--w----   1 root tty     4,  58 Feb  5 22:35 tty58
crw--w----   1 root tty     4,  59 Feb  5 22:35 tty59
crw--w----   1 root tty     4,   6 Feb  5 22:35 tty6
crw--w----   1 root tty     4,  60 Feb  5 22:35 tty60
crw--w----   1 root tty     4,  61 Feb  5 22:35 tty61
crw--w----   1 root tty     4,  62 Feb  5 22:35 tty62
crw--w----   1 root tty     4,  63 Feb  5 22:35 tty63
crw--w----   1 nisy tty     4,   7 Feb  5 22:36 tty7
crw--w----   1 root tty     4,   8 Feb  5 22:35 tty8
crw--w----   1 root tty     4,   9 Feb  5 22:35 tty9
crw-------   1 root root    5,   3 Feb  5 22:35 ttyprintk
crw-------   1 root root   10, 239 Feb  5 22:35 uhid
crw-------   1 root root   10, 223 Feb  5 22:35 uinput
crw-rw-rw-   1 root root    1,   9 Feb  5 22:35 urandom
drwxr-xr-x   3 root root        60 Feb  5 22:35 v4l
crw-rw----+  1 root video  81,   2 Feb  5 22:35 v4l-subdev0
crw-rw----   1 root video  10, 124 Feb  5 22:35 vchiq
crw-rw----   1 root video  10, 125 Feb  5 22:35 vcio
crw-------   1 root root  246,   0 Feb  5 22:35 vc-mem
crw-rw----   1 root tty     7,   0 Feb  5 22:35 vcs
crw-rw----   1 root tty     7,   1 Feb  5 22:35 vcs1
crw-rw----   1 root tty     7,   2 Feb  5 22:35 vcs2
crw-rw----   1 root tty     7,   3 Feb  5 22:35 vcs3
crw-rw----   1 root tty     7,   4 Feb  5 22:35 vcs4
crw-rw----   1 root tty     7,   5 Feb  5 22:35 vcs5
crw-rw----   1 root tty     7,   6 Feb  5 22:35 vcs6
crw-rw----   1 root tty     7,   7 Feb  5 22:36 vcs7
crw-rw----   1 root tty     7, 128 Feb  5 22:35 vcsa
crw-rw----   1 root tty     7, 129 Feb  5 22:35 vcsa1
crw-rw----   1 root tty     7, 130 Feb  5 22:35 vcsa2
crw-rw----   1 root tty     7, 131 Feb  5 22:35 vcsa3
crw-rw----   1 root tty     7, 132 Feb  5 22:35 vcsa4
crw-rw----   1 root tty     7, 133 Feb  5 22:35 vcsa5
crw-rw----   1 root tty     7, 134 Feb  5 22:35 vcsa6
crw-rw----   1 root tty     7, 135 Feb  5 22:36 vcsa7
crw-rw----   1 root video  10, 122 Feb  5 22:35 vcsm-cma
crw-rw----   1 root tty     7,  64 Feb  5 22:35 vcsu
crw-rw----   1 root tty     7,  65 Feb  5 22:35 vcsu1
crw-rw----   1 root tty     7,  66 Feb  5 22:35 vcsu2
crw-rw----   1 root tty     7,  67 Feb  5 22:35 vcsu3
crw-rw----   1 root tty     7,  68 Feb  5 22:35 vcsu4
crw-rw----   1 root tty     7,  69 Feb  5 22:35 vcsu5
crw-rw----   1 root tty     7,  70 Feb  5 22:35 vcsu6
crw-rw----   1 root tty     7,  71 Feb  5 22:36 vcsu7
crw-------   1 root root   10, 127 Feb  5 22:35 vga_arbiter
crw-------   1 root root   10, 137 Feb  5 22:35 vhci
crw-rw----   1 root kvm    10, 238 Feb  5 22:35 vhost-net
crw-rw----   1 root kvm    10, 241 Feb  5 22:35 vhost-vsock
crw-rw----+  1 root video  81,   1 Feb  5 22:35 video0
crw-rw----+  1 root video  81,  10 Feb  5 22:35 video10
crw-rw----+  1 root video  81,  11 Feb  5 22:35 video11
crw-rw----+  1 root video  81,  12 Feb  5 22:35 video12
crw-rw----+  1 root video  81,   0 Feb  5 22:35 video13
crw-rw----+  1 root video  81,   3 Feb  5 22:35 video14
crw-rw----+  1 root video  81,   4 Feb  5 22:35 video15
crw-rw----+  1 root video  81,   5 Feb  5 22:35 video16
crw-rw----+  1 root video  81,  13 Feb  5 22:35 video18
crw-rw----+  1 root video  81,  15 Feb  5 22:35 video19
crw-rw----+  1 root video  81,   6 Feb  5 22:35 video20
crw-rw----+  1 root video  81,   7 Feb  5 22:35 video21
crw-rw----+  1 root video  81,   8 Feb  5 22:35 video22
crw-rw----+  1 root video  81,   9 Feb  5 22:35 video23
crw-rw----+  1 root video  81,  14 Feb  5 22:35 video31
crw-------   1 root root   10, 130 Feb  5 22:35 watchdog
crw-------   1 root root  248,   0 Feb  5 22:35 watchdog0
crw-rw-rw-   1 root root    1,   5 Feb  5 22:35 zero

##  ls -al /dev/block/by-name/ 
 
