import java.io.*;
import java.util.StringTokenizer;

/*
 * 풀이 아이디어
 * dynamic programming
 * dp[i][j] => i개의 재료를 가지고 j칼로리를 넘지 않는 최대의 만족도
 * 두가지의 경우가 생김
 * 	1. j가 현재 재료의 칼로리보다 작을 때
 * 		=> 현재 재료가 들어가지 못하니 이전 dp값 그대로 가져옴
 * 	2. j가 현재 재료의 칼로리보다 클 때
 * 		=> 현재 dp에는 칼로리를 저장하지 않아 완벽하게는 찾을 수 없음,
 * 		=> 그러나, dp[i-1][j-[현재 칼로리]] 에는 `무조건` 현재 재료를 추가 가능함. j-[현재 칼로리]보다 적거나 같다는게 이미 증명되어있음
 * 	결론
 * 	=> if: j < foods[i-1][1]
 * 			dp[i][j] = dp[i-1][j]
 *  => else:
 *  		max(foods[i-1][0] + dp[i-1][j-foods[i-1][1]], dp[i-1][j])
 * 
 * 시간 복잡도: O(NL) 
 * 
 * 난이도: 중상
 */

public class Solution {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int testCase = Integer.parseInt(br.readLine());
		for(int t=1; t<=testCase; ++t) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int l = Integer.parseInt(st.nextToken());
			
			// dp 배열 => dp[i][j] = i개의 재료로 j 칼로리를 넘지 않는 최대의 만족도
			int[][] dp = new int[n+1][l+1];
			// 재료의 만족도와 칼로리를 저장한 배열
			// foods[i][0] => i재료의 만족도
			// foods[i][1] => i재료의 칼로리
			int[][] foods = new int[n][2];
			for(int i=0; i<n; ++i) {
				st = new StringTokenizer(br.readLine());
				
				foods[i][0] = Integer.parseInt(st.nextToken());
				foods[i][1] = Integer.parseInt(st.nextToken());
			}
			
			// dp 수행
			for(int i=1; i<=n; ++i) {
				for(int j=0; j<=l; ++j) {
					if(j < foods[i-1][1]) {
						dp[i][j] = dp[i-1][j];
					} else {
						dp[i][j] = Math.max(foods[i-1][0] + dp[i-1][j-foods[i-1][1]], dp[i-1][j]);
					}
				}
			}
			
			// 출력 버퍼링
			sb.append("#").append(t).append(" ").append(dp[n][l]).append("\n");
		}
		
		// 출력
		System.out.print(sb.toString());
	}
}
