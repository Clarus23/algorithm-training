import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/* # BOJ S2 11048. 이동하기
 * # 풀이 아이디어: Dynamic Programming
 * 
 * # 시간복잡도: O(NM)
 * 
 * # 메모리: 71,716 kb
 * # 실행시간: 468 ms
 * # 체감난이도: 하
 */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		int[][] dp = new int[n+1][m+1];
		for(int row=1; row<=n; ++row) {
			st = new StringTokenizer(br.readLine());
			for(int col=1; col<=m; ++col) {
				dp[row][col] = Integer.parseInt(st.nextToken());
				
				dp[row][col] += Math.max(Math.max(dp[row-1][col], dp[row][col-1]), dp[row-1][col-1]);
			}
		}
		
		System.out.print(dp[n][m]);
	}
}
