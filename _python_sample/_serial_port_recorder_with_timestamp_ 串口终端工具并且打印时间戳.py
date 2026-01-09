import serial
import time
import threading
from datetime import datetime
import os

class SerialLoggerWithTimestamp:
    def __init__(self, port, baudrate=115200, timeout=1):
        """
        初始化串口日志记录器
        :param port: 串口号 (如 'COM3', '/dev/ttyUSB0')
        :param baudrate: 波特率
        :param timeout: 超时时间
        """
        self.port = port
        self.baudrate = baudrate
        self.timeout = timeout
        self.serial_port = None
        self.running = False
        self.lock = threading.Lock()
        
        # 生成文件名：D:/serial_log_年-月-日_时-分-秒.txt
        self.filename = f"D:/serial_log_{datetime.now().strftime('%Y-%m-%d_%H-%M-%S')}.txt"
        
    def open_serial(self):
        """打开串口"""
        try:
            self.serial_port = serial.Serial(
                port=self.port,
                baudrate=self.baudrate,
                timeout=self.timeout
            )
            print(f"成功打开串口: {self.port}，波特率: {self.baudrate}")
            return True
        except serial.SerialException as e:
            print(f"打开串口失败: {e}")
            return False
    
    def write_to_file(self, data, is_timestamp=False):
        """写入数据到文件"""
        try:
            with open(self.filename, 'a', encoding='utf-8') as f:
                if is_timestamp:
                    # 如果是时间戳，添加特殊标记
                    timestamp_line = f"\n[{datetime.now().strftime('%Y-%m-%d %H:%M:%S')}] ======== PC时间戳 ========\n"
                    f.write(timestamp_line)
                    print(f"已添加时间戳: {timestamp_line.strip()}")
                else:
                    # 写入普通串口数据
                    f.write(data)
        except Exception as e:
            print(f"写入文件失败: {e}")
    
    def read_serial_data(self):
        """读取串口数据线程函数"""
        buffer = ""
        print("开始读取串口数据...")
        print(f"数据保存至: {self.filename}")
        print("每隔10秒会自动添加一次时间戳")
        
        while self.running:
            try:
                if self.serial_port and self.serial_port.is_open:
                    # 读取串口数据
                    if self.serial_port.in_waiting > 0:
                        data = self.serial_port.read(self.serial_port.in_waiting)
                        try:
                            text = data.decode('utf-8', errors='ignore')
                            buffer += text
                            
                            # 如果有换行符，写入文件
                            if '\n' in buffer:
                                lines = buffer.split('\n')
                                for line in lines[:-1]:
                                    with self.lock:
                                        self.write_to_file(line + '\n')
                                buffer = lines[-1]
                        except Exception as e:
                            print(f"解码数据失败: {e}")
                    
                    time.sleep(0.01)  # 短暂休眠，避免占用太多CPU
                else:
                    time.sleep(0.1)
            except Exception as e:
                print(f"读取串口数据异常: {e}")
                time.sleep(0.1)
    
    def timestamp_worker(self):
        """时间戳线程函数，每隔10秒添加一次时间戳"""
        print("时间戳线程已启动，每隔10秒添加一次时间戳")
        while self.running:
            time.sleep(10)  # 等待10秒
            if self.running:
                with self.lock:
                    self.write_to_file("", is_timestamp=True)
    
    def start(self):
        """启动串口监听和时间戳线程"""
        if not self.open_serial():
            return False
        
        self.running = True
        
        # 创建并启动串口读取线程
        serial_thread = threading.Thread(target=self.read_serial_data)
        serial_thread.daemon = True
        
        # 创建并启动时间戳线程
        timestamp_thread = threading.Thread(target=self.timestamp_worker)
        timestamp_thread.daemon = True
        
        serial_thread.start()
        timestamp_thread.start()
        
        print("\n" + "="*50)
        print("串口数据记录器已启动")
        print(f"串口: {self.port}")
        print(f"波特率: {self.baudrate}")
        print(f"保存文件: {self.filename}")
        print("每隔10秒会自动添加一次PC时间戳")
        print("按 Ctrl+C 停止程序")
        print("="*50 + "\n")
        
        return True
    
    def stop(self):
        """停止所有线程"""
        self.running = False
        if self.serial_port and self.serial_port.is_open:
            self.serial_port.close()
            print("串口已关闭")
        print("程序已停止")
    
    def run(self):
        """运行主程序"""
        try:
            if self.start():
                # 保持主线程运行
                while self.running:
                    time.sleep(0.1)
        except KeyboardInterrupt:
            print("\n检测到Ctrl+C，正在停止程序...")
        finally:
            self.stop()


def list_serial_ports():
    """列出可用的串口"""
    import sys
    ports = []
    
    if sys.platform.startswith('win'):
        # Windows系统
        for i in range(1, 257):
            port = f'COM{i}'
            try:
                s = serial.Serial(port)
                s.close()
                ports.append(port)
            except (OSError, serial.SerialException):
                pass
    elif sys.platform.startswith('linux') or sys.platform.startswith('cygwin'):
        # Linux系统
        import glob
        ports = glob.glob('/dev/tty[A-Za-z]*')
    elif sys.platform.startswith('darwin'):
        # macOS系统
        import glob
        ports = glob.glob('/dev/tty.*')
    
    return ports


if __name__ == "__main__":
    # 列出可用串口
    available_ports = list_serial_ports()
    print("可用的串口:")
    for i, port in enumerate(available_ports, 1):
        print(f"{i}. {port}")
    
    # 获取用户输入
    if available_ports:
        try:
            choice = input(f"\n请选择串口号 (1-{len(available_ports)}) 或直接输入串口号: ").strip()
            if choice.isdigit() and 1 <= int(choice) <= len(available_ports):
                port = available_ports[int(choice)-1]
            else:
                port = choice
        except:
            port = available_ports[0] if available_ports else 'COM3'
    else:
        port = input("未检测到可用串口，请输入串口号 (如COM3): ").strip()
    
    # 获取波特率
    baudrate_input = input("请输入波特率 (默认115200): ").strip()
    baudrate = int(baudrate_input) if baudrate_input.isdigit() else 115200
    
    # 检查D盘是否存在
    if not os.path.exists('D:/'):
        print("警告: D盘不存在，将尝试在当前目录保存文件")
        # 修改保存路径到当前目录
        import __main__
        script_dir = os.path.dirname(os.path.abspath(__main__.__file__))
        filename = f"serial_log_{datetime.now().strftime('%Y-%m-%d_%H-%M-%S')}.txt"
        print(f"文件将保存到: {os.path.join(script_dir, filename)}")
    
    # 创建并运行串口记录器
    logger = SerialLoggerWithTimestamp(port, baudrate)
    logger.run()