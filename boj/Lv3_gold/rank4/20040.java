import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int n, m;
	static int[] parents;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		parents = new int[n];
		for(int i=0; i<n; ++i) parents[i] = -1;
		for(int i=0; i<m; ++i) {
			st = new StringTokenizer(br.readLine());
			
			int v1 = Integer.parseInt(st.nextToken());
			int v2 = Integer.parseInt(st.nextToken());
			
			if(merge(v1, v2)) continue;
			
			System.out.print(i+1);
			return;
		}
		
		System.out.print(0);
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
			int temp = x;
			x = y;
			y = temp;
		}
		
		parents[y] = x;
		return true;
	}
}
