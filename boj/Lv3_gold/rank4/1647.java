import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: 최소 신장 트리(MST), 크루스칼 알고리즘(Kruskal's Algorithm), 유니온 파인드(Union-Find)
 * 	- 모든 정점을 최소 비용으로 연결하되, 최종적으로 2개의 그룹으로 나누는 문제. 이는 최소 신장 트리(MST)를 구성한 후, 가장 비용이 큰 간선 하나를 제거하는 것과 같습니다.
 * 	- 크루스칼 알고리즘을 사용하여 최소 신장 트리를 찾습니다.
 * 		1. 모든 간선을 비용(weight)에 따라 오름차순으로 정렬합니다.
 * 		2. 비용이 가장 낮은 간선부터 순서대로 확인하며, 사이클을 만들지 않는 간선을 선택합니다.
 * 		3. 사이클 생성 여부는 유니온 파인드(Union-Find) 자료구조를 통해 확인합니다.
 * 		4. 총 N개의 정점이 있을 때, MST는 N-1개의 간선으로 구성됩니다. 이 문제에서는 2개의 그룹을 만들어야 하므로, N-2개의 간선만 선택하여 그 비용의 합을 구합니다.
 *
 * # 시간복잡도: O(M*log(M))
 * 	- E는 간선의 수, V는 정점의 수 라 하면,
 * 	- 간선을 정렬하는 데 O(E log E)의 시간이 소요됩니다.
 * 	- 유니온 파인드 연산은 경로 압축 최적화 시 거의 상수 시간에 가까운 O(α(V))의 시간이 걸리며, 최대 E번 반복합니다.
 * 	- 따라서 전체 시간 복잡도는 간선 정렬 시간에 의해 결정되어 O(E log E)가 됩니다.
 *
 * # 메모리: 337,068 kb
 * # 실행시간: 2,476 ms
 * # 체감난이도: 하
 */

public class Main {
	static int n, m;
	static int[] parent;
	static Edge[] edges;
	
	static class Edge implements Comparable<Edge> {
		int a, b;
		int weight;
		public Edge(int a, int b, int weight) {
			super();
			this.a = a;
			this.b = b;
			this.weight = weight;
		}
		
		@Override
		public int compareTo(Edge o) {
			if(weight > o.weight) return 1;
			else if(weight < o.weight) return -1;
			return 0;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		parent = new int[n];
		for(int i=0; i<n; ++i) parent[i] = -1;
		edges = new Edge[m];
		
		for(int i=0; i<m; ++i) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;
			int cost = Integer.parseInt(st.nextToken());
			
			edges[i] = new Edge(a, b, cost);
		} Arrays.sort(edges);
		
		int cnt = 0; int cost = 0;
		for(Edge edge : edges) {
			if(cnt == n-2) break;
			if(!merge(edge.a, edge.b)) continue;
			
			++cnt;
			cost += edge.weight;
		}
		
		System.out.print(cost);
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
			int temp = x;
			x = y;
			y = temp;
		}
		
		parent[y] = x;
		
		return true;
	}
}
