echo on
set DATE=%date%
set  YEAR=%DATE:~0,3%
set  MONTH=%DATE:~5,2%
set  DAY=%DATE:~8,2%

set  NOW=%time%
set  HOUR=%NOW:~0,2%
set  MINUTE=%NOW:~3,2%
set  SECOND=%NOW:~6,2%
call python _generate_i2ctransfer_val_bus2_addr_0x29_max96722_m57.py >%HOUR%-%MINUTE%-%SECOND%.log

