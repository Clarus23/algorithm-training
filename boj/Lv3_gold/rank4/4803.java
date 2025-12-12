import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int[] parents;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int n, m;
		int no = 1;
		while(true) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			
			if(n == 0 && m == 0) break;
			sb.append("Case ").append(no++).append(": ");
			
			parents = new int[n+1];
			for(int i=1; i<=n; ++i) parents[i] = i;
			
			for(int i=0; i<m; ++i) {
				st = new StringTokenizer(br.readLine());
				int u = Integer.parseInt(st.nextToken());
				int v = Integer.parseInt(st.nextToken());
				
				merge(u, v);
			}
			
			int numOfTree = 0;
			for(int i=1; i<=n; ++i) {
				if(parents[i] == i && parents[i] != 0) ++numOfTree;
			}
			
			if(numOfTree > 1) sb.append("A forest of ").append(numOfTree).append(" trees.\n");
			else if(numOfTree == 1) sb.append("There is one tree.\n");
			else sb.append("No trees.\n");
		}
		
		System.out.println(sb);
	}
	
	private static int find(int x) {
		if(parents[x] != x)
			return parents[x] = find(parents[x]);
		return x;
	}
	
	private static void merge(int x, int y) {
		x = find(x);
		y = find(y);
		
		if(x == y) {
			parents[x] = parents[y] = 0;
			return;
		}
		
		if(x < y) {
			int temp = x;
			x = y;
			y = temp;
		}
		
		parents[x] = y;
	}
}
