import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어 : dijkstra 최소 경로 탐색
 *	- 출발점과 도착점이 정해져있는 최단 경로 찾기.
 *	- 단, 가중치 그래프 라는 점에 주의
 *	- 일반적인 bfs로는 가중치 처리를 하기 힘듦. -> 완탐을 하게 됨.
 *	- 음의 가중치가 존재하지 않음. -> dijkstra algorithm
 *	
 *	- dijkstra를 이용해 최소 경로를 dynamic 하게 업데이트
 *	- 모든 탐색이 끝났을 때, 도착점의 dist는 최소 값.
 *	
 * # 시간복잡도: O(N^2 * logN)
 *
 * # 메모리: 23,408 kb
 * # 시간 : 200 ms
 * # 체감 난이도: 중하
 */

public class Main {
	
	static final int[][] dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
	static int n;
	
	static class Item implements Comparable<Item> {
		int row, col;
		int distance;
		public Item(int row, int col, int distance) {
			super();
			this.row = row;
			this.col = col;
			this.distance = distance;
		}
		
		@Override
		public int compareTo(Item o) {
			if(this.distance > o.distance) return 1;
			if(this.distance < o.distance) return -1;
			return 0;
		}

		@Override
		public String toString() {
			return "Item [row=" + row + ", col=" + col + ", distance=" + distance + "]";
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int problem=0;
		while(true) {
			n = Integer.parseInt(br.readLine());
			if(n == 0) break;
			
			int[][] rupees = new int[n][n];
			for(int row=0; row<n; ++row) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for(int col=0; col<n; ++col) {
					rupees[row][col] = Integer.parseInt(st.nextToken());
				}
			}
			
			int[][] dist = new int[n][n];
			for(int row=0; row<n; ++row) for(int col=0; col<n; ++col) dist[row][col] = Integer.MAX_VALUE;
			
			PriorityQueue<Item> pq = new PriorityQueue<>();
			pq.offer(new Item(0, 0, rupees[0][0]));
			dist[0][0] = rupees[0][0];
			while(!pq.isEmpty()) {
				Item cur = pq.poll();
				
				if(cur.distance > dist[cur.row][cur.col]) continue;
				
				for(int[] dir : dirs) {
					Item next = new Item(cur.row+dir[0], cur.col+dir[1], 0);
					if(isOutOfBounds(next)) continue;
					
					next.distance = cur.distance + rupees[next.row][next.col];
					if(next.distance >= dist[next.row][next.col]) continue;
					
					dist[next.row][next.col] = next.distance;
					pq.offer(next);
				}
			}
			
			bw.write("Problem " + ++problem + ": " + dist[n-1][n-1] + "\n");
		}
		
		bw.close();
	}
	
	static boolean isOutOfBounds(Item coord) {
		return (coord.row < 0 || coord.row >= n || coord.col < 0 || coord.col >= n);
	}
}
