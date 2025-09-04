import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: BFS
 * - 3차원배열(보드판 + 나이트처럼 뛴 횟수)를 만들어 bfs 수행
 * - 가장 먼저 {row, col}(z값은 상관 x)에 도착하면 정답이다.
 * - 만약, 모두 {row, col}(z값은 상관 x)에 도착하지 못했다면, -1을 출력한다.
 * 
 * # 시간복잡도: O(NMK)
 * 
 * # 메모리: 301,856 kb
 * # 실행시간: 684 ms
 * # 체감난이도: 하
 */

public class Main {
	
	static final int[][] dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}, {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

	static int k, w, h;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		k = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		w = Integer.parseInt(st.nextToken());
		h = Integer.parseInt(st.nextToken());
		
		boolean[][][] map = new boolean[h][w][k+1];
		for(int row=0; row<h; ++row) {
			st = new StringTokenizer(br.readLine());
			for(int col=0; col<w; ++col) {
				map[row][col][0] = (st.nextToken().charAt(0) == '1') ? true : false;
				for(int i=1; i<=k; ++i) map[row][col][i] = map[row][col][0];
			}
		}
		
		Deque<int[]> q = new ArrayDeque<>();
		map[0][0][0] = true;
		q.offer(new int[] {0, 0, 0, 0});
		
		if(isEnd(q.peek())) {
			System.out.print(0);
			return;
		}
		
		while(!q.isEmpty()) {
			int[] cur = q.poll();
			
			for(int dir=0; dir<4; ++dir) {
				int[] next = new int[] {cur[0]+dirs[dir][0], cur[1]+dirs[dir][1], cur[2], cur[3]+1};
				
				if(isOutOfBounds(next) || map[next[0]][next[1]][next[2]]) continue;
				if(isEnd(next)) {
					System.out.print(next[3]);
					return;
				}
				
				map[next[0]][next[1]][next[2]] = true;
				q.offer(next);
			}
			
			// knight 움직임
			if(cur[2] >= k) continue;
			for(int dir=4; dir<12; ++dir) {
				int[] next = new int[] {cur[0]+dirs[dir][0], cur[1]+dirs[dir][1], cur[2]+1, cur[3]+1};
				
				if(isOutOfBounds(next) || map[next[0]][next[1]][next[2]]) continue;
				if(isEnd(next)) {
					System.out.print(next[3]);
					return;
				}
				
				map[next[0]][next[1]][next[2]] = true;
				q.offer(next);
			}
		}
		
		System.out.print(-1);
	}
	static boolean isEnd(int[] coord) {
		return (coord[0] == h-1 && coord[1] == w-1);
	}
	static boolean isOutOfBounds(int[] coord) {
		return (coord[0] < 0 || coord[0] >= h || coord[1] < 0 || coord[1] >= w);
	}
}
