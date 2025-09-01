import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
	
	static final int[][] dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
	
	static int n, m, k;
	
	static int[][] board;
	static int[] start = {0, 0};
	static int[] end = {0, 0};

	public static void main(String[] args) throws IOException {
		init();
		
		Deque<int[]> q = new ArrayDeque<>();
		
		q.offer(start);
		board[start[0]][start[1]] = 0;
		while(!q.isEmpty()) {
			int[] cur = q.poll();
			
			for(int[] dir : dirs) {
				for(int depth=1; depth<=k; ++depth) {
					int[] next = new int[] {cur[0] + dir[0]*depth, cur[1] + dir[1]*depth};
					
					if(isOutOfBounds(next) || board[next[0]][next[1]] == -1) break;
					if(isEnd(next)) {
						System.out.print(board[cur[0]][cur[1]] + 1);
						return;
					}
					
					if(board[next[0]][next[1]] == board[cur[0]][cur[1]]) break;
					if(board[next[0]][next[1]] > board[cur[0]][cur[1]] + 1) {
						board[next[0]][next[1]] = board[cur[0]][cur[1]] + 1;
						q.offer(next);
					}
				}
			}
		}
		
		System.out.print(-1);
		return;
	}
	
	static boolean isOutOfBounds(int[] coord) {
		return (coord[0] < 0 || coord[0] >= n || coord[1] < 0 || coord[1] >= m);
	}
	static boolean isEnd(int[] coord) {
		return (coord[0] == end[0] && coord[1] == end[1]);
	}
	
	static void init() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		
		board = new int[n][m];
		for(int row=0; row<n; ++row) {
			String temp = br.readLine();
			
			for(int col=0; col<m; ++col) {
				board[row][col] = (temp.charAt(col) == '#' ? -1 : Integer.MAX_VALUE);
			}
		}
		
		st = new StringTokenizer(br.readLine());
		start[0] = Integer.parseInt(st.nextToken())-1;
		start[1] = Integer.parseInt(st.nextToken())-1;
		end[0] = Integer.parseInt(st.nextToken())-1;
		end[1] = Integer.parseInt(st.nextToken())-1;
	}
}
