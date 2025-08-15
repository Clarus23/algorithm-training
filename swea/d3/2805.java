import java.io.*;

/*
 * Idea
 * - 찾아야 하는 값은 중앙을 기준으로 상하 대칭이다.
 * - i = [0 ~ n/2] 까지 탐색하며  i행 과 (n-1 - i)행 에서 이득을 얻을 값을 계산한다.
 *   + 이득을 얻을 수 있는 값은 각 행에서 [n/2 - i ~ n/2 + i] 에 해당하는 값이다.
 * - i == (n-1 - i)의 경우(i 값이 n/2일 때)는 똑같은 값이 두번 들어가니 중간에 break 문을 삽입한다.
 * 
 * 시간 복잡도 : O(NM) (단, m은 n보다 같거나 작은 정수)
 * 체감 난이도 : 하
 */
public class Solution {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int testCase = Integer.parseInt(br.readLine());
		for(int t=1; t<=testCase; ++t) {		// test case 만큼 반복
			int n = Integer.parseInt(br.readLine());
			
			// 문자열의 1차원 배열로 저장
			String[] field = new String[n];
			for(int row=0; row<n; ++row) field[row] = br.readLine();
			
			// 전체 정답을 저장할 변수
			int revenue = 0;
			for(int i=0; i<=n/2; ++i) {
				// i행, n-1 - i행 에서 해당 값 더하기
				for(int j=n/2 - i; j <= n/2 + i; ++j)
					revenue += (field[i].charAt(j) - '0');
				if(i == n-1-i) break;
				for(int j=n/2 - i; j <= n/2 + i; ++j)
					revenue += (field[n-1-i].charAt(j) - '0');
			}
			
			bw.write("#" + t + " " + revenue + "\n");
		}
		
		bw.close();
	}
}
