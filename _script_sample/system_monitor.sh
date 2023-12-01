#!/system/bin/sh

#在window上右击鼠标->"Git Bash Here"，然后执行如下命令完成csv格式的转化：
#sed -i ":a;N;s/\"\n\,/\"\,/g;ba"  $file1
#然后在excel上打开CSV格式 
	
cd /logcache

if [ ! -d "log" ];then
    mkdir -m 707 log
fi

cd /logcache/log

if [ ! -d "monitor_log" ];then
    mkdir -m 707 monitor_log
fi

cd /logcache/log/monitor_log
cp -rf /vendor/bin/system_monitor_log_README.txt .

if [ -f "1_monitor.csv" ];then
    log=`ls -l | grep monitor |awk '{print $8}' |sort -n | awk 'END{print}' |cut -d '_' -f 1`
    if [ -f "50_monitor.csv" ];then
        log=`ls -lrt | grep monitor |awk 'NR==1{print $8}' |cut -d '_' -f 1`
        let log-=1
    fi
else
    log=0
fi

while [ 1 ]
do
    let log+=1
    file1=${log}_monitor.csv
    
    #添加csv格式的每一列的统计类型
    str="\"DATE\""
    echo   ${str} > $file1
    str=",\"------top %CPU------\""
    echo   ${str} >> $file1
    str=",\"------top %MEM------\""
    echo   ${str} >> $file1
    str=",\"------df------\""
    echo   ${str} >> $file1
    str=",\"------gpu_loading------\""
    echo   ${str} >> $file1
    str=",\"------meminfo------\""
    echo   ${str} >> $file1
    
    chmod 707 $file1
    file_size=0
    while [ $file_size -lt 2097152 ]
    do
        sleep 5s
        
        #实际追加统计值
        str="\""$(date)"\""
        echo   ${str} >> $file1
        
        #echo "------top %CPU------" >> $file1
        # begin add next row
        echo ",\"" >> $file1
        # append multiline result
        top -bn1 -s 8 -m 10 >> $file1
        # end add next row
        echo "\"" >> $file1
    
        #echo "------top %MEM------" >> $file1
        # begin add next row
        echo ",\"" >> $file1
        # append multiline result
        top -bn1 -s 10 -m 10 >> $file1
        # end add next row
        echo "\"" >> $file1

        #echo "------df------" >> $file1
        # begin add next row
        echo ",\"" >> $file1
        # append multiline result
        df -h |egrep "/data$|Size" >> $file1
        # end add next row
        echo "\"" >> $file1
        
        #echo "------gpu_loading------" >> $file1
        # begin add next row
        echo ",\"" >> $file1
        # append multiline result
        cat /sys/kernel/debug/gc/idle | awk '{printf $0}' | awk '{printf "%.2f%%\n", 100*$6/($6+$8+$12)}' >> $file1
        # end add next row
        echo "\"" >> $file1

        #echo "------meminfo------" >> $file1
        # begin add next row
        echo ",\"" >> $file1
        # append multiline result
        cat /proc/meminfo | grep -E 'Mem|Cma' >> $file1
        # end add next row
        echo "\"" >> $file1
        
        #echo "------interrupts------" >> $file1
        #cat /proc/interrupts >> $file1
        
        file_size=`ls -lt |grep $file1 | awk 'NR==1{print $5}'`
    done
    
    sync

    if [ $log -eq 50 ];then
        log=0
    fi
done
