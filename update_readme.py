import os
import re

README_PATH = "README.md"

def count_files_in_dir(path):
    """path 아래 모든 파일 개수를 세는 함수"""
    if not os.path.exists(path):
        return 0
    count = 0
    # os.walk를 사용하여 모든 하위 디렉터리까지 탐색
    for root, _, files in os.walk(path):
        for f in files:
            # 지정된 확장자로 끝나는 파일만 카운트
            if f.endswith((".py", ".java", ".cpp", ".c", ".js")):
                count += 1
    return count


def get_solved_counts():
    """각 디렉터리별 문제 풀이 파일 수를 계산하여 딕셔너리로 반환"""
    counts = {
        "bronze": count_files_in_dir("boj/Lv1_bronze"),
        "silver": count_files_in_dir("boj/Lv2_silver"),
        "gold": count_files_in_dir("boj/Lv3_gold"),
        "platinum": count_files_in_dir("boj/Lv4_platinum"),
        "programmers_lv1": count_files_in_dir("programmers/Lv1"),
        "programmers_lv2": count_files_in_dir("programmers/Lv2"),
        "swea": count_files_in_dir("swea"),
    }
    return counts


def update_readme(counts):
    """README.md 파일을 읽어 문제 풀이 수를 업데이트"""
    with open(README_PATH, "r", encoding="utf-8") as f:
        content = f.read()

    # Baekjoon 업데이트: \1 대신 \g<1>을 사용하여 명확하게 그룹을 참조
    content = re.sub(r"(🥉 Bronze\s*\|\s*)\d+", fr"\g<1>{counts['bronze']}", content)
    content = re.sub(r"(🥈 Silver\s*\|\s*)\d+", fr"\g<1>{counts['silver']}", content)
    content = re.sub(r"(🥇 Gold\s*\|\s*)\d+", fr"\g<1>{counts['gold']}", content)
    content = re.sub(r"(💎 Platinum\s*\|\s*)\d+", fr"\g<1>{counts['platinum']}", content)

    # Programmers 업데이트
    content = re.sub(r"(Lv\.1\s*\|\s*)\d+", fr"\g<1>{counts['programmers_lv1']}", content)
    content = re.sub(r"(Lv\.2\s*\|\s*)\d+", fr"\g<1>{counts['programmers_lv2']}", content)

    # SWEA 업데이트
    content = re.sub(r"(전체\s*\|\s*)\d+", fr"\g<1>{counts['swea']}", content)

    with open(README_PATH, "w", encoding="utf-8") as f:
        f.write(content)


if __name__ == "__main__":
    counts = get_solved_counts()
    update_readme(counts)
    print("✅ README.md 업데이트 완료!")
    print(counts)
