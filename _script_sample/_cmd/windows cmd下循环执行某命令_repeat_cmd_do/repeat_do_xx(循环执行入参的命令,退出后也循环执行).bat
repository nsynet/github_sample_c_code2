@echo off
adb root
for /l %%i in (1,0,1) do %1 &&choice /T 1 /C ync /CS /D y /n
pause