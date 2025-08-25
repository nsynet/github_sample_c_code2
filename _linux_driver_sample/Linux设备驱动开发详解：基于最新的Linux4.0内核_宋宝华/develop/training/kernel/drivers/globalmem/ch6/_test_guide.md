# install ko

```
sudo insmod globalmem_nisy.ko
```


# sysfs

```
rlk@rlk:/sys$ sudo find . -iname "*globalmem*"
[sudo] password for rlk: 
./class/globalmem_class
./class/globalmem_class/globalmem
./devices/virtual/globalmem_class
./devices/virtual/globalmem_class/globalmem
./module/globalmem_nisy
./module/globalmem_nisy/parameters/globalmem_major
rlk@rlk:/sys$ ls -al /sys/class/globalmem_class/globalmem
lrwxrwxrwx 1 root root 0 8月  26 00:25 /sys/class/globalmem_class/globalmem -> ../../devices/virtual/globalmem_class/globalmem
rlk@rlk:/sys$ 
rlk@rlk:/sys$ tree  /sys/module/globalmem_nisy/
/sys/module/globalmem_nisy/
├── coresize
├── holders
├── initsize
├── initstate
├── notes
├── parameters
│   └── globalmem_major
├── refcnt
├── sections
│   ├── __bug_table
│   ├── __mcount_loc
│   └── __param
├── srcversion
├── taint
└── uevent

4 directories, 11 files
rlk@rlk:/sys$ cat   /sys/module/globalmem_nisy/parameters/globalmem_major 
236
rlk@rlk:/sys$ 

```


# devfs

```
rlk@rlk:/dev$ ls -al *global* 
crw-rw-rw- 1 root root 236, 0 8月  26 00:24 globalmem
rlk@rlk:/dev$ echo "hello world" >  /dev/globalmem 
rlk@rlk:/dev$ cat   /dev/globalmem 
hello world
rlk@rlk:/dev$ 
```

# dmesg 打印

```
[ 2325.396882] succeeded register char device: my_demo_dev
[ 2325.396890] Major number = 237, minor number = 0
[ 6287.575188] read 4096 bytes(s) from 0
[ 6290.295371] read 4096 bytes(s) from 0
[ 7164.170752] written 12 bytes(s) from 0
[ 7169.164999] read 4096 bytes(s) from 0
rlk@rlk:/sys$ 
```