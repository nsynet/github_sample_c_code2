#自动化测试需要2个通道,一个控制继电器做操作,一个(可选)读设备节点的状态,这样就能边执行边判断测试结果.
import serial
import time
import os

#BEGIN 测试配置
SERIAL_COM='COM6'                #继电器的串口端口号
ADB_ID='-s 0123456789ABCDEF'     #安卓的adb devices 的ID号
#END 测试配置


step_1_cmd  =[
           [[0xa0,0x01,0x01,0xa2],30]]  #acc connect

def step_1(ser):
    print('--- step_1:power up ---')
    #output = os.popen('adb -s 0123456789ABCDEF shell  uptime')
    #print(output.read())
    a=0
    while(a < len(step_1_cmd)):
        ser.write(step_1_cmd[a][0])
        time.sleep(step_1_cmd[a][1])
        a=a+1
        

step_2_cmd  =[
           [[0xa0,0x01,0x00,0xa1],30],  #acc disconnect
           [[0xa0,0x01,0x01,0xa2],30]]  #acc connect]
           
def step_2(ser):
    print('--- step_2:sleep and wake up ---')
    a=0
    while(a < len(step_2_cmd)):
        ser.write(step_2_cmd[a][0])
        time.sleep(step_2_cmd[a][1])
        a=a+1

"""
step_3_cmd = [
           [[0xa0,0x02,0x01,0xa3],12],
           [[0xa0,0x02,0x00,0xa2],30]]

def step_3(ser):
    print('--- step_3:xx ---')
    a=0
    while(a < len(step_3_cmd)):
        ser.write(step_3_cmd[a][0])
        time.sleep(step_3_cmd[a][1])
        a=a+1

"""

def step99_check_status():
    print('--- step_99:check_status:',end=' ')
    STR='adb '
    STR +=ADB_ID
    STR +=' shell settings get system camera_normal'
    output1 = os.popen(STR)
    output1_val = int(output1.read(),10)
    print(output1_val,end=' ')
    time.sleep(1)
    
    output2 = os.popen(STR)
    output2_val = int(output2.read(),10)
    print(output2_val,end=' ')
    time.sleep(1)
    
    output3 = os.popen(STR)
    output3_val = int(output3.read(),10)
    print(output3_val)
    time.sleep(1)
    
    if((output1_val != 1) and (output2_val != 1) and (output3_val != 1)):
        print('problem occur !!')
        return -1
    return 0
    
    
def main():
    ser = serial.Serial()
    ser.baudrate = 115200
    ser.timeout = 1
    ser.port = SERIAL_COM
    ser.open()
    cnt=1
    step_1(ser)
    while (cnt <9999999):
        print("-->test  ",cnt)
        print(time.strftime('%Y-%m-%d %H:%M:%S',time.localtime(time.time())))       # 打印按指定格式排版的时间
        step_2(ser)
        if(step99_check_status() != 0):
            break
        #step_2(ser)
        #step_3(ser)
        cnt = cnt +1
    ser.close()
    print('---- test end !! -----')

main()
