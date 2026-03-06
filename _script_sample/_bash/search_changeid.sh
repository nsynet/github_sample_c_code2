#!/bin/bash

# 配置：请修改为你的代码仓库所在的根目录
base_dir="/workspace/code13_QCM8295/Android"

# 目标 Change-Id (完整的ID字符串)
target_changeid="Ia7cfb33664f8ebe43b78f8e4c91be831bc3d00e6"

echo "开始在以下目录的所有Git仓库中搜索 Change-Id: $target_changeid"
echo "搜索根目录: $base_dir"
echo "----------------------------------------"

# 使用 find 命令查找所有 .git 目录，即定位所有 Git 仓库
find "$base_dir" -type d -name ".git" 2>/dev/null | while read git_dir; do
    # 获取仓库的实际路径（.git 目录的上一级）
    repo_path=$(dirname "$git_dir")
    
    # 进入仓库路径
    cd "$repo_path" || continue
    
    # 在当前仓库中搜索
    # 使用 git for-each-ref 获取所有本地分支和标签的引用名，并对每个引用执行 git log 搜索 Change-Id
    # 这样可以确保搜索覆盖所有分支和标签，而不仅仅是当前检出的分支
    result=$(git for-each-ref --format='%(refname)' refs/heads/ refs/tags/ 2>/dev/null | \
             xargs -I {} git log {} --oneline --grep="$target_changeid" 2>/dev/null)
    
    # 如果搜索结果非空，则打印仓库路径和结果
    if [ -n "$result" ]; then
        echo "找到匹配的仓库: $repo_path"
        echo "$result"
        echo "----------------------------------------"
    fi
done

echo "搜索完成。"
