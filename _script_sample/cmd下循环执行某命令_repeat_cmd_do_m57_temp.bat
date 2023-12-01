@echo off
adb root
for /l %%i in (1,0,1) do adb  shell "cat /sys/class/thermal/thermal_zone*/type && cat /sys/class/thermal/thermal_zone*/temp" &&choice /T 1 /C ync /CS /D y /n
pause