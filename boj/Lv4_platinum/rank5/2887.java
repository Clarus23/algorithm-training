import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: 최소 신장 트리(MST), 크루스칼 알고리즘(Kruskal's Algorithm), 그리디(Greedy)
 *	 - N개의 행성을 모두 연결하는 최소 비용을 구하는 MST 문제입니다.
 *	 - 모든 행성 쌍(N*(N-1)/2개)에 대한 간선을 고려하면 간선 수가 O(N²)이 되어 시간 초과가 발생합니다.
 *	 ## 핵심 아이디어: 두 행성 A, B의 연결 비용은 min(|xA-xB|, |yA-yB|, |zA-zB|)입니다.
 *		 - MST에 포함될 간선은 두 행성 사이의 거리가 특정 축(x, y, 또는 z) 방향으로 가장 가까운 간선일 가능성이 높습니다.
 *	 - 따라서 전체 간선을 계산하는 대신, 각 축(x, y, z)에 대해 모든 행성을 개별적으로 정렬합니다.
 *	 - 정렬된 각 리스트에서 인접한 행성끼리만 연결하는 간선들만을 MST 후보로 간주합니다. 이렇게 하면 x, y, z축에 대해 각각 N-1개씩, 총 3*(N-1)개의 간선만 고려하면 됩니다.
 *		(O(N²) -> O(N))
 *	 - 이 O(N)개의 후보 간선들을 대상으로 크루스칼 알고리즘을 적용하여 최종 MST 비용을 구합니다.
 *
 * # 시간복잡도: O(N log N)
 *	 - N은 행성의 수입니다.
 *	 - 각 좌표(x, y, z)에 따라 행성을 정렬하는 데 O(N log N)이 걸립니다.
 *	 - 후보 간선(3*(N-1)개)을 생성하는 데 O(N)이 걸립니다.
 *	 - 생성된 O(N)개의 간선을 크루스칼 알고리즘을 위해 정렬하는 데 O(N log N)이 걸립니다.
 *	 - 유니온 파인드 연산은 O(N * α(N)) 입니다.
 *	 - 따라서 전체 시간 복잡도는 정렬에 의해 O(N log N)이 됩니다.
 *
 * # 메모리: 88,808 kb
 * # 실행시간: 1,924 ms
 * # 체감난이도: 중상
 */

public class Main {
	
	static int n;
	static int[] parent;
	
	static class Pair implements Comparable<Pair> {
		int first, second;

		public Pair(int first, int second) {
			super();
			this.first = first;
			this.second = second;
		}

		@Override
		public int compareTo(Pair o) {
			if(first > o.first) return 1;
			if(first < o.first) return -1; 
			return 0;
		}
		
	}
	
	static class Tunnel implements Comparable<Tunnel>{
		int planetA, planetB;
		int cost;
		public Tunnel(int planetA, int planetB, int cost) {
			super();
			this.planetA = planetA;
			this.planetB = planetB;
			this.cost = cost;
		}
		@Override
		public int compareTo(Tunnel o) {
			if(cost > o.cost) return 1;
			if(cost < o.cost) return -1; 
			return 0;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		parent = new int[n];
		
		// 각각 행성의 x,y,z 좌표와 행성번호를 집어넣을 배열
		Pair[] x = new Pair[n];
		Pair[] y = new Pair[n];
		Pair[] z = new Pair[n];
		for(int i=0; i<n; ++i) {
			parent[i] = -1;
			
			StringTokenizer st = new StringTokenizer(br.readLine());
			x[i] = new Pair(Integer.parseInt(st.nextToken()), i);
			y[i] = new Pair(Integer.parseInt(st.nextToken()), i);
			z[i] = new Pair(Integer.parseInt(st.nextToken()), i);
		}
		
		Arrays.sort(x);
		Arrays.sort(y);
		Arrays.sort(z);
		
		Tunnel[] tunnels = new Tunnel[3*(n-1)];
		for(int i=0; i<n-1; ++i) {
			tunnels[i*3] = new Tunnel(x[i].second, x[i+1].second, Math.abs(x[i].first-x[i+1].first));
			tunnels[i*3 + 1] = new Tunnel(y[i].second, y[i+1].second, Math.abs(y[i].first-y[i+1].first));;
			tunnels[i*3 + 2] = new Tunnel(z[i].second, z[i+1].second, Math.abs(z[i].first-z[i+1].first));;
		} Arrays.sort(tunnels);
		
		int cnt = 0; long cost = 0;
		for(Tunnel tunnel : tunnels) {
			if(cnt >= n-1) break;
			if(!merge(tunnel.planetA, tunnel.planetB)) continue;
			
			++cnt;
			cost += tunnel.cost;
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
