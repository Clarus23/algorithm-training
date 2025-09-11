import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: DFS
 * ## 다음번 탐색지가 나보다 크기가 적으면 탐색 아니면 탐색하지 않는 dfs
 * ## 하지만, 경로상 딱 한번 최대 k만큼 다음 탐색지를 깎을 수 있음.
 * #### boolean 변수를 이용 깎았는지 안깎았는지 판별
 * #### 현재 노드값 -1을 만들어야 가장 좋다는건 쉽게 알 수 있음.
 * ## 위 전략으로 dfs 탐색 후 최대 경로값 출력.
 * 
 * # 시간복잡도: O(N^2)
 * 
 * # 메모리: 28,012 kb
 * # 수행시간: 99 ms
 * # 난이도: 중하
 */

public class Solution {
    
    static int n, k;
    static int[][] mountains;
    static boolean[][] isVisited;
    static int maxRoad;
    static final int[][] dirs = new int[][] {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int t = Integer.parseInt(br.readLine());
        for(int tc=1; tc<=t; ++tc) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            
            n = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());
            
            int maxValue = 0;
            List<int[]> maxCoords = new ArrayList<>();
            
            mountains = new int[n][n];
            for(int row=0; row<n; ++row) {
                st = new StringTokenizer(br.readLine());
                for(int col=0; col<n; ++col) {
                    mountains[row][col] = Integer.parseInt(st.nextToken());
                    
                    if(mountains[row][col] > maxValue) {
                        maxValue = mountains[row][col];
                        maxCoords = new ArrayList<>();
                    } if(mountains[row][col] == maxValue) maxCoords.add(new int[] {row, col});
                }
            }
            
            maxRoad = 0;
            for(int[] start : maxCoords) {
                isVisited = new boolean[n][n];
                isVisited[start[0]][start[1]] = true;
                
                dfs(start, 1, false);
            }
            
            bw.write("#" + tc + " " + maxRoad + "\n");
        }
        
        bw.close();
    }
    
    static void dfs(int[] cur, int length, boolean isDig) {
        boolean isEnd = true;
        
        for(int[] dir : dirs) {
            int[] next = new int[] {cur[0]+dir[0], cur[1]+dir[1]};
            
            if(next[0] < 0 || next[0] >= n || next[1] < 0 || next[1] >= n || isVisited[next[0]][next[1]]) continue;
            
            int diff = mountains[next[0]][next[1]] - mountains[cur[0]][cur[1]];
            
            if(diff < 0) {
                isEnd = false;
                
                isVisited[next[0]][next[1]] = true;
                dfs(next, length+1, isDig);
                isVisited[next[0]][next[1]] = false;
            } else if(!isDig && (diff < k)) {
                isEnd = false;
                int temp = mountains[next[0]][next[1]];
                
                mountains[next[0]][next[1]] = mountains[cur[0]][cur[1]] -1;
                isVisited[next[0]][next[1]] = true;
                dfs(next, length+1, true);
                mountains[next[0]][next[1]] = temp;
                isVisited[next[0]][next[1]] = false;
            }
        }
        
        if(isEnd) maxRoad = (length > maxRoad) ? length : maxRoad;
    }
}
