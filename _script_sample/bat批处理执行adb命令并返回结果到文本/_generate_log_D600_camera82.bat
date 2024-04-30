echo on
set DATE=%date%
set  YEAR=%DATE:~0,3%
set  MONTH=%DATE:~5,2%
set  DAY=%DATE:~8,2%

set  NOW=%time%
set  HOUR=%NOW:~0,2%
set  MINUTE=%NOW:~3,2%
set  SECOND=%NOW:~6,2%
call :WORK >%YEAR%-%MONTH%-%DAY%__%HOUR%-%MINUTE%-%SECOND%.log
pause

:WORK
adb root
echo ========= I2C-8  check ===========
adb shell "ls -al  /system/bin/dls_reverse_svr*"
adb shell "uname -a"
adb shell "i2cdetect -y -r 8"
adb shell "i2cdump -f -y 8 0x21 b"
adb shell "i2cdump -f -y 8 0x23 b"
adb shell "i2cdump -f -y 8 0x25 b"
adb shell "i2cset -f -y 8 0x44 0x40 0x00"
adb shell "i2cdump -f -y 8 0x44 b"
adb shell "i2cget -f -y 8 0x44 0x1  #MSB=011 is video 0 good"
adb shell "i2cget -f -y 8 0x44 0x3  #BIT2-0=4  is 720P30"
adb shell "i2cset -f -y 8 0x44 0x40 0x01"
adb shell "i2cdump -f -y 8 0x44 b"
adb shell "i2cget -f -y 8 0x44 0x1  #MSB=011 is video 1 good"
adb shell "i2cget -f -y 8 0x44 0x3  #BIT2-0=4  is 720P30"
adb shell "i2cset -f -y 8 0x44 0x40 0x02"
adb shell "i2cdump -f -y 8 0x44 b"
adb shell "i2cget -f -y 8 0x44 0x1  #MSB=011 is video 2 good"
adb shell "i2cget -f -y 8 0x44 0x3  #BIT2-0=4  is 720P30"
adb shell "i2cset -f -y 8 0x44 0x40 0x03"
adb shell "i2cdump -f -y 8 0x44 b"
adb shell "i2cget -f -y 8 0x44 0x1  #MSB=011 is video 3 good"
adb shell "i2cget -f -y 8 0x44 0x3  #BIT2-0=4  is 720P30"
echo ========= I2C-2  check ===========
adb shell "uname -a"
adb shell "i2cdetect -y -r 2"
adb shell "i2cdump -f -y 2 0x24 b"
adb shell "i2cdump -f -y 2 0x27 b"
adb shell "i2cset -f -y 2 0x45 0x40 0x00"
adb shell "i2cdump -f -y 2 0x45 b"
adb shell "i2cget -f -y 2 0x45 0x1  #MSB=011 is video 0 good"
adb shell "i2cget -f -y 2 0x45 0x3  #BIT2-0=4  is 720P30"
adb shell "i2cset -f -y 2 0x45 0x40 0x01"
adb shell "i2cdump -f -y 2 0x45 b"
adb shell "i2cget -f -y 2 0x45 0x1  #MSB=011 is video 1 good"
adb shell "i2cget -f -y 2 0x45 0x3  #BIT2-0=4  is 720P30"
adb shell "i2cset -f -y 2 0x45 0x40 0x02"
adb shell "i2cdump -f -y 2 0x45 b"
adb shell "i2cget -f -y 2 0x45 0x1  #MSB=011 is video 2 good"
adb shell "i2cget -f -y 2 0x45 0x3  #BIT2-0=4  is 720P30"
adb shell "i2cset -f -y 2 0x45 0x40 0x03"
adb shell "i2cdump -f -y 2 0x45 b"
adb shell "i2cget -f -y 2 0x45 0x1  #MSB=011 is video 3 good"
adb shell "i2cget -f -y 2 0x45 0x3  #BIT2-0=4  is 720P30"


goto :eof