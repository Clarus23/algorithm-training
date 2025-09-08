import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: BFS 
 * 	- 처음에 행렬의 가장 가장자리부터 bfs를 수행
 * 	- 0이면 bfs를 이어가고 1을 만나면 nextQ에 저장(치즈 개수를 -1)
 * 	- bfs가 끝나면 q를 nextQ로 바꿔침.
 * 	- 치즈개수가 0이 될때까지 반복 수행
 * 
 * # 시간복잡도: O(NM)
 * 
 * # 메모리: 	15,172 kb
 * # 실행시간: 120 ms
 * # 체감난이도: 중하
 */

public class Main {
	
	static final int[][] dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
	
	static int n, m;
	static int[][] board;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		int cnt = 0;
		board = new int[n][m];
		for(int row=0; row<n; ++row) {
			st = new StringTokenizer(br.readLine());
			for(int col=0; col<m; ++col) {
				board[row][col] = Integer.parseInt(st.nextToken());
				if(board[row][col] == 1) ++cnt;
			}
		}
		
		Queue<int[]> q = new ArrayDeque<>();
		for(int row=0; row<n; ++row) {
			q.offer(new int[] {row, 0});
			q.offer(new int[] {row, m-1});
			
			board[row][0] = -1;
			board[row][m-1] = -1;
		}
		for(int col=1; col<m-1; ++col) {
			q.offer(new int[] {0, col});
			q.offer(new int[] {n-1, col});
			
			board[0][col] = -1;
			board[n-1][col] = -1;
		}
		
		int prevCnt=-1, time = 0;
		while(cnt > 0) {
			prevCnt = cnt;
			Queue<int[]> nextQ = new ArrayDeque<>();
			
			while(!q.isEmpty()) {
				int[] cur = q.poll();
				
				for(int[] dir : dirs) {
					int[] next = {cur[0]+dir[0], cur[1]+dir[1]};
					
					if(isOutOfBounds(next) || board[next[0]][next[1]] == -1) continue;
					
					if(board[next[0]][next[1]] == 0) {
						board[next[0]][next[1]] = -1;
						q.offer(next);
						continue;
					}
					
					board[next[0]][next[1]] = -1;
					nextQ.offer(next);
					--cnt;
				}
			}
			
			q = nextQ;
			++time;
		}
		
		System.out.print(time + "\n" + prevCnt);
		
	}
	
	static boolean isOutOfBounds(int[] coord) {
		return (coord[0] < 0 || coord[0] >= n || coord[1] < 0 || coord[1] >= m);
	}
}	
