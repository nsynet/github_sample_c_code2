echo on
setlocal enabledelayedexpansion  
:: 获取当前日期和时间，并格式化为YYYY-MM-DD-HH-MM-SS  
	for /f "tokens=2 delims==" %%I in ('wmic OS Get localdatetime /value') do set datetime=%%I  
	set year=%datetime:~0,4%  
	set month=%datetime:~4,2%  
	set day=%datetime:~6,2%  
	set hour=%datetime:~8,2%  
	set minute=%datetime:~10,2%  
	set second=%datetime:~12,2%  
	
set filename=%year%-%month%-%day%-%hour%-%minute%-%second%.txt  
call :WORK >!filename!  

:WORK
cls
adb root
adb shell "date  &&uname -a"
echo ========= AVM  CHECK ===========
adb  shell "cat /sys/class/misc/max9286_control/camera_status"
adb  shell "cat /sys/class/misc/max9286_control/camera_status_value"
adb  shell "echo 0xd4 0x1e > /sys/class/misc/max9286_control/readReg  # read max9286 ID: 0x1e=0x40"  
adb  shell "cat /sys/class/misc/max9286_control/readReg"
adb  shell "echo 0xd4 0x49 > /sys/class/misc/max9286_control/readReg  # read max9286 0x49=0x0f"  
adb  shell "cat /sys/class/misc/max9286_control/readReg"
adb  shell "echo 0xd4 0x69 > /sys/class/misc/max9286_control/readReg  # read max9286 0x69=0xf0 is ok"  
adb  shell "cat /sys/class/misc/max9286_control/readReg"
adb  shell "echo 0x82 0x1e > /sys/class/misc/max9286_control/readReg  # read link A max9670x ID=0x45"  
adb  shell "cat /sys/class/misc/max9286_control/readReg"
adb  shell "echo 0x84 0x1e > /sys/class/misc/max9286_control/readReg  # read link B max9670x ID=0x45"  
adb  shell "cat /sys/class/misc/max9286_control/readReg"
adb  shell "echo 0x86 0x1e > /sys/class/misc/max9286_control/readReg  # read link C max9670x ID=0x45"  
adb  shell "cat /sys/class/misc/max9286_control/readReg"
adb  shell "echo 0x88 0x1e > /sys/class/misc/max9286_control/readReg  # read link D max9670x ID=0x45"  
adb  shell "cat /sys/class/misc/max9286_control/readReg"
goto :eof