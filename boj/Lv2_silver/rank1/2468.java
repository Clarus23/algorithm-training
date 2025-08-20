import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: 강수량에 따른 BFS
 * ## 비가 많이 올수록 칸이 점점 사라짐.
 * ## 배열은 그대로 두고, 강수량과 칸에 적힌 숫자를 이용해 빈칸인지 아닌지 판단(현재 강수량보다 작다면 빈칸 취급)
 * ## 여러번 bfs를 돌려야 하니, isVisited 배열을 각각 선언하여 방문 처리
 * ## 가장 많은 그룹을 업데이트 및 탐색 종료 후 출력
 * 
 * # 시간복잡도: O(N^3)
 * 
 * # 메모리: 96,656 kb
 * # 실행시간: 328 ms
 * # 체감난이도: 하
 */

public class Main {
    
    static final int[][] dirs = new int[][] {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int n = Integer.parseInt(br.readLine());
        
        int[][] map = new int[n][n];
        for(int row=0; row<n; ++row) {
            StringTokenizer st = new StringTokenizer(br.readLine());        
            for(int col=0; col<n; ++col) map[row][col] = Integer.parseInt(st.nextToken());
        }
        
        int maxGroup = 1;
        for(int rain=1; rain<=100; ++rain) {
            boolean[][] isVisited = new boolean[n][n];
            int curGroup = 0;
            
            for(int row=0; row<n; ++row) {
                for(int col=0; col<n; ++col) {
                    if(map[row][col] <= rain || isVisited[row][col]) continue;
                    
                    ++curGroup;
                    
                    Deque<int[]> q = new ArrayDeque<>();
                    q.offer(new int[] {row, col});
                    isVisited[row][col] = true;
                    
                    while(!q.isEmpty()) {
                        int[] cur = q.poll();
                        
                        for(int[] dir : dirs) {
                            int[] next = new int[] {cur[0]+dir[0], cur[1]+dir[1]};
                            
                            if(next[0] < 0 || next[0] >= n || next[1] < 0 || next[1] >=n
                            || isVisited[next[0]][next[1]] || map[next[0]][next[1]] <= rain) continue;
                            
                            isVisited[next[0]][next[1]] = true;
                            q.offer(next);
                        }
                    }
                }
            }
            
            maxGroup = (curGroup > maxGroup) ? curGroup : maxGroup;
        }
        
        bw.write(Integer.toString(maxGroup));
        bw.close();
    }
}