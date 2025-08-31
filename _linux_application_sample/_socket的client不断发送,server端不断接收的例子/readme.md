# Linux下C语言的Socket通信示例

# Linux下C语言的Socket通信示例

下面是一个简单的Linux下C语言的Socket通信示例，包含客户端和服务器端代码。客户端每秒向服务器发送一次消息，服务器不断接收并打印这些消息。

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
    
    // 设置socket选项，允许地址和端口重用
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // 绑定socket到指定端口
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // 开始监听连接
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
    
    printf("Client connected. Waiting for messages...\n");
    
    // 持续接收并打印消息
    while (1) {
        int valread = read(new_socket, buffer, BUFFER_SIZE);
        if (valread > 0) {
            printf("Received: %s\n", buffer);
            memset(buffer, 0, BUFFER_SIZE); // 清空缓冲区
        } else if (valread == 0) {
            printf("Client disconnected.\n");
            break;
        } else {
            perror("read");
            break;
        }
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
```

## 编译和运行方法

1. 首先编译服务器端和客户端代码：

```bash
gcc server.c -o server
gcc client.c -o client
```

2. 在一个终端窗口中运行服务器：

```bash
./server
```

3. 在另一个终端窗口中运行客户端：

```bash
./client
```

## 程序说明

- 服务器监听8080端口，等待客户端连接
- 客户端连接到服务器的8080端口
- 客户端每秒发送一条消息到服务器
- 服务器接收并打印所有来自客户端的消息
- 使用TCP协议保证可靠的数据传输

要终止程序，可以使用Ctrl+C。这个示例展示了基本的Socket编程概念，包括创建socket、绑定地址、监听连接、接受连接、发送和接收数据。