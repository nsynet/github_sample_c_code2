import random
import time
import os
import subprocess


#ADB_ID=' '
ADB_ID='-s b7b0bb26'      #安卓的adb devices 的ID号
#END 测试环境的配置

def adb_root():
    try:
        # 使用subprocess.run来执行adb root命令
        result = subprocess.run(['adb', '-s', 'b7b0bb26', 'root'], check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        print(result.stdout)  # 打印命令的输出
    except subprocess.CalledProcessError as e:
        print(e.stderr)  # 如果命令执行失败，打印错误信息

def adb_shell(command,end_flag):
    try:
        # 使用subprocess.run来执行adb shell命令
        result = subprocess.run(['adb', '-s', 'b7b0bb26', 'shell', command], check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        if result.returncode != 0:  
            print("Error:", result.stderr)
            return -1
        else:
            print(result.stdout,end=end_flag)  # 打印命令的输出
            return result.stdout
    except subprocess.CalledProcessError as e:
        result = subprocess.run(['adb devices'], check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        if result.returncode != 0:  
            print("Error:", result.stderr)
            return -1
        else:
            print(result.stdout)  # 打印命令的输出
            print(e.stderr)  # 如果命令执行失败，打印错误信息
            return -1

def step_1():
    adb_shell('input tap 1122 1003',' ')
    random_number = random.uniform(0, 0.7)
    time.sleep(random_number)

   
def main():
    cnt = 0
    while (cnt <9999999):
        cnt=cnt+1
        step_1()


main()
