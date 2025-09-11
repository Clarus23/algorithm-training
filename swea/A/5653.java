import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: Simulation 
 * 	- PriorityQueue를 이용하여 조건에 맞는(가장 먼저 퍼져나가는) 녀석부터 골라내어 시뮬 수행.
 * 
 * # 시간복잡도: O(K * (N+M+K)^2 * log(N+M+K))
 * 
 * # 메모리: 104,668 kb
 * # 실행시간: 374 ms
 * # 체감난이도: 중하
 */

class Solution {
	
	static final int[][] dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
	
	static int n, m, k;
	
	static class Cell implements Comparable<Cell> {
		int hp;
		int row, col;
		int activeTime, deadTime;
		
		public Cell(int hp, int row, int col, int time) {
			super();
			this.hp = hp;
			this.row = row;
			this.col = col;
			
			this.activeTime = time + hp;
			this.deadTime = time + hp*2;
		}

		@Override
		public int compareTo(Cell o) {
			if(this.activeTime > o.activeTime) return 1;
			else if(this.activeTime == o.activeTime && this.hp < o.hp) return 1;
			
			return -1;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int t = Integer.parseInt(br.readLine());
		for(int tc=1; tc<=t; ++tc) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());
			
			int[][] map = new int[n+602][m+602];
			PriorityQueue<Cell> curQ = new PriorityQueue<>();
			
			for(int row=0; row<n; ++row) {
				st = new StringTokenizer(br.readLine());
				for(int col=0; col<m; ++col) {
					map[row+301][col+301] = Integer.parseInt(st.nextToken());
					
					if(map[row+301][col+301] == 0) continue;
					curQ.offer(new Cell(map[row+301][col+301], row+301, col+301, 0));
				}
			}
			
			for(int time=0; time<=k; ++time) {
				PriorityQueue<Cell> nextQ = new PriorityQueue<>();
				
				while(!curQ.isEmpty()) {
					Cell cur = curQ.poll();
					
					if(time == cur.activeTime+1) {
						for(int[] dir : dirs) {
							int nr = cur.row + dir[0];
							int nc = cur.col + dir[1];
							
							if(isOutOfBounds(nr, nc) || map[nr][nc] != 0) continue;
							map[nr][nc] = cur.hp;
							nextQ.offer(new Cell(cur.hp, nr, nc, time));
						}
					} if(time == cur.deadTime) continue;
					
					nextQ.offer(cur);
				}
				
				curQ = nextQ;
			}
			
			bw.write("#" + tc + " " + curQ.size() + "\n");
		}
		
		bw.close();
	}
	
	static boolean isOutOfBounds(int row, int col) {
		return (row < 0 || row >= n+602 || col < 0 || col >= m+602);
	}
}
