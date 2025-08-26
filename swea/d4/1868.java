import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Deque;

/*
 * # 풀이 아이디어: 전처리 + bfs
 * ## click을 최소로 하기 위해선 0인 칸들을 미리 알아야 함.
 * ## 그를 찾기 위해 입력받을때 2가지 일을 수행.
 * #### 0. 0으로 초기화된 n*n 배열을 준비함.
 * #### 1. '.' 을 만난다면, click 값을 +1
 * #### 2. '*' 를 만난다면, 주변 8방의 값들을 +1 시켜줌.
 * ## 이후 맵을 차례대로 탐색하며, 0일때마다 bfs를 수행.
 * ## bfs에서 원소들을 만날때마다 click을 -1 (클릭하지 않고 열렸음)
 * ## 마지막에 남은 click값을 출력.
 * 
 * # 시간복잡도: O(n^3)
 * 
 * # 메모리: 75,292 kb
 * # 실행시간: 188 ms
 * # 체감난이도: 하
 */

public class Solution {
    
    static final int[][] dirs = new int[][] {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int t = Integer.parseInt(br.readLine());
        for(int tc=1; tc<=t; ++tc) {
            int n = Integer.parseInt(br.readLine());
            
            int click = 0;
            int[][] map = new int[n][n];
            for(int row=0; row<n; ++row) {
                String temp = br.readLine();
                for(int col=0; col<n; ++col) {
                    char c = temp.charAt(col);
                    
                    if(c == '.') {
                        ++click;
                        continue;
                    }
                    
                    map[row][col] = -1;
                    for(int dir=0; dir<8; ++dir) {
                        int[] fringe = new int[] {row+dirs[dir][0], col+dirs[dir][1]};
                        
                        if(fringe[0] < 0 || fringe[0] >= n || fringe[1] < 0 || fringe[1] >= n || map[fringe[0]][fringe[1]] == -1) continue;
                        ++map[fringe[0]][fringe[1]];
                    }
                }
            }
            
            for(int row=0; row<n; ++row) {
                for(int col=0; col<n; ++col) {
                    if(map[row][col] != 0) continue;
                    
                    map[row][col] = -1;
                    
                    Deque<int[]> q = new ArrayDeque<int[]>();
                    q.offer(new int[] {row, col});
                    while(!q.isEmpty()) {
                        int[] cur = q.poll();
                        
                        for(int dir=0; dir<8; ++dir) {
                            int[] next = new int[] {cur[0]+dirs[dir][0], cur[1]+dirs[dir][1]};
                            if(next[0] < 0 || next[0] >= n || next[1] < 0 || next[1] >= n || map[next[0]][next[1]] == -1) continue;
                            
                            --click;
                            if(map[next[0]][next[1]] == 0) q.offer(next);
                            map[next[0]][next[1]] = -1;
                        }
                    }
                }
            }
            
            bw.write("#" + tc + " " + click + "\n");
        }
        bw.close();
    }
}    