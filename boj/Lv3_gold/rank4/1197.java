import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

/* # BOJ G4 1197. 최소 스패닝 트리
 * # 풀이 아이디어: Kruskal 
 * 
 * # 시간복잡도: O(E*log(E))
 * 
 * # 메모리: 50,812 kb
 * # 실행시간: 528 ms
 * # 체감난이도: 하
 */

class Main {
	
	static int v, e;
	static int[] parent;
	
	static class Edge implements Comparable<Edge> {
		int v1, v2;
		int weight;

		public Edge(int v1, int v2, int weight) {
			super();
			this.v1 = v1;
			this.v2 = v2;
			this.weight = weight;
		}

		@Override
		public int compareTo(Edge o) {
			if(this.weight > o.weight) return 1; 
			return -1;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		v = Integer.parseInt(st.nextToken());
		e = Integer.parseInt(st.nextToken());
		
		parent = new int[v+1];
		Arrays.fill(parent, -1);
		
		List<Edge> edges = new ArrayList<>();
		for(int i=0; i<e; ++i) {
			st = new StringTokenizer(br.readLine());
			int v1 = Integer.parseInt(st.nextToken());
			int v2 = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			
			edges.add(new Edge(v1, v2, w));
		} Collections.sort(edges);
		
		long minDist = 0;
		int connect = 0;
		for(Edge edge : edges) {
			if(!merge(edge.v1, edge.v2)) continue;
			
			minDist += edge.weight;
			++connect;
			if(connect == v-1) break;
		}
		
		System.out.print(minDist);
	}
	
	static int find(int x) {
		if(parent[x] < 0) return x;
		return (parent[x] = find(parent[x]));
	}
	static boolean merge(int x, int y) {
		x = find(x); y = find(y);
		if(x == y) return false;
		
		if(parent[x] == parent[y]) --parent[x];
		if(x > y) {
			int tmp = x;
			x = y;
			y = tmp;
		}
		
		parent[y] = x;
		return true;
	}
}
