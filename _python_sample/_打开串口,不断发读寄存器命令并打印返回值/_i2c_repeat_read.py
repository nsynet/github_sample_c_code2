#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
串口循环通信示例
功能：循环发送串口命令并打印返回数据
"""

import serial
import time
import sys

# ==================== 配置区域 ====================
# 串口配置（根据你的系统修改）
PORT = 'COM53'          # Windows: COM1, COM2, COM3... 
                       # Linux: /dev/ttyUSB0, /dev/ttyACM0
                       # macOS: /dev/cu.usbserial, /dev/cu.usbmodem

BAUDRATE = 115200        # 波特率：9600, 115200 等
BYTESIZE = serial.EIGHTBITS    # 数据位：8
PARITY = serial.PARITY_NONE    # 校验位：无
STOPBITS = serial.STOPBITS_ONE # 停止位：1
TIMEOUT = 1            # 读取超时时间（秒）

# 要循环发送的命令列表
COMMANDS = [
    "i2ctransfer -f -y 11 w2@0x40 0x00 0x00 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x00 0x20 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x00 0x40 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x00 0x60 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x00 0x80 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x00 0xa0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x00 0xc0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x00 0xe0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x01 0x00 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x01 0x20 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x01 0x40 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x01 0x60 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x01 0x80 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x01 0xa0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x01 0xc0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x01 0xe0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x02 0x00 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x02 0x20 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x02 0x40 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x02 0x60 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x02 0x80 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x02 0xa0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x02 0xc0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x02 0xe0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x03 0x00 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x03 0x20 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x03 0x40 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x03 0x60 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x03 0x80 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x03 0xa0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x03 0xc0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x03 0xe0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x04 0x00 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x04 0x20 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x04 0x40 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x04 0x60 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x04 0x80 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x04 0xa0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x04 0xc0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x04 0xe0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x05 0x00 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x05 0x20 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x05 0x40 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x05 0x60 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x05 0x80 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x05 0xa0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x05 0xc0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x05 0xe0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x14 0x00 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x14 0x20 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x14 0x40 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x14 0x60 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x14 0x80 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x14 0xa0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x14 0xc0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x14 0xe0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x15 0x00 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x15 0x20 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x15 0x40 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x15 0x60 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x15 0x80 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x15 0xa0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x15 0xc0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x15 0xe0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x16 0x00 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x16 0x20 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x16 0x40 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x16 0x60 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x16 0x80 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x16 0xa0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x16 0xc0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x16 0xe0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x17 0x00 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x17 0x20 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x17 0x40 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x17 0x60 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x17 0x80 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x17 0xa0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x17 0xc0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x17 0xe0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x1d 0x00 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x1d 0x20 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x1d 0x40 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x1d 0x60 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x1d 0x80 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x1d 0xa0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x1d 0xc0 r20\n",
    "i2ctransfer -f -y 11 w2@0x40 0x1d 0xe0 r20\n",
]

# 循环配置
MAX_CYCLES = 1        # 最大循环次数（None表示无限循环）
CMD_DELAY = 0.5        # 每条命令间隔（秒）
CYCLE_DELAY = 1.0      # 每轮循环间隔（秒）

# ==================== 功能函数 ====================

def list_serial_ports():
    """列出可用串口"""
    ports = serial.tools.list_ports.comports()
    print("可用串口列表：")
    for port in ports:
        print(f"  {port.device} - {port.description}")
    return [p.device for p in ports]

def send_and_receive(ser, command):
    """发送命令并接收返回"""
    try:
        # 清空缓冲区
        ser.reset_input_buffer()
        ser.reset_output_buffer()
        
        # 发送数据
        ser.write(command.encode('utf-8'))
        print(f"[发送] {repr(command)}")
        
        # 等待设备响应
        time.sleep(0.1)
        
        # 读取返回数据
        response = b''
        start_time = time.time()
        
        # 持续读取直到超时或收到完整数据
        while (time.time() - start_time) < TIMEOUT:
            if ser.in_waiting > 0:
                data = ser.read(ser.in_waiting)
                response += data
                # 如果收到换行符，认为数据接收完成
                if b'\n' in data:
                    break
            time.sleep(0.01)
        
        # 打印返回结果
        if response:
            try:
                decoded = response.decode('utf-8').strip()
                print(f"[接收] {decoded}")
            except UnicodeDecodeError:
                print(f"[接收] {response.hex()}")
        else:
            print("[接收] (无返回)")
            
    except Exception as e:
        print(f"[错误] 通信失败: {e}")
    
    print("-" * 50)

def main():
    """主函数"""
    print("=" * 50)
    print("串口循环通信程序")
    print("=" * 50)
    
    try:
        # 打开串口
        print(f"\n正在打开串口 {PORT}...")
        ser = serial.Serial(
            port=PORT,
            baudrate=BAUDRATE,
            bytesize=BYTESIZE,
            parity=PARITY,
            stopbits=STOPBITS,
            timeout=TIMEOUT
        )
        
        print(f"✓ 串口已打开")
        print(f"  端口: {ser.port}")
        print(f"  波特率: {ser.baudrate}")
        print(f"  数据位: {ser.bytesize}")
        print(f"  校验: {ser.parity}")
        print(f"  停止位: {ser.stopbits}")
        print(f"\n按 Ctrl+C 停止程序")
        print("=" * 50)
        
        # 循环发送命令
        cycle = 0
        while True:
            if MAX_CYCLES and cycle >= MAX_CYCLES:
                print(f"\n已达到最大循环次数 {MAX_CYCLES}")
                break
                
            cycle += 1
            print(f"\n>>> 第 {cycle} 轮循环")
            
            for i, cmd in enumerate(COMMANDS, 1):
                print(f"\n[{i}/{len(COMMANDS)}] ")
                send_and_receive(ser, cmd)
                time.sleep(CMD_DELAY)
            
            print(f"<<< 第 {cycle} 轮完成")
            time.sleep(CYCLE_DELAY)
            
    except serial.SerialException as e:
        print(f"✗ 串口错误: {e}")
        print("提示：请检查串口名称是否正确，设备是否连接")
        sys.exit(1)
        
    except KeyboardInterrupt:
        print("\n\n用户中断程序")
        
    finally:
        if 'ser' in locals() and ser.is_open:
            ser.close()
            print("✓ 串口已关闭")

if __name__ == "__main__":
    main()