import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

/* # BOJ G3 2206. 벽 부수고 이동하기
 * # 풀이 아이디어: BFS
 * 
 * # 시간복잡도: O(N^2)
 * 
 * # 메모리: 320,724 kb
 * # 실행시간: 884 ms
 * # 체감난이도: 하
 */

public class Main {
	
	static final int[][] dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
	
	static int n, m;
	
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        
        String[] map = new String[n];
        for(int row=0; row<n; ++row)
        	map[row] = br.readLine();
        
        int[] start = {0, 0, 0, 1};
        if(isGoal(start)) {
        	System.out.print(1);
        	return;
        }
        
        Queue<int[]> q = new ArrayDeque<>();
        boolean[][][] isVisited = new boolean[n][m][2];
        
        q.offer(start);
        isVisited[0][0][0] = true;
        while(!q.isEmpty()) {
        	int[] cur = q.poll();
        	
        	for(int[] dir : dirs) {
        		int[] next = {cur[0] + dir[0], cur[1] + dir[1], cur[2], cur[3]+1};
        		
        		if(isOutOfBounds(next) || isVisited[next[0]][next[1]][next[2]]) continue;
        		if(isGoal(next)) {
        			System.out.print(next[3]);
        			return;
        		}
        		
        		if(map[next[0]].charAt(next[1]) == '1' && next[2] == 1) continue;
        		if(map[next[0]].charAt(next[1]) == '1') next[2] = 1;
        		
        		q.offer(next);
        		isVisited[next[0]][next[1]][next[2]] = true;
        	}
        }
        
        System.out.print(-1);
    }
    
    static boolean isOutOfBounds(int[] coord) {
    	return (coord[0] < 0 || coord[0] >= n || coord[1] < 0 || coord[1] >= m);
    }
    static boolean isGoal(int[] coord) {
    	return (coord[0] == n-1 && coord[1] == m-1);
    }
}