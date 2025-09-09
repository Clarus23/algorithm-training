import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*
 * # 풀이 아이디어: DP
 * 	- 기저
 * 		- dp[0] = stairs[0]
 * 		- dp[1] = stairs[1] + stairs[0]
 * 		- dp[2] = stairs[2] + max(stairs[0] + stairs[1])
 * 	- 점화식
 * 		- dp[i] = stairs[i] + max(dp[i-3] + stairs[i-1], dp[i-2]) (단, i >= 3)
 * 	- 유도
 * 		=> 계단을 3개 이상 연속으로 밟을 수 없음, dp[i] 는 i번째 계단을 밟는게 보장되어있음.
 * 			-> i번째 계단을 밟을 수 있는 경우의 수.
 * 				1. i-2를 밟지 않는다, i-1을 밟는다.
 * 				2. i-2를 밟는다, i-1을 밟지 않는다.
 * # 시간복잡도: O(N)
 * 
 * # 메모리: 14,256 kb
 * # 실행시간: 108 ms
 * # 체감난이도: 중상
 */

public class Main {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		int[] stairs = new int[n];
		int[] dp = new int[n];
		
		stairs[0] = dp[0] = Integer.parseInt(br.readLine());
		if(n == 1) {
			System.out.print(dp[n-1]);
			return;
		}
		stairs[1] = Integer.parseInt(br.readLine());
		dp[1] = stairs[1] + stairs[0];
		if(n == 2) {
			System.out.print(dp[n-1]);
			return;
		}
		
		stairs[2] = Integer.parseInt(br.readLine());
		dp[2] = stairs[2] + Math.max(stairs[0], stairs[1]);
		for(int i=3; i<n; ++i) {
			stairs[i] = Integer.parseInt(br.readLine());
			dp[i] = stairs[i] + Math.max(dp[i-3] + stairs[i-1], dp[i-2]);
		}
		
		System.out.print(dp[n-1]);
	}
}	
