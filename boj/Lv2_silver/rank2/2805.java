import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int n, m;
	static int[] trees;
	
	static long height;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken()); 
		m = Integer.parseInt(st.nextToken());
		
		int start = 0; int end = 0;
		st = new StringTokenizer(br.readLine());
		trees = new int[n];
		for(int i=0; i<n; ++i) {
			trees[i] = Integer.parseInt(st.nextToken());
			end = (trees[i] > end) ? trees[i] : end;
		}
		
		while(start <= end) {
			int mid = (start+end)/2;
			
			boolean isBig = false;
			long wood = 0;
			for(int i=0; i<n; ++i) {
				if(trees[i] > mid) wood += (trees[i] - mid);
				if(wood >= m) {
					height = mid;
					isBig = true;
					break;
				}
			}
			
			if(isBig) start = mid+1;
			else end = mid-1;
		}
		
		System.out.print(height);
	}
}
