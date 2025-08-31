#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    int message_count = 0;
    
    // 创建socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    // 将IPv4地址从文本转换为二进制形式
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    
    // 连接到服务器
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    
    printf("Connected to server. Sending messages every second...\n");
    
    // 每秒发送一条消息
    while (1) {
        message_count++;
        snprintf(buffer, sizeof(buffer), "Message %d from client", message_count);
        send(sock, buffer, strlen(buffer), 0);
        printf("Sent: %s\n", buffer);
        memset(buffer, 0, sizeof(buffer)); // 清空缓冲区
        sleep(1); // 等待1秒
    }
    
    close(sock);
    return 0;
}
