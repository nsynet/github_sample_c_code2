#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define SERVER_IP "127.0.0.1"
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    
    // 创建socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    // 将IP地址从字符串转换为二进制形式
    if (inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    
    // 连接到服务器
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    
    printf("Connected to server. Sending accumulated values (1,2,3)...\n");
    
    // 发送累加的数据值
    int values[] = {1, 2, 3};
    for (int i = 0; i < 3; i++) {
        snprintf(buffer, BUFFER_SIZE, "%d", values[i]);
        send(sock, buffer, strlen(buffer), 0);
        printf("Sent: %d\n", values[i]);
        sleep(1); // 等待1秒，模拟数据处理时间
        memset(buffer, 0, BUFFER_SIZE); // 清空缓冲区
    }
    
    printf("All values sent. Closing connection.\n");
    close(sock);
    
    return 0;
}
