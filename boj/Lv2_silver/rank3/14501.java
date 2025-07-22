import java.io.*;
import java.util.StringTokenizer;

/*
 * DP 문제
 * 
 * Idea
 *  x일에 할 수 있는 선택지
 * 	 1. x일에 상담을 하고 보수를 받는다.
 *   2. x일에 상담을 건너뛴다.
 *  
 *  각각의 경우
 *   1. 상담을 하지 않는다면, dp[x+1]에  dp[x]을 비교하여 큰 값을 저장.
 *   2. 상담을 한다면, dp[x+Tx]에  dp[x] + Px을 비교하여 큰 값을 저장.
 *   => n번 반복.
 *  
 *  dp[n]=> 최고 수익.
 *  
 * 시간 복잡도
 *  입력 : O(N)
 *  dp 수행 : O(N)
 *  출력 : O(1)
 *  => 총 시간 복잡도 : O(N)
 *  
 * 공간 복잡도
 *  입력 : O(2*N)
 *  dp 저장 : O(N)
 *  => 총 공간 복잡도 : O(N)
 */

public class Solution {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(br.readLine());
		
		// 0열 : 기간, 1열 : 수익
		int[][] counseling = new int[n][2];
		for(int i=0; i<n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			counseling[i][0] = Integer.parseInt(st.nextToken());
			counseling[i][1] = Integer.parseInt(st.nextToken());
		}
		
		int[] dp = new int[n+1]; // dp[i] => i일에 얻을 수 있는 최대 수익.
		for(int i=0; i<n; i++) {
			// 오늘 상담을 하지 않는 경우
			dp[i+1] = Math.max(dp[i], dp[i+1]);
			
			// 오늘 상담을 하는 경우
			int next = counseling[i][0]+i;
			if(next <= n) {
				dp[next] = Math.max(dp[next], dp[i]+counseling[i][1]);
			}
		}
		
		bw.write(String.valueOf(dp[n]));
		bw.flush();
		bw.close();
	}
}
