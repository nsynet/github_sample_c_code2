import os
import platform
import struct
import sys

def get_bitness():
    # 检测操作系统位数
    if platform.system() == "Windows":
        # 在Windows上，使用ctypes来检测系统位数
        import ctypes
        return ctypes.sizeof(ctypes.c_voidp) * 8
    else:
        # 在Linux上，使用os来检测系统位数
        return os.sysconf('SC_PAGE_SIZE') * 8 // os.cpu_count() * 8

def main():
    # 获取操作系统类型
    os_type = platform.system()
    # 获取操作系统位数
    os_bitness = get_bitness()
    # 获取Python解释器位数
    python_bitness = struct.calcsize("P") * 8

    print(f"操作系统: {os_type}")
    print(f"操作系统位数: {os_bitness}-bit")
    print(f"Python解释器位数: {python_bitness}-bit")
    # 获取当前Python解释器的完整路径
    python_executable_path = sys.executable

    print("当前Python解释器的完整路径是：", python_executable_path)
if __name__ == "__main__":
    main()



