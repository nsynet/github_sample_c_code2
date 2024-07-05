#!/bin/bash  
  
# 检查是否提供了一个文件路径作为参数  
if [ "$#" -ne 1 ]; then  
    echo "Usage: $0 <file_path>"  
    exit 1  
fi  
  
file_path="$1"  
  
# 检查文件是否存在  
if [ ! -f "$file_path" ]; then  
    echo "Error: File $file_path does not exist."  
    exit 1  
fi  
  
# 使用sort和uniq命令去重，并输出到标准输出  
# 你可以将下面的输出重定向到一个新文件，例如：> "${file_path}_dedup.txt"  
sort "$file_path" | uniq

#使用方法:
#比如，如果你的文件名为example.txt，你可以这样运行脚本：
#./remove_duplicates.sh example.txt
#如果你想要将去重后的内容保存到一个新文件中，你可以使用重定向操作符>，如下所示：
#./remove_duplicates.sh example.txt > example_dedup.txt
#这样，去重后的内容就会被保存到example_dedup.txt文件中