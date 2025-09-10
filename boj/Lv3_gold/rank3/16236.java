import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: BFS + 시뮬레이션
 * 	- '먹을 수 있는 물고기'를 bfs를 이용하여 탐색.
 * 	- '먹을 수 있는 물고기'가 여러마리일 경우 우선순위에 따라 사냥.
 * 
 * # 시간복잡도: O(N^4)
 * 
 * # 메모리: 14,624 kb
 * # 실행시간: 108 ms
 * # 체감난이도: 중하
 */

public class Main {
	
	static final int[][] dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
	
	static int n;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		// row, col, 이동 시간
		int[] babyShark = {0, 0, 0};
		int[][] sea = new int[n][n];
		for(int row=0; row<n; ++row) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			for(int col=0; col<n; ++col) {
				sea[row][col] = st.nextToken().charAt(0) - '0';
				
				if(sea[row][col] == 9) {
					sea[row][col] = 0;
					babyShark[0] = row;
					babyShark[1] = col;
				}
			}
		}
		
		int time = 0;
		int sharkSize = 2;
		int eatCnt = 0;
		while(true) {
			Queue<int[]> q = new ArrayDeque<>();
			q.offer(babyShark);
			
			boolean[][] isVisited = new boolean[n][n];
			int[] eatFish = {n, n, Integer.MAX_VALUE};
			while(!q.isEmpty()) {
				int[] cur = q.poll();
				
				if(cur[2] >= eatFish[2]) continue;
				for(int[] dir : dirs) {
					int[] next = {cur[0] + dir[0], cur[1] + dir[1], cur[2]+1};
					
					if(isOutOfBounds(next) || sea[next[0]][next[1]] > sharkSize || isVisited[next[0]][next[1]]) continue;
					
					isVisited[next[0]][next[1]] = true;
					if(sea[next[0]][next[1]] == 0 || sea[next[0]][next[1]] == sharkSize) {
						q.offer(next);
						continue;
					}
					
					if(next[0] < eatFish[0] || (next[0] == eatFish[0] && next[1] < eatFish[1]))
						eatFish = next;
				}
			}
			
			if(eatFish[2] == Integer.MAX_VALUE) break;
			
			sea[eatFish[0]][eatFish[1]] = 0;
			time += eatFish[2];
			if(++eatCnt == sharkSize) {
				eatCnt = 0;
				++sharkSize;
			}
			
			babyShark = eatFish;
			babyShark[2] = 0;
		}
		
		System.out.print(time);
	}
	
	static boolean isOutOfBounds(int[] coord) {
		return (coord[0] < 0 || coord[0] >= n || coord[1] < 0 || coord[1] >= n);
	}
}	
