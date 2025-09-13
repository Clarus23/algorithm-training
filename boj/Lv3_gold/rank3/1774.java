import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

/* # BOJ G3 1774. 우주신과의 교감
 * # 풀이 아이디어: MST(PRIM) + union-find
 * 	- 원래 연결되어 있는 경로들을 먼저 union-find
 * 	- 그 후 PRIM 알고리즘 수행.
 * 	- 만약 find(from) == find(to) 라면, 이미 연결되어있떤 간선, => cost = 0 처리
 * 
 * # 시간복잡도: (N^2 * log(N))
 * 	- 외부 while문 n번 동작
 * 	- 내부 for문 n번 동작
 * 	- priorityQueue 삽입 연산 log(N)
 * 	
 * # 메모리: 35168 kb
 * # 실행시간: 304 ms
 * # 체감난이도: 중
 */

class Main {
	
	static int n, m;
	static int[] parent;
	
	static class Edge implements Comparable<Edge> {
		int to;
		double dist;
		public Edge(int to, double dist) {
			super();
			this.to = to;
			this.dist = dist;
		}
		@Override
		public int compareTo(Edge o) {
			if(this.dist > o.dist) return 1;
			return -1;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		parent = new int[n+1];
		Arrays.fill(parent, -1);
		
		int[][] gods = new int[n+1][2];
		for(int i=1; i<=n; ++i) {
			st = new StringTokenizer(br.readLine());
			gods[i][0] = Integer.parseInt(st.nextToken());
			gods[i][1] = Integer.parseInt(st.nextToken());
		}
		
		for(int i=0; i<m; ++i) {
			st = new StringTokenizer(br.readLine());
			int v1 = Integer.parseInt(st.nextToken());
			int v2 = Integer.parseInt(st.nextToken());
			
			merge(v1, v2);
		}
		
		PriorityQueue<Edge> pq = new PriorityQueue<>();
		boolean[] isVisited = new boolean[n+1];
		double minDist = 0.0; int nodes = 0;
		
		pq.add(new Edge(1, 0));
		while(!pq.isEmpty()) {
			Edge cur = pq.poll();
			
			int from = cur.to;
			if(isVisited[from]) continue;
			
			isVisited[from] = true;
			minDist += cur.dist;
			++nodes;
			
			if(nodes == n) break;
			
			for(int to=1; to<=n; ++to) {
				if(isVisited[to]) continue;
				
				double dist = 0;
				if(find(from) != find(to)) dist = calculateDist(gods[from], gods[to]);
				pq.add(new Edge(to, dist));
			}
		}
		
		System.out.printf("%.2f", minDist);
	}
	static double calculateDist(int[] coord1, int[] coord2) {
		return Math.sqrt(Math.pow((coord1[0] - coord2[0]), 2) + Math.pow((coord1[1] - coord2[1]), 2));
	}
	
	static int find(int x) {
		if(parent[x] < 0) return x;
		return (parent[x] = find(parent[x]));
	}
	static boolean merge(int x, int y) {
		x = find(x); y = find(y);
		if(x == y) return false;
		
		if(parent[x] == parent[y]) --parent[x];
		else if(parent[x] > parent[y]) {
			int tmp = x;
			x = y;
			y = tmp;
		}
		
		parent[y] = x;
		return true;
	}
}


/*////////////////////////////////////////////////////////////////////
위: Prim 알고리즘
아래: Kruskal 알고리즘
///////////////////////////////////////////////////////////////////*/


// import java.io.BufferedReader;
// import java.io.IOException;
// import java.io.InputStreamReader;
// import java.util.ArrayList;
// import java.util.Arrays;
// import java.util.Collections;
// import java.util.List;
// import java.util.StringTokenizer;

// /* # BOJ G3 1774. 우주신과의 교감
//  * # 풀이 아이디어: MST(Kruskal)
//  * 	- 원래 연결되어 있는 경로들을 먼저 union-find
//  * 	- 그 후 kruskal 알고리즘 수행.
//  * 
//  * # 시간복잡도: O(N^2 * log(N))
//  * 	- 모든 간선 계산, 저장 : O(N^2)
//  * 	- 간선 정렬: O(N^2 * log(N))
//  * 	- kruskal 수행: O(N^2 * α(N))
//  * 
//  * # 메모리: 43,556 kb
//  * # 실행시간: 580 ms
//  * # 체감난이도: 중
//  */

// class Main {
	
// 	static int n, m;
// 	static int[] parent;
	
// 	static class Edge implements Comparable<Edge> {
// 		int v1, v2;
// 		double dist;
// 		public Edge(int v1, int v2, double dist) {
// 			super();
// 			this.v1 = v1;
// 			this.v2 = v2;
// 			this.dist = dist;
// 		}
// 		@Override
// 		public int compareTo(Edge o) {
// 			if(this.dist > o.dist) return 1;
// 			return -1;
// 		}
// 	}
	
// 	public static void main(String[] args) throws IOException {
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		StringTokenizer st = new StringTokenizer(br.readLine());
		
// 		n = Integer.parseInt(st.nextToken());
// 		m = Integer.parseInt(st.nextToken());
		
// 		parent = new int[n+1];
// 		Arrays.fill(parent, -1);
		
// 		int[][] gods = new int[n+1][2];
// 		for(int i=1; i<=n; ++i) {
// 			st = new StringTokenizer(br.readLine());
// 			gods[i][0] = Integer.parseInt(st.nextToken());
// 			gods[i][1] = Integer.parseInt(st.nextToken());
// 		}
		
// 		List<Edge> edges = new ArrayList<>();
// 		for(int v1=1; v1<n; ++v1) for(int v2=v1+1; v2<=n; ++v2){
// 			edges.add(new Edge(v1, v2, calculateDist(gods[v1], gods[v2])));
// 		} Collections.sort(edges);
		
// 		double minDist = 0.0; int cnt = 0;
// 		for(int i=0; i<m; ++i) {
// 			st = new StringTokenizer(br.readLine());
// 			int v1 = Integer.parseInt(st.nextToken());
// 			int v2 = Integer.parseInt(st.nextToken());
			
// 			if(merge(v1, v2)) ++cnt;
// 		}
		
// 		for(Edge edge : edges) {
// 			if(cnt == n-1) break;
			
// 			if(!merge(edge.v1, edge.v2)) continue;
// 			minDist += edge.dist;
// 			++cnt;
// 		}
		
// 		System.out.printf("%.2f", minDist);
// 	}
// 	static double calculateDist(int[] coord1, int[] coord2) {
// 		return Math.sqrt(Math.pow((coord1[0] - coord2[0]), 2) + Math.pow((coord1[1] - coord2[1]), 2));
// 	}
	
// 	static int find(int x) {
// 		if(parent[x] < 0) return x;
// 		return (parent[x] = find(parent[x]));
// 	}
// 	static boolean merge(int x, int y) {
// 		x = find(x); y = find(y);
// 		if(x == y) return false;
		
// 		if(parent[x] == parent[y]) --parent[x];
// 		else if(parent[x] > parent[y]) {
// 			int tmp = x;
// 			x = y;
// 			y = tmp;
// 		}
		
// 		parent[y] = x;
// 		return true;
// 	}
// }
