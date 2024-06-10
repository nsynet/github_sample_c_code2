在这个例子中，客户端每秒向服务器发送一次消息，而服务器则不断地接收并打印这些消息。你可以根据需要调整发送频率或消息内容。


发送端：
```
nisy@raspberrypi:~/_git/github_sample_c_code2/_python_sample/_socket的 client不断发送,server端不断接收的例子 $ python ./_client.py 
已发送消息: Hello, Server!
已发送消息: Hello, Server!
...
```

接收端：
```
nisy@raspberrypi:~/_git/github_sample_c_code2/_python_sample/_socket的 client不断发送,server端不断接收的例子 $ python ./_server.py 
连接地址: ('127.0.0.1', 46314)
收到消息: Hello, Server!
收到消息: Hello, Server!
收到消息: Hello, Server!
...
```

查到2者的进程号为3101和3098：
```
nisy@raspberrypi:~ $ ps -ef|grep python
nisy       934     1  0 10:33 ?        00:00:01 /usr/bin/python3 /usr/share/system-config-printer/applet.py
nisy      3098  2374  0 12:03 pts/0    00:00:00 python ./_server.py
nisy      3101  2226  0 12:03 pts/1    00:00:00 python ./_client.py
nisy      3114  2622  0 12:04 pts/3    00:00:00 grep --color=auto python

```

查到发送进程的 3101进程的端口号是43244：
```
nisy@raspberrypi:~ $ lsof -p 3101
COMMAND  PID USER   FD   TYPE DEVICE SIZE/OFF   NODE NAME
python  3101 nisy  cwd    DIR 179,10     4096 424225 /home/nisy/_git/github_sample_c_code2/_python_sample/_socket的 client不断发送,server端不断接收的例子
python  3101 nisy  rtd    DIR 179,10     4096      2 /
python  3101 nisy  txt    REG 179,10  4703672 269952 /usr/bin/python3.9
python  3101 nisy  mem    REG 179,10    42628 407594 /usr/lib/arm-linux-gnueabihf/libnss_files-2.31.so
python  3101 nisy  mem    REG 179,10  3041456 656759 /usr/lib/locale/locale-archive
python  3101 nisy  mem    REG 179,10   116324 407824 /usr/lib/arm-linux-gnueabihf/libgcc_s.so.1
python  3101 nisy  mem    REG 179,10  1319784 407596 /usr/lib/arm-linux-gnueabihf/libc-2.31.so
python  3101 nisy  mem    REG 179,10    95880 406580 /usr/lib/arm-linux-gnueabihf/libz.so.1.2.11
python  3101 nisy  mem    REG 179,10   144944 407273 /usr/lib/arm-linux-gnueabihf/libexpat.so.1.6.12
python  3101 nisy  mem    REG 179,10   386572 407138 /usr/lib/arm-linux-gnueabihf/libm-2.31.so
python  3101 nisy  mem    REG 179,10     9796 407495 /usr/lib/arm-linux-gnueabihf/libutil-2.31.so
python  3101 nisy  mem    REG 179,10    13864 408136 /usr/lib/arm-linux-gnueabihf/libdl-2.31.so
python  3101 nisy  mem    REG 179,10   137364 408274 /usr/lib/arm-linux-gnueabihf/libpthread-2.31.so
python  3101 nisy  mem    REG 179,10    17708 408173 /usr/lib/arm-linux-gnueabihf/libarmmem-v7l.so
python  3101 nisy  mem    REG 179,10   146888 407867 /usr/lib/arm-linux-gnueabihf/ld-2.31.so
python  3101 nisy  mem    REG 179,10    27006 408906 /usr/lib/arm-linux-gnueabihf/gconv/gconv-modules.cache
python  3101 nisy    0u   CHR  136,1      0t0      4 /dev/pts/1
python  3101 nisy    1u   CHR  136,1      0t0      4 /dev/pts/1
python  3101 nisy    2u   CHR  136,1      0t0      4 /dev/pts/1
python  3101 nisy    3u  IPv4  52263      0t0    TCP localhost:43244->raspberrypi:9999 (ESTABLISHED)
```lsof -p <进程PID>

strace查看发送进程在不断发送：
```
nisy@raspberrypi:~ $ strace -p  3101
strace: Process 3101 attached
_newselect(0, NULL, NULL, NULL, {tv_sec=0, tv_usec=298859}) = 0 (Timeout)
send(3, "Hello, Server!", 14, 0)        = 14
write(1, "\345\267\262\345\217\221\351\200\201\346\266\210\346\201\257: Hello, Server!\n", 32) = 32
clock_gettime64(CLOCK_MONOTONIC, {tv_sec=6376, tv_nsec=200169999}) = 0
_newselect(0, NULL, NULL, NULL, {tv_sec=1, tv_usec=0}) = 0 (Timeout)
send(3, "Hello, Server!", 14, 0)        = 14
write(1, "\345\267\262\345\217\221\351\200\201\346\266\210\346\201\257: Hello, Server!\n", 32) = 32
clock_gettime64(CLOCK_MONOTONIC, {tv_sec=6377, tv_nsec=202056932}) = 0
_newselect(0, NULL, NULL, NULL, {tv_sec=1, tv_usec=0}) = 0 (Timeout)
send(3, "Hello, Server!", 14, 0)        = 14
write(1, "\345\267\262\345\217\221\351\200\201\346\266\210\346\201\257: Hello, Server!\n", 32) = 32
clock_gettime64(CLOCK_MONOTONIC, {tv_sec=6378, tv_nsec=203955687}) = 0
_newselect(0, NULL, NULL, NULL, {tv_sec=1, tv_usec=0}) = 0 (Timeout)
send(3, "Hello, Server!", 14, 0)        = 14
......
```

ss 查到发送和接收进程：
```
nisy@raspberrypi:~ $ ss |grep 43244
tcp   ESTAB    0      0                                  127.0.0.1:43244       127.0.1.1:9999        
tcp   ESTAB    0      0                                  127.0.1.1:9999        127.0.0.1:43244       
```

类似地用 `sudo netstat -tuanp`  也能看到发送和接收进程.

