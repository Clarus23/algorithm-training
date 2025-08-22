import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: BFS 순회
 * ## bfs 탐색, l 시간을 넘어서면 (== depth가 l보다 크면) 탐색 종료
 * #### 주의! 탐색시 다음 파이프를 확인해서 "연결 되어있는지" 확인 필요.
 * ## 터널의 모양에 따라 탐색할 수 있는 위치가 다르므로 주의 필요.
 * 
 * # 메모리: 28,544 kb
 * # 실행시간: 102 ms
 * # 체감 난이도: 중하
 */

public class Solution {
    
    static int n, m;
    static int r, c, l;
    static int[][] map;
    
    static final int[][] dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    static final int[][] tunels = {
            {},             // 0번 ()
            {0, 1, 2, 3},    // 1번 (상, 좌, 우, 하)
            {0, 3},            // 2번 (상, 하)
            {1, 2},            // 3번 (좌, 우)
            {0, 2},            // 4번 (상, 우)
            {2, 3},            // 5번 (우, 하)
            {1, 3},            // 6번 (좌, 하)
            {0, 1}            // 7번 (상, 좌)
        };
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int t = Integer.parseInt(br.readLine());
        for(int tc=1; tc<=t; ++tc) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            r = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            l = Integer.parseInt(st.nextToken());
            
            map = new int[n][m];
            for(int row=0; row<n; ++row) {
                st = new StringTokenizer(br.readLine());
                for(int col=0; col<m; ++col)
                    map[row][col] = Integer.parseInt(st.nextToken());
            }
            
            if(l == 1) {
                bw.write("#" + tc + " 1\n");
                continue;
            }

            int cnt=1;
            Deque<int[]> q = new ArrayDeque<int[]>();
            map[r][c] *= 10;
            q.offer(new int[] {r, c, 1});
            
            while(!q.isEmpty()) {
                int[] cur = q.poll();
                
                int[] dirId = tunels[map[cur[0]][cur[1]]/10];
                for(int id : dirId) {
                    int[] next = new int[] {cur[0] + dirs[id][0], cur[1] + dirs[id][1], cur[2]+1};
                    
                    if(isRangeOut(next) || map[next[0]][next[1]] == 0 || map[next[0]][next[1]] > 9 || isDisconnected(id, next)) continue;
                    
                    ++cnt;
                    map[next[0]][next[1]] *= 10;
                    if(next[2] < l) q.offer(next);
                }
            }
            
            bw.write("#" + tc + " " + cnt + "\n");
        }
        bw.close();
    }
    
    static boolean isRangeOut(int[] coord) {
        return (coord[0] < 0 || coord[0] >= n || coord[1] < 0 || coord[1] >=m);
    }
    static boolean isDisconnected(int dirId, int[] next) {
        if(dirId == 0 && (map[next[0]][next[1]] != 1 && map[next[0]][next[1]] != 2 && map[next[0]][next[1]] != 5 && map[next[0]][next[1]] != 6)) return true;
        if(dirId == 1 && (map[next[0]][next[1]] != 1 && map[next[0]][next[1]] != 3 && map[next[0]][next[1]] != 4 && map[next[0]][next[1]] != 5)) return true;
        if(dirId == 2 && (map[next[0]][next[1]] != 1 && map[next[0]][next[1]] != 3 && map[next[0]][next[1]] != 6 && map[next[0]][next[1]] != 7)) return true;
        if(dirId == 3 && (map[next[0]][next[1]] != 1 && map[next[0]][next[1]] != 2 && map[next[0]][next[1]] != 4 && map[next[0]][next[1]] != 7)) return true;
        
        return false;
    }
}