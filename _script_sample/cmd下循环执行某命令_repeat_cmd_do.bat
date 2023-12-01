@echo off
adb root
for /l %%i in (1,0,1) do adb shell "cat /sys/bus/i2c/devices/i2c-2/2-0029/camera_Max96722Bx_status" &&choice /T 1 /C ync /CS /D y /n
pause