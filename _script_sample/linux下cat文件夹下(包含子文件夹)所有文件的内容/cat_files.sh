#!/bin/bash  
  
# 指定要遍历的目录  
target_dir="$1"  
  
# 检查是否提供了目录参数  
if [ -z "$target_dir" ]; then  
    echo "Usage: $0 <directory_to_traverse>"  
    exit 1  
fi  
  
# 检查目标目录是否存在  
if [ ! -d "$target_dir" ]; then  
    echo "Error: $target_dir is not a directory."  
    exit 1  
fi  
  
# 遍历目录的函数  
traverse_dir() {  
    local dir="$1"  
    for entry in "$dir"/*; do  
        # 检查是否为文件且非链接  
        if [ -L "$entry" ]; then  
			echo ""  
		elif [ -f "$entry" ]; then  
            echo "cat file: $entry"  
            cat "$entry"  
            echo "==================="  
        # 检查是否为目录  
        elif [ -d "$entry" ]; then  
            # 递归遍历子目录  
            traverse_dir "$entry"  
        fi  
    done  
}  
  
# 调用遍历目录的函数  
traverse_dir "$target_dir"
