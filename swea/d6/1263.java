import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: 플로이드 워샬
 * 	- 모든 정점에서 다른 정점까지의 거리 계산
 * 	- 그 중 가장 짧은 거리의 합을 출력
 * 
 * # 시간복잡도: O(N^3)
 * 
 * # 메모리: 101,796 kb
 * # 실행시간: 3,372 ms
 * # 체감난이도: 하
 */

public class Solution {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int t = Integer.parseInt(br.readLine());
		for(int tc=1; tc<=t; ++tc) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int n = Integer.parseInt(st.nextToken());
			
			int[][] humanNet = new int[n][n];
			for(int row=0; row<n; ++row)
				for(int col=0; col<n; ++col)
					humanNet[row][col] = (st.nextToken().charAt(0) == '1') ? 1 : Integer.MAX_VALUE;
			
			for(int i=1; i<n; ++i) {
				for(int from=0; from<n; ++from) {
					if(from == i) continue;
					
					for(int to=0; to<n; ++to) {
						if(to == i || to == from) continue;
						if(humanNet[from][i] == Integer.MAX_VALUE || humanNet[i][to] == Integer.MAX_VALUE) continue;
						
						int cand = humanNet[from][i] + humanNet[i][to];
						humanNet[from][to] = (cand < humanNet[from][to]) ? cand : humanNet[from][to];
					}
				}
			}

			int cc = Integer.MAX_VALUE;
			for(int i=0; i<n; ++i) {
				int cand = 0;
				for(int j=0; j<n; ++j)
					cand += (humanNet[i][j] == Integer.MAX_VALUE) ? 0 : humanNet[i][j];
				
				cc = (cand < cc) ? cand : cc;
			}
			
			bw.write("#" + tc + " " + cc + "\n");
		}
		
		bw.close();
	}
}
