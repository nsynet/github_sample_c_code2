#!/usr/bin/env python3

import os
import subprocess
import shutil

def save_changed_files():
    old_dir = "_old"
    new_dir = "_new"
    
    os.makedirs(old_dir, exist_ok=True)
    os.makedirs(new_dir, exist_ok=True)
    
    # 获取修改的文件列表
    result = subprocess.run(
        ["git", "diff", "--name-only", "HEAD"],
        capture_output=True, text=True
    )
    
    changed_files = [f.strip() for f in result.stdout.split('\n') if f.strip()]
    
    for file_path in changed_files:
        if not file_path:
            continue
            
        print(f"Processing: {file_path}")
        
        # 创建目录
        old_file_dir = os.path.join(old_dir, os.path.dirname(file_path))
        new_file_dir = os.path.join(new_dir, os.path.dirname(file_path))
        os.makedirs(old_file_dir, exist_ok=True)
        os.makedirs(new_file_dir, exist_ok=True)
        
        # 保存旧版本
        try:
            old_content = subprocess.run(
                ["git", "show", f"HEAD:{file_path}"],
                capture_output=True, text=True, check=True
            )
            with open(os.path.join(old_dir, file_path), 'w') as f:
                f.write(old_content.stdout)
        except subprocess.CalledProcessError:
            with open(os.path.join(old_dir, file_path), 'w') as f:
                f.write(f"# New file: {file_path}\n")
        
        # 保存新版本
        if os.path.exists(file_path):
            shutil.copy2(file_path, os.path.join(new_dir, file_path))
        else:
            with open(os.path.join(new_dir, file_path), 'w') as f:
                f.write(f"# Deleted file: {file_path}\n")
    
    print(f"Completed! Check {old_dir} and {new_dir} directories")

if __name__ == "__main__":
    save_changed_files()
