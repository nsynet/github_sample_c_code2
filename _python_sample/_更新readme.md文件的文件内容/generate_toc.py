#!/usr/bin/env python3
import os
import re
from pathlib import Path

# 配置区
REPO_ROOT = Path(__file__).parent
README = REPO_ROOT / "README.md"
IGNORE_DIRS = {'.git', 'node_modules', '__pycache__', '.venv', 'dist', 'build'}  # 要忽略的文件夹名
HEADING_LEVEL = '##'   # 要提取的标题级别（例如 '##' 或 '#'）
# 是否在 README 中显示文件夹分组标题（True=按文件夹分节，False=平铺所有文件）
GROUP_BY_FOLDER = True

def github_anchor(title):
    """生成 GitHub 风格的锚点（与 GitHub 渲染一致）"""
    anchor = title.strip().lower()
    # 移除特殊字符，保留字母数字、空格和连字符
    anchor = re.sub(r'[^\w\- ]', '', anchor)
    # 将空格和连续连字符替换为单个连字符
    anchor = re.sub(r'[ \-]+', '-', anchor)
    return anchor

def get_md_files(root_dir):
    """递归获取所有 .md 文件，忽略指定目录"""
    md_files = []
    for dirpath, dirnames, filenames in os.walk(root_dir):
        # 排除忽略的目录
        dirnames[:] = [d for d in dirnames if d not in IGNORE_DIRS]
        for fname in filenames:
            if fname.endswith('.md') and fname != 'README.md':
                full_path = Path(dirpath) / fname
                # 相对于根目录的路径（用于 README 链接）
                rel_path = full_path.relative_to(root_dir)
                md_files.append(rel_path)
    return sorted(md_files)

def extract_headings(file_path, level='##'):
    """从 MD 文件中提取指定级别的标题（去除前导/尾随空格）"""
    with open(file_path, 'r', encoding='utf-8') as f:
        content = f.read()
    # 匹配行首的 level 标题，例如 ^##\s+(.+)$
    pattern = rf'^{re.escape(level)}\s+(.+)$'
    return re.findall(pattern, content, re.MULTILINE)

def build_toc(md_files):
    """生成 Markdown 目录列表"""
    lines = []
    # 按文件夹分组（可选）
    if GROUP_BY_FOLDER:
        # 获取每个文件的目录名（相对于根目录）
        file_groups = {}
        for rel_path in md_files:
            folder = rel_path.parent if rel_path.parent != Path('.') else Path('.')
            file_groups.setdefault(folder, []).append(rel_path)
        # 按目录名称排序
        for folder, files in sorted(file_groups.items()):
            if str(folder) != '.':
                lines.append(f"\n### 📁 `{folder}`\n")
            for rel_path in files:
                lines.extend(format_file_entry(rel_path))
    else:
        for rel_path in md_files:
            lines.extend(format_file_entry(rel_path))
    return lines

def format_file_entry(rel_path):
    """为单个文件生成条目（可能包含多个二级标题）"""
    full_path = REPO_ROOT / rel_path
    titles = extract_headings(full_path, HEADING_LEVEL)
    if not titles:
        return []   # 没有匹配的标题，跳过

    # 文件显示名：取第一个标题或文件名
    file_display = titles[0] if titles else rel_path.stem
    # 生成行：- [文件显示名](文件路径)
    line = f"- [{file_display}]({rel_path})"
    # 生成所有函数链接
    func_links = []
    for title in titles:
        anchor = github_anchor(title)
        func_links.append(f"[`{title}`]({rel_path}#{anchor})")
    # 拼接函数链接（若过多可换行，这里保持一行）
    if func_links:
        line += "\n  " + ", ".join(func_links)
    return [line]

def update_readme(new_block):
    """将生成的块插入 README.md 的标记之间"""
    if not README.exists():
        print("⚠️ 未找到 README.md，将创建新文件。")
        with open(README, 'w', encoding='utf-8') as f:
            f.write("# Project Index\n\n" + new_block)
        return

    with open(README, 'r', encoding='utf-8') as f:
        content = f.read()

    start_tag = "<!-- AUTO-GENERATED START -->"
    end_tag = "<!-- AUTO-GENERATED END -->"
    pattern = rf'({re.escape(start_tag)}).*?({re.escape(end_tag)})'
    replacement = f"{start_tag}\n{new_block}\n{end_tag}"

    if re.search(pattern, content, re.DOTALL):
        new_content = re.sub(pattern, replacement, content, flags=re.DOTALL)
    else:
        # 没有标记，在末尾追加
        new_content = content.rstrip() + "\n\n" + replacement

    with open(README, 'w', encoding='utf-8') as f:
        f.write(new_content)
    print("✅ README.md 已更新！")

def main():
    md_files = get_md_files(REPO_ROOT)
    print(f"📄 找到 {len(md_files)} 个 MD 文件")
    toc_lines = build_toc(md_files)
    if not toc_lines:
        print("⚠️ 没有提取到任何二级标题，请检查文件格式。")
        return
    new_block = "\n".join(toc_lines)
    update_readme(new_block)

if __name__ == "__main__":
    main()
