@echo off

set /a count=0

:loop
adb root

if %count% EQU 100000 goto end
echo "********** start cat cpu freq **********"
adb shell date
adb shell cat /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_cur_freq
adb shell cat /sys/devices/system/cpu/cpu1/cpufreq/cpuinfo_cur_freq
adb shell cat /sys/devices/system/cpu/cpu2/cpufreq/cpuinfo_cur_freq
adb shell cat /sys/devices/system/cpu/cpu3/cpufreq/cpuinfo_cur_freq
adb shell cat /sys/devices/system/cpu/cpu4/cpufreq/cpuinfo_cur_freq
adb shell cat /sys/devices/system/cpu/cpu5/cpufreq/cpuinfo_cur_freq
adb shell cat /sys/devices/system/cpu/cpu6/cpufreq/cpuinfo_cur_freq
echo "********** end **********"

set /a count+=1
echo ........%count% time........
TIMEOUT /T 1

goto loop
:end
pause
exit