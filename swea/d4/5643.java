import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: 플로이드 워샬 
 * 	- 인접 행렬을 만들어 그래프에 대해 플로이드 워샬 알고리즘을 수행한다.
 * 	- [i][j] 는 내가 탐색 한 수, [j][i]는 내가 탐색 받은 수이다.
 * 	- 이를 모두 더했을때, 나를 포함한 개수가 n이라면 내 키를 알 수 있다.
 * 
 * # 시간복잡도: O(N^3)
 * 
 * # 메모리: 101,204 kb
 * # 실행시간: 1,231 ms
 * # 체감난이도: 하
 */

public class Solution {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int t = Integer.parseInt(br.readLine());
		for(int tc=1; tc<=t; ++tc) {
			int n = Integer.parseInt(br.readLine());
			int m = Integer.parseInt(br.readLine());
			
			int[][] matrix = new int[n][n];
			
			for(int i=0; i<m; ++i) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				int from = Integer.parseInt(st.nextToken()) - 1;
				int to = Integer.parseInt(st.nextToken()) - 1;
				
				matrix[from][to] = 1;
			}
			
			for(int i=0; i<n; ++i) {
				for(int from=0; from<n; ++from) {
					for(int to=0; to<n; ++to) {
						if(matrix[from][i] != 1 || matrix[i][to] != 1) continue;
						
						matrix[from][to] = 1;
					}
				}
			}
			
			int ans = 0;
			for(int i=0; i<n; ++i) {
				int cand = 1;
				for(int j=0; j<n; ++j) {
					cand += matrix[i][j];
					cand += matrix[j][i];					
				}
				
				if(cand == n) ++ans;
			}
			
			bw.write("#" + tc + " " + ans + "\n");
		}
		
		bw.close();
	}
}
