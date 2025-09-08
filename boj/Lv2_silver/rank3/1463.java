import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: DP
 * 	- x부터 시작하여 1이 될때까지 min(i*3, i*2, i+1) + 1 을 수행
 * ## 점화식
 * 	- dp[i] = min(dp[i+1], dp[i*3], dp[i*2]) + 1 
 * 
 * # 시간복잡도: O(X) 
 * 
 * # 메모리: 18,196 kb
 * # 실행시간: 114 ms
 * # 체감난이도: 하
 */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int x = Integer.parseInt(br.readLine());
		int[] arr = new int[x+1];
		for(int i=x-1; i>0; --i) {
			int cand1 = (3*i > x) ? Integer.MAX_VALUE : arr[3*i];
			int cand2 = (2*i > x) ? Integer.MAX_VALUE : arr[2*i];
			
			arr[i] = Math.min(cand1, cand2);
			arr[i] = Math.min(arr[i], arr[i+1]);
			++arr[i];
		}
		
		System.out.print(arr[1]);
	}
}
