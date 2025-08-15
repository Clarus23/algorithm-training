import java.io.*;
import java.util.StringTokenizer;


/*
 * 풀이 아이디어
 * 
 * 완탐
 *  - 재료 n개의 부분집합 => n개의 bit로 표현 할 수 있는 모든 수 2^n
 *  - x번 bit의 의미 => 1-> x번 재료가 들어갔다, 0-> x번 재료가 들어가지 않았다.
 *  - item[0], item[1]과 bit AND 연산 실행했는데 둘다 0이 아니라면 => 재료쌍이 모두 들어간 햄버거
 *  	=> 사용되면 안되는 햄버거
 *  - 둘중에 하나라도 0이라면 => 둘이 같이 들어가지 않은 햄버거
 *  	=> 사용해도 되는 햄버거 
 * 
 * 시간 복잡도: O(M*2^N) 
 * 메모리: 32920 kb
 * 시간: 388 ms
 * 난이도: 중상
 */

public class Solution {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
		
		int t = Integer.parseInt(br.readLine());
		for(int tc=1; tc<=t; ++tc) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			
			// 제외해야할 음식쌍을 저장할 배열
			int[][] excludes = new int[m][2];
			for(int i=0; i<m; ++i) {
				st = new StringTokenizer(br.readLine());
				
				excludes[i][0] = Integer.parseInt(st.nextToken())-1;
				excludes[i][1] = Integer.parseInt(st.nextToken())-1;
			}
			
			int cnt=0;
			// 0 ~ 2^n-1 까지 반복
			for(int sub=0; sub<(1<<n); ++sub) {
				boolean isPossible = true;
				for(int[] item : excludes) {
					// 1<<x => x번째 비트 item[0]와 item[1]을 비트AND 연산했는데 둘다 0이 아니다 => 둘다 사용되었다.
					if( (sub&(1<<item[0])) != 0 && (sub&(1<<item[1])) != 0 ) {
						isPossible = false;
						break;
					}
				}
				if(isPossible) ++cnt;
			}
			
			sb.append("#").append(tc).append(" ").append(cnt).append("\n");
		}
		
		System.out.println(sb.toString());
	}
}
