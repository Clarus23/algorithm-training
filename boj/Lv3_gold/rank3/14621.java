import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

/* # BOJ G3 14621. 나만 안되는 연애
 * # 풀이 아이디어: MST(Kruskal)
 * 	- kruskal 을 이용하되, 간선이 남대와 여대끼리 이어야하므로,
 * 		남대 - 남대 간선과, 여대 - 여대 간선은 후보에서 제외한다.
 * 
 * # 시간복잡도: O(M*log(M))
 * 
 * # 메모리: 20,424 kb
 * # 실행시간: 208 ms
 * # 체감난이도: 중하
 */

public class Main {
	
	static int n, m;
	static int[] parents;
	
	static class Edge implements Comparable<Edge> {
		int v1, v2;
		int dist;
		public Edge(int v1, int v2, int dist) {
			super();
			this.v1 = v1;
			this.v2 = v2;
			this.dist = dist;
		}
		@Override
		public int compareTo(Edge o) {
			if(this.dist > o.dist) return 1;
			else if(this.dist < o.dist) return -1;
			return 0;
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		boolean[] colledges = new boolean[n+1];
		for(int i=1; i<=n; ++i) colledges[i] = (st.nextToken().charAt(0) == 'M');
		
		parents = new int[n+1];
		Arrays.fill(parents, -1);
		
		List<Edge> edges = new ArrayList<>();
		for(int i=0; i<m; ++i) {
			st = new StringTokenizer(br.readLine());
			
			int v1 = Integer.parseInt(st.nextToken());
			int v2 = Integer.parseInt(st.nextToken());
			
			if(colledges[v1] == colledges[v2]) continue;
			edges.add(new Edge(v1, v2, Integer.parseInt(st.nextToken())));
		} Collections.sort(edges);
		
		int road = 0; int dist = 0;
		for(Edge edge : edges) {
			if(!merge(edge.v1, edge.v2)) continue;
			
			dist += edge.dist;
			if(++road == n-1) break;
		}
		
		System.out.print((road == n-1) ? dist : -1);
	}
	
	static int find(int x) {
		if(parents[x] < 0) return x;
		return (parents[x] = find(parents[x]));
	}
	static boolean merge(int x, int y) {
		x = find(x); y = find(y);
		if(x == y) return false;
		
		if(parents[x] == parents[y]) --parents[x];
		else if(parents[x] > parents[y]) {
			int tmp = x;
			x = y;
			y = tmp;
		}
		
		parents[y] = x;
		return true;
	}
}
