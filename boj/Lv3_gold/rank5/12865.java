import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/* # BOJ G5 12865. 평범한 배낭
 * # 풀이 아이디어: DP
 * 
 * # 시간복잡도: O(NK)
 * 
 * # 메모리: 14,784 kb
 * # 실행시간: 140 ms
 * # 체감난이도: 하
 */


public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		
		int[][] items = new int[n][2];
		for(int i=0; i<n; ++i) {
			st = new StringTokenizer(br.readLine());
			
			for(int j=0; j<2; ++j) items[i][j] = Integer.parseInt(st.nextToken());
		}
		
		int[] dp = new int[k+1];
		for(int[] item : items) {
			for(int w=k; w>=0; --w) {
				if(w < item[0]) break;
				dp[w] = Math.max(dp[w], dp[w-item[0]] + item[1]);
			}
		}
		
		System.out.print(dp[k]);
	}
}	
