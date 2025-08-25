# 写一个linux下一个程序累加的数据值(1,2,3)发送socket  client 到另一个程序 socket server,socket server打印出接收的值

# Linux Socket 通信示例：客户端发送累加值，服务器接收并打印

下面是一个完整的示例，包含客户端和服务器端程序，使用TCP Socket进行通信。客户端会发送累加的数据值(1,2,3)，服务器接收并打印这些值。

## 服务器端代码 (server.c)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    
    // 创建socket文件描述符
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // 设置socket选项
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // 绑定socket到端口
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // 开始监听
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    printf("Server listening on port %d...\n", PORT);
    
    // 接受客户端连接
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    
    printf("Client connected. Waiting for data...\n");
    
    // 读取客户端发送的数据
    int valread;
    while ((valread = read(new_socket, buffer, BUFFER_SIZE)) > 0) {
        printf("Received from client: %s\n", buffer);
        memset(buffer, 0, BUFFER_SIZE); // 清空缓冲区
    }
    
    if (valread == 0) {
        printf("Client disconnected.\n");
    } else if (valread == -1) {
        perror("read");
    }
    
    close(new_socket);
    close(server_fd);
    
    return 0;
}
```

## 客户端代码 (client.c)

```c
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
```

## 编译和运行方法

1. 首先编译服务器端和客户端程序：

```bash
gcc server.c -o server
gcc client.c -o client
```

2. 在一个终端窗口中启动服务器：

```bash
./server
```

3. 在另一个终端窗口中启动客户端：

```bash
./client
```

## 预期输出

服务器端输出：
```
Server listening on port 8080...
Client connected. Waiting for data...
Received from client: 1
Received from client: 2
Received from client: 3
Client disconnected.
```

客户端输出：
```
Connected to server. Sending accumulated values (1,2,3)...
Sent: 1
Sent: 2
Sent: 3
All values sent. Closing connection.
```

## 扩展说明

1. 如果需要发送更复杂的数据结构，可以考虑使用JSON格式或自定义协议
2. 可以添加错误处理机制，使程序更加健壮
3. 对于生产环境，可能需要考虑多客户端连接的情况，可以使用多线程或select/poll/epoll等技术

这个示例展示了基本的Socket通信流程，您可以根据实际需求进行修改和扩展。
