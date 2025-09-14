import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

/* # BOJ P4 1854. k번째 최단경로 찾기
 * # 풀이 아이디어: Dijkstra
 * 	- k번째 최단 경로를 찾기 위해, 일반 다익스트라와는 다르게 => dist를 max-heap으로 사용한다.
 * 	## 알고리즘 동작 과정
 * 		1. dijkstra의 탐색 큐(pq) => 일반 dijkstra와 동일 (min-heap, {도착노드, 거리} 저장)
 * 		2. pq에서 {현재노드, **현재까지의 누적 거리**} 꺼냄
 * 		3. 현재 노드와 연결된 다음 노드 경로 계산(거리 = 현재까지의 누적 거리 + 간선 가중치)
 * 		4. 다음 노드의 max-heap(dists[next])를 확인
 * 			a. max-heap의 크기 < k 라면, 경로 추가
 * 			b. max-heap의 크기 == k 라면, 힙의 최댓값(peek()) 보다 짧다면 -> 경로 추가
 * 		5. a, b에서 경로가 추가되면 pq에 그 경로를 삽입.
 * 		이상, pq가 빌때까지 반복.
 * 
 * # 시간복잡도: O(M * k * log(N))
 * 
 * # 메모리: 103,536 kb
 * # 실행시간: 980 ms
 * # 체감난이도: 상
 */

public class Main {
	
	static final int inf = Integer.MAX_VALUE;
	static int n, m, k;
	static List<Edge>[] graph;
	static PriorityQueue<Integer>[] dists;
	
	static class Edge implements Comparable<Edge> {
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
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		
		graph = new ArrayList[n+1];
		for(int i=1; i<=n; ++i) graph[i] = new ArrayList<>();
		for(int i=0; i<m; ++i) {
			st = new StringTokenizer(br.readLine());
			
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			int dist = Integer.parseInt(st.nextToken());
			
			graph[from].add(new Edge(to, dist));
		}
		
		dists = new PriorityQueue[n+1];
		for(int i=1; i<=n; ++i) dists[i] = new PriorityQueue<>(Collections.reverseOrder());
		
		dijkstra(1);
		
		StringBuilder sb = new StringBuilder();
		for(int city = 1; city<=n; ++city)
			sb.append((dists[city].size() < k ? -1 : dists[city].peek())).append("\n");
		
		System.out.print(sb.toString());
	}
	
	static void dijkstra(int start) {
		PriorityQueue<Edge> pq = new PriorityQueue<>();
		
		dists[start].offer(0);
		pq.offer(new Edge(start, 0));
		
		while(!pq.isEmpty()) {
			Edge cur = pq.poll();
			
			for(Edge next : graph[cur.to]) {
				int dist = cur.dist + next.dist;
				
				if(dists[next.to].size() < k) {
					dists[next.to].offer(dist);
					pq.offer(new Edge(next.to, dist));
				} else if(dists[next.to].peek() > dist) {
					dists[next.to].poll();
					dists[next.to].offer(dist);
					pq.offer(new Edge(next.to, dist));
				} else continue;
			}
		}
	}
}
