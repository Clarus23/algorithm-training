import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

/* # BOJ G3 11779. 최소비용 구하기 2
 * # 풀이 아이디어: Dijkstra + 역추적
 * 	- 각 경로를 갱신할때, 자신과 연결된 노드(부모노드)를 저장해놓는다.
 * 	- 도착지 부터 부모노드의 배열을 역추적하여 경로와, 그 경롤에 속한 노드 수를 구한다.
 * 
 * # 시간복잡도: O(N*log(N))
 * 
 * # 메모리: 49,360 kb
 * # 실행시간: 432 ms
 * # 체감난이도: 중하
 */

public class Main {
	
	static int n, m;
	
	static class Edge implements Comparable<Edge>{
		int to;
		int dist;
		public Edge(int to, int dist) {
			super();
			this.to = to;
			this.dist = dist;
		}
		@Override
		public int compareTo(Edge o) {
			if(this.dist > o.dist) return 1;
			if(this.dist < o.dist) return -1; 
			return 0;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		n = Integer.parseInt(br.readLine());
		m = Integer.parseInt(br.readLine());
		
		List<Edge>[] graph = new ArrayList[n+1];
		for(int i=1; i<=n; ++i) graph[i] = new ArrayList<>();
		
		for(int i=0; i<m; ++i) {
			st = new StringTokenizer(br.readLine());
			
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			int dist = Integer.parseInt(st.nextToken());
			
			graph[from].add(new Edge(to, dist));
		}
		
		st = new StringTokenizer(br.readLine());
		int start = Integer.parseInt(st.nextToken());
		int end = Integer.parseInt(st.nextToken());
		
		int[] myParent = new int[n+1];
		int[] dists = new int[n+1];
		Arrays.fill(dists, Integer.MAX_VALUE);
		PriorityQueue<Edge> pq = new PriorityQueue<>();
		
		pq.offer(new Edge(start, 0));
		dists[start] = 0;
		while(!pq.isEmpty()) {
			Edge cur = pq.poll();
			
			if(dists[cur.to] < cur.dist) continue;
			
			for(Edge next : graph[cur.to]) {
				int nextDist = next.dist + dists[cur.to];
				
				if(nextDist < dists[next.to]) {
					myParent[next.to] = cur.to;
					dists[next.to]= nextDist;
					pq.offer(next);
				}
			}
		}
		
		int size = 0;
		int[] ans = new int[n];
		
		ans[size] = end;
		while(myParent[ans[size++]] != 0) ans[size] = myParent[ans[size-1]];
		
		StringBuilder sb = new StringBuilder();
		sb.append(dists[end]).append("\n").append(size).append("\n");
		while(size != 0) sb.append(ans[--size]).append(" ");
		
		System.out.println(sb);
	}
}
