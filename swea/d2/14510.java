/*
# idea

## 전제 : 홀수일 -> +1, 짝수일 -> +2

## 전제
### 높여야 하는 총 높이를 구함. => diffSum
### 홀수만큼 자라야 하는 나무 개수 구함 => oddTree 
### 높여야 하는 총 높이에 필요한 날을 계산 => day = (diffSum/3)*2 + diffSum%3
### day에 포함된 홀수일을 계산 => oddDay = day/2 + day%2

### 핵심 아이디어
    1. 홀수만큼 자라야 하는 나무는 무조건 홀수일이 포함되어 있어야 한다.
    2. oddTree <= oddDay 라면 day가 최소일이다.
    3. 그렇지 않다면, 홀수일을 oddDay - oddTree 만큼 더 기다려야한다.

### sudo code
     if ) oddDay >= oddTree
        day가 최소 일수.
     else )
        if) day%2 == 1
            => day + (oddTree - oddDay)*2 가 최소 일수
        else)
            => day + (oddTree - oddDay)*2 - 1 이 최소 일수
## 시간 복잡도
    O(T*N)
*/

import java.io.*;
import java.util.StringTokenizer;

public class Solution {
    public static void main(String[] args) throws IOException { // BufferedReader에서 일어날 수 있는 예외 처리
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));   // 표준 입력
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out)); // 표준 출력
        StringTokenizer st; // 문자열 파싱

        int testCase = Integer.parseInt(br.readLine());
        for(int t=1; t<=testCase; t++) {    // O(T)
            int n = Integer.parseInt(br.readLine());

            int[] trees = new int[n];       // 나무의 높이 저장하기 위한 배열
            st = new StringTokenizer(br.readLine());
            int maxH = 0;                   // 최대 높이 저장하기 위한 변수
            for(int i=0; i<n; i++) {        // O(N)
                trees[i] = Integer.parseInt(st.nextToken());    // 배열에 저장
                maxH = (trees[i] > maxH) ? trees[i] : maxH;     // 최대 높이 업데이트
            }

            int diffSum = 0;        // 높여야 하는 총 길이 저장
            int oddTree = 0;        // 홀수만큼 자라야 하는 나무 개수 저장
            for(int tree : trees) { // O(N)
                diffSum += (maxH - tree);
                if((maxH-tree)%2 == 1) ++oddTree;
            }

            int day = (diffSum/3)*2 + diffSum%3;    // 최적일수 계산
            int oddDay = day/2 + day%2;             // 최적일수에 포함된 홀수일 계산

            // 핵심 아이디어 구현
            if(oddDay < oddTree) {
                if(day%2 == 1) day = day + (oddTree - oddDay)*2;
                else day = day + (oddTree - oddDay)*2 - 1;
            }

            bw.write("#" + t + " " + day + "\n");
            bw.flush();
        }

        bw.close();
    }
}