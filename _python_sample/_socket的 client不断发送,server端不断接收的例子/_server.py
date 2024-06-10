import socket  
  
def start_server():  
    # 创建 socket 对象  
    serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)   
  
    # 获取本地主机名  
    host = socket.gethostname()   
  
    # 设置端口号  
    port = 9999  
  
    # 绑定端口号  
    serversocket.bind((host, port))  
  
    # 设置最大连接数，超过后排队  
    serversocket.listen(5)   
  
    while True:  
        # 建立客户端连接  
        clientsocket,addr = serversocket.accept()        
  
        print("连接地址: %s" % str(addr))  
          
        while True:  
            data = clientsocket.recv(1024).decode()  
            if not data:  
                break  
            print('收到消息: ' + data)  
          
        # 关闭连接  
        clientsocket.close()  
  
if __name__ == '__main__':  
    start_server()
