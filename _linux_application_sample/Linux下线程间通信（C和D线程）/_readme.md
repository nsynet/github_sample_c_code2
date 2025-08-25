
**编译运行：**
```bash
gcc thread_ipc.c -o thread_ipc -lpthread
./thread_ipc
```


2. **查看线程状态**：
  ```bash
  ps -T -p $(pgrep thread_ipc)
  ```
  输出示例：
  ```
  PID  SPID TTY   STAT  TIME COMMAND
  5678 5678 pts/0  Sl+  0:00 ./thread_ipc # 主线程（可能是C或D）
  5678 5679 pts/0  Sl+  0:00 ./thread_ipc # 线程C
  5678 5680 pts/0  Sl+  0:00 ./thread_ipc # 线程D
  ```
  - **`-T`**：显示线程（SPID=LWP ID）。
  - **STAT中的`l`**：表示是多线程进程。
  - **线程名**：默认与进程同名，可用`pthread_setname_np`设置。


### **关键状态说明**
| 状态 | 含义           | 常见场景        |
|------|--------------------------|-----------------------|
| `S` | 休眠（可中断）      | 等待I/O或锁      |
| `R` | 运行/可运行       | 正在执行或就绪    |
| `D` | 不可中断休眠       | 等待磁盘I/O      |
| `Z` | 僵尸进程         | 子进程已终止未回收  |
| `+` | 前台进程组        | 终端关联进程     |
| `l` | 多线程进程        | 线程示例中的主进程  |

通过`top -H -p <PID>`可实时查看线程CPU占用，其中：
- **进程间通信**：两个独立进程（不同PID）
- **线程间通信**：同一进程内（相同PID，不同SPID/LWP）