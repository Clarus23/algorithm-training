import os
import re

# ------------ 경로 설정 ------------
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
README_PATH = os.path.join(BASE_DIR, "README.md")

# ------------ 문제 풀이 경로 매핑 ------------
paths = {
    "boj": {
        "🥉 Bronze": "boj/Lv1_bronze",
        "🥈 Silver": "boj/Lv2_silver",
        "🥇 Gold": "boj/Lv3_gold",
        "💎 Platinum": "boj/Lv4_platinum"
    },
    "programmers": {
        "Lv.1": "programmers/Lv1",
        "Lv.2": "programmers/Lv2"
    },
    "swea": {
        "전체": "swea"
    }
}

def count_files(path: str) -> int:
    """경로 내 모든 파일 개수 세기"""
    if not os.path.exists(path):
        return 0
    return len([f for f in os.listdir(path) if os.path.isfile(os.path.join(path, f))])

def generate_table():
    """각 플랫폼별 통계 테이블 생성"""
    tables = {}

    # BOJ
    boj_table = "| 난이도 | 풀이 수 |\n| ------ | ------ |\n"
    for level, path in paths["boj"].items():
        boj_table += f"| {level} | {count_files(os.path.join(BASE_DIR, path))} |\n"
    tables["boj"] = boj_table

    # Programmers
    prog_table = "| 난이도 | 풀이 수 |\n| ------ | ------ |\n"
    for level, path in paths["programmers"].items():
        prog_table += f"| {level} | {count_files(os.path.join(BASE_DIR, path))} |\n"
    tables["programmers"] = prog_table

    # SWEA
    swea_table = "| 구분 | 풀이 수 |\n| ---- | ------ |\n"
    for level, path in paths["swea"].items():
        swea_table += f"| {level} | {count_files(os.path.join(BASE_DIR, path))} |\n"
    tables["swea"] = swea_table

    return tables

def update_readme():
    """README.md 파일 내 표를 자동 갱신"""
    tables = generate_table()

    with open(README_PATH, "r", encoding="utf-8") as f:
        content = f.read()

    # BOJ 테이블 교체
    content = re.sub(
        r"(### ✅ Baekjoon Online Judge\n)(\|.*?\n)+",
        "### ✅ Baekjoon Online Judge\n" + tables["boj"],
        content,
        flags=re.DOTALL
    )

    # Programmers 테이블 교체
    content = re.sub(
        r"(### ✅ Programmers\n)(\|.*?\n)+",
        "### ✅ Programmers\n" + tables["programmers"],
        content,
        flags=re.DOTALL
    )

    # SWEA 테이블 교체
    content = re.sub(
        r"(### ✅ SWEA\n)(\|.*?\n)+",
        "### ✅ SWEA\n" + tables["swea"],
        content,
        flags=re.DOTALL
    )

    with open(README_PATH, "w", encoding="utf-8") as f:
        f.write(content)

    print("✅ README.md 업데이트 완료!")

if __name__ == "__main__":
    update_readme()

