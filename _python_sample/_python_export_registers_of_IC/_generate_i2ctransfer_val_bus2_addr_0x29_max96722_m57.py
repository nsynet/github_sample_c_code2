import os
import time

a=0
b=0
os.system('adb root')
os.system('adb remount')    

s_blank=" "
k=""
while b <= 0x18:
    while a <= 0xFF:
        z='adb shell i2ctransfer -f -y 2 w2@0x29 '
        z += s_blank+ hex(b)
        z+= s_blank
        z += s_blank + hex(a)
        z +=' r1'
        k=hex(b)+ " " +hex(a) +"="
        print(k,end='')
        output=os.popen(z)
        print(output.read())
        a+=1
    b+=1
    a=0
