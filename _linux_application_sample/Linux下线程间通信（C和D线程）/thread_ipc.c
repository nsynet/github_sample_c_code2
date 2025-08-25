#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

char buffer[BUFFER_SIZE];
int data_ready = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void* thread_C(void* arg) { // 发送线程
  int count = 0;
  while (1) {
    pthread_mutex_lock(&mutex);
    snprintf(buffer, BUFFER_SIZE, "Message %d from C", ++count);
    data_ready = 1;
    pthread_cond_signal(&cond); // 通知线程D
    pthread_mutex_unlock(&mutex);
    sleep(2);
  }
  return NULL;
}

void* thread_D(void* arg) { // 接收线程
  while (1) {
    pthread_mutex_lock(&mutex);
    while (!data_ready) {
      pthread_cond_wait(&cond, &mutex); // 等待信号
    }
    printf("D Received: %s\n", buffer);
    data_ready = 0;
    memset(buffer, 0, BUFFER_SIZE);
    pthread_mutex_unlock(&mutex);
  }
  return NULL;
}

int main() {
  pthread_t tid1, tid2;
  pthread_create(&tid1, NULL, thread_C, NULL);
  pthread_create(&tid2, NULL, thread_D, NULL);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  return 0;
}
