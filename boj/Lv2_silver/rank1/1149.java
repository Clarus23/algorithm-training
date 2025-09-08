import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: DP
 * ## 점화식
 * 	dp[i][0] = Red + min(dp[i-1][1] + dp[i-1][2]) (Red로 칠할 경우)
 * 	dp[i][1] = Green + min(dp[i-1][0] + dp[i-1][2]) (Green으로 칠할 경우)
 *  dp[i][2] = Blue + min(dp[i-1][0] + dp[i-1][1]) (Blue로 칠할 경우)
 * ## 정답 
 *  min(dp[N][0], dp[N][1], dp[N][2])
 *  
 * # 시간복잡도: O(N)
 * 
 * # 메모리: 14,532 kb
 * # 실행시간: 116 ms
 * # 체감난이도: 하
 */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		int[][] dp = new int[n+1][3];
		for(int i=1; i<=n; ++i) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int r = Integer.parseInt(st.nextToken());
			int g = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			dp[i][0] = r + Math.min(dp[i-1][1], dp[i-1][2]);
			dp[i][1] = g + Math.min(dp[i-1][0], dp[i-1][2]);
			dp[i][2] = b + Math.min(dp[i-1][0], dp[i-1][1]);
		}
		
		System.out.print(Math.min(Math.min(dp[n][0], dp[n][1]), dp[n][2]));
	}
}
