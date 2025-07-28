import java.io.*;
import java.util.StringTokenizer;

/*
 * 풀이 아이디어
 * -> 100 by 100 2차원 배열 선언
 * -> 색종이가 덮인 부분 true로 업데이트
 * -> 마지막에 전체 순회하며 true인 부분 개수 세기
 * 
 * 시간복잡도
 * -> 입력 O(1)
 * -> 계산 O(100*N + 10000) => O(N)
 * -> 출력 O(1)
 * => 총 시간 복잡도 O(N)
 */

public class Solution {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        boolean[][] board = new boolean[100][100];        // 색종이가 붙어있는 영역을 저장할 boolean 배열
        
        int n = Integer.parseInt(br.readLine());
        for(int i=0; i<n; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            
            for(int row=r; row<r+10; ++row)                // 색종이가 붙은 영역 true로 업데이트
                for(int col=c; col<c+10; ++col)
                    board[row][col] = true;
        }
        
        int cnt=0;
        for(int row=0; row<100; ++row)                    // 전체 순회하며 색종이가 붙은 영역 개수 세기
            for(int col=0; col<100; ++col)
                if(board[row][col]) ++cnt;
        
        bw.write(String.valueOf(cnt));
        bw.flush();
        
        bw.close();
    }
}