#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/ipc.h>

#define SHM_SIZE 1024

// 信号量P/V操作
void P(int semid) {
  struct sembuf op = {0, -1, SEM_UNDO};
  semop(semid, &op, 1);
}

void V(int semid) {
  struct sembuf op = {0, 1, SEM_UNDO};
  semop(semid, &op, 1);
}

int main() {
  // 创建共享内存和信号量
  key_t key = ftok("/tmp", 'a');
  int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
  int semid = semget(key, 1, IPC_CREAT | 0666);
  semctl(semid, 0, SETVAL, 1);  // 初始化信号量为1

  char *shm_ptr = (char*)shmat(shmid, NULL, 0);
  memset(shm_ptr, 0, SHM_SIZE);

  pid_t pid = fork();
  if (pid == 0) {  // 子进程B（接收端）
    while (1) {
      P(semid);
      if (strlen(shm_ptr) > 0) {
        printf("B Received: %s\n", shm_ptr);
        memset(shm_ptr, 0, SHM_SIZE);  // 清空缓冲区
      }
      V(semid);
      sleep(1);
    }
  } else {  // 父进程A（发送端）
    int count = 0;
    while (1) {
      P(semid);
      snprintf(shm_ptr, SHM_SIZE, "Message %d from A", ++count);
      V(semid);
      sleep(2);
    }
    //wait(NULL);
  }
  shmdt(shm_ptr);
  shmctl(shmid, IPC_RMID, NULL);
  semctl(semid, 0, IPC_RMID);
  return 0;
}
