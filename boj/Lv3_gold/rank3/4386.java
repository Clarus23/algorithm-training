import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: 최소 신장 트리(MST), 프림 알고리즘(Prim's Algorithm), 우선순위 큐(Priority Queue)
 *	 - N개의 별(정점)들을 모두 연결하는 최소 비용(간선 가중치의 합)을 찾는 MST 문제입니다.
 *	 - 정점 중심의 알고리즘인 프림 알고리즘을 사용하여 해결합니다.
 *	 	1. 임의의 한 정점(0번 별)을 시작점으로 선택하여 우선순위 큐에 넣습니다.
 *	 	2. 우선순위 큐에서 비용이 가장 작은 간선을 추출합니다. 이 간선에 연결된 정점이 아직 MST에 포함되지 않았다면 다음을 수행합니다.
 *	 	3. 해당 정점을 MST에 포함시키고, 간선의 비용을 총비용에 더합니다.
 *	 	4. 새로 추가된 정점과 아직 MST에 포함되지 않은 다른 모든 정점들 사이의 거리를 계산하여 간선 정보로 우선순위 큐에 추가합니다.
 *	 	5. 모든 정점이 MST에 포함될 때까지 2-4 과정을 반복합니다.
 *
 * # 시간복잡도: O(N² log N)
 *	 - N은 별(정점)의 개수입니다.
 *	 - 프림 알고리즘에서 우선순위 큐를 사용할 때의 시간 복잡도는 O(E log V)입니다. (E: 간선 수, V: 정점 수)
 *	 - 이 문제는 모든 별들이 서로 연결될 수 있는 완전 그래프이므로, 간선의 수 E는 O(N²)입니다.
 *	 - 따라서 전체 시간 복잡도는 O(N² log N)이 됩니다.
 *
 * # 메모리: 14,668 kb
 * # 실행시간: 124 ms
 * # 체감난이도: 중하
 */

public class Main {
	static int n;
	
	static class Edge implements Comparable<Edge>{
		int to;
		double length;
		public Edge(int to, double length) {
			super();
			this.to = to;
			this.length = length;
		}
		
		@Override
		public int compareTo(Edge o) {
			if(length > o.length) return 1;
			if(length < o.length) return -1;
			return 0;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		
		boolean[] isInclude = new boolean[n];
		double[][] stars = new double[n][2];
		for(int i=0; i<n; ++i) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			stars[i][0] = Double.parseDouble(st.nextToken());
			stars[i][1] = Double.parseDouble(st.nextToken());
		}
		
		PriorityQueue<Edge> pq = new PriorityQueue<>();
		pq.add(new Edge(0, 0));
		int cnt = 0; double length = 0;
		while(!pq.isEmpty()) {
			Edge cur = pq.poll();
			if(isInclude[cur.to]) continue;
			
			isInclude[cur.to] = true; 
			++cnt; length += cur.length;
			if(cnt >= n) break;
			
			for(int i=0; i<n; ++i) {
				if(isInclude[i]) continue;
				
				double distance = Math.sqrt(Math.pow(stars[cur.to][0] - stars[i][0], 2) + Math.pow(stars[cur.to][1] - stars[i][1], 2));
				pq.add(new Edge(i, distance));
			}
		}
		
		System.out.printf("%.2f", length);
	}
}
