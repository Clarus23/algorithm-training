import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/* # BOJ S3 11727. 2*n 타일링 2
 * # 풀이 아이디어: Dynamic Programming
 * 
 * # 시간복잡도: O(N)
 * 
 * # 메모리: 14,332 kb
 * # 실행시간: 108 ms
 * # 체감난이도: 하
 */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		int[] dp = new int[n+1];
		dp[0] = 1; dp[1] = 1;
		
		for(int i=2; i<=n; ++i)
			dp[i] = (dp[i-1] + dp[i-2]*2)%10007;
		
		System.out.print(dp[n]);
	}
}
