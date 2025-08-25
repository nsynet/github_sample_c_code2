
### **1. 进程间通信（A ↔ B 进程）**

**编译运行：**
```bash
gcc shm_ipc.c -o shm_ipc
./shm_ipc
B Received: Message 1 from A
B Received: Message 2 from A
B Received: Message 3 from A
B Received: Message 4 from A
B Received: Message 5 from A
B Received: Message 6 from A
B Received: Message 7 from A
B Received: Message 8 from A
....
```
查看ps命令：
```
[nisy@nisy _linux_application_sample]$ ps -ef |grep shm
nisy        3144    2763  3 19:39 ?        00:00:10 /usr/bin/geany /run/media/nisy/win_program_D/_Tech/95_code/_my_github/github_sample_c_code2/_linux_application_sample/shm_ipc.c
nisy        3443    3165  0 19:43 pts/2    00:00:00 ./shm_ipc
nisy        3444    3443  0 19:43 pts/2    00:00:00 ./shm_ipc
nisy        3842    3222  0 19:43 pts/0    00:00:00 grep --colour=auto shm
[nisy@nisy _linux_application_sample]$ ps -ef |grep 3165
nisy        3165    2814  0 19:39 pts/2    00:00:00 bash
nisy        3443    3165  0 19:43 pts/2    00:00:00 ./shm_ipc
nisy        3862    3222  0 19:43 pts/0    00:00:00 grep --colour=auto 3165
[nisy@nisy _linux_application_sample]$ 

```

可以看到bash （3165）下产生的2个pid的进程。