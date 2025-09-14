import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/* # BOJ P5 14003. 가장 긴 증가하는 부분 수열 5
 * # 풀이 아이디어: DP(LIS) + 역추적(Binary Search)
 * 
 * # 시간복잡도: O(N*log(N))
 * 
 * # 메모리: 131,268 kb
 * # 실행시간: 820 ms
 * # 체감난이도: 중하
 */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int n = Integer.parseInt(br.readLine());
		
		int[] arr = new int[n];
		int[] lis = new int[n];
		int[] pointer = new int[n];
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int size = 0;
		for(int i=0; i<n; ++i) {
			arr[i] = Integer.parseInt(st.nextToken());
			
			int s = 0, e = size;
			while(s < e) {
				int m = (s+e)/2;
				
				if(lis[m] < arr[i]) s = m+1;
				else e = m;
			}
			
			lis[e] = arr[i];
			pointer[i] = e;
			if(e == size) ++size;
		}
		
		sb.append(size).append("\n");
		int target = size-1;
		
		int[] stack = new int[size];
		int top = -1;
		
		for(int i=n-1; i>=0; --i) {
			if(pointer[i] != target) continue;
			
			stack[++top] = arr[i];
			--target;
		}
		
		while(top != -1) sb.append(stack[top--]).append(" ");
		System.out.print(sb.toString());
	}
}
