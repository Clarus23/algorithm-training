import os

# 카운트할 확장자
TARGET_EXTENSIONS = [".cpp", ".java"]

# 탐색 대상 디렉토리
TARGET_DIRS = ["boj", "programmers", "swea"]

def count_solutions(base_path):
    total = 0
    detail_counts = {}

    for target in TARGET_DIRS:
        dir_path = os.path.join(base_path, target)
        count = 0
        if os.path.exists(dir_path):
            for root, _, files in os.walk(dir_path):
                for file in files:
                    if any(file.endswith(ext) for ext in TARGET_EXTENSIONS):
                        count += 1
                        total += 1
        detail_counts[target] = count

    return total, detail_counts


def update_readme(base_path, total, detail_counts):
    readme_path = os.path.join(base_path, "README.md")
    with open(readme_path, "r", encoding="utf-8") as f:
        lines = f.readlines()

    # README 내에 "## 📊 풀이 현황" 블럭 갱신
    start_marker = "## 📊 풀이 현황"
    start_idx = None
    for i, line in enumerate(lines):
        if line.strip() == start_marker:
            start_idx = i
            break

    if start_idx is not None:
        # 기존 블럭 제거 후 새로 삽입
        lines = lines[:start_idx+1]
    else:
        # 없으면 맨 끝에 추가
        lines.append("\n" + start_marker + "\n")

    # 새로운 통계 내용 작성
    stats_block = [
        f"\n- 총 풀이 수: **{total}** 문제\n",
        f"- BOJ: **{detail_counts.get('boj', 0)}** 문제\n",
        f"- Programmers: **{detail_counts.get('programmers', 0)}** 문제\n",
        f"- SWEA: **{detail_counts.get('swea', 0)}** 문제\n",
        "\n"
    ]
    lines.extend(stats_block)

    with open(readme_path, "w", encoding="utf-8") as f:
        f.writelines(lines)


if __name__ == "__main__":
    BASE_PATH = os.path.dirname(os.path.abspath(__file__))
    total, detail_counts = count_solutions(BASE_PATH)
    update_readme(BASE_PATH, total, detail_counts)
