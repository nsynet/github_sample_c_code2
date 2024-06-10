import socket  
import time  
  
def start_client():  
    # 创建 socket 对象  
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)   
  
    # 获取本地主机名  
    host = socket.gethostname()   
  
    # 设置端口号，与服务器端的端口号一致  
    port = 9999  
  
    # 连接服务，指定主机和端口  
    s.connect((host, port))  
  
    # 使用循环不断地发送消息  
    message = "Hello, Server!"  
    while True:  
        s.send(message.encode())  
        print('已发送消息: ' + message)  
        time.sleep(1)  # 每秒发送一次消息  
  
    # 关闭连接  
    s.close()  
  
if __name__ == '__main__':  
    start_client()
