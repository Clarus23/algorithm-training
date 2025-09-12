import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

/*
 * # SWEA D4 1494. 사랑의 카운슬러
 * # 풀이 아이디어: Combination
 * 	- 절반을 골라 내어 고른 절반의 x,y 값을 모두 더하고, 고르지 않은 절반의 x,y값을 모두 뺀다.
 * 	- 그 후 문제에서 제시된 공식을 따라 벡터의 크기를 구한다.
 * 	- 모든 경우의 수에서 min값을 구한다.
 * 
 * # 시간복잡도: O(N)
 * 
 * # 메모리: 27,648 kb
 * # 실행시간: 171 ms
 * # 체감난이도: 중하
 */

class Solution {
	
	static int n;
	static long[] total, cur;
	static int[][] coord;
	
	static long minVector;
	static boolean[] isSelected;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int t = Integer.parseInt(br.readLine());
		for(int tc=1; tc<=t; ++tc) {
			n = Integer.parseInt(br.readLine());
			
			total = new long[] {0, 0};
			cur = new long[] {0, 0};
			
			coord = new int[n][2];
			isSelected = new boolean[n];
			for(int i=0; i<n; ++i) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				
				coord[i][0] = Integer.parseInt(st.nextToken());
				coord[i][1] = Integer.parseInt(st.nextToken());
				
				for(int j=0; j<2; ++j) total[j] += coord[i][j];
			}
			
			
			minVector = Long.MAX_VALUE;
			combination(0, 0);
			
			bw.write("#" + tc + " " + minVector + "\n");
		}
		bw.close();
	}
	
	static void combination(int idx, int cnt) {
		if(cnt == n/2) {
			long xx = total[0] - 2*cur[0];
			long yy = total[1] - 2*cur[1];
			
			long cand = xx*xx + yy*yy;
			minVector = (cand < minVector) ? cand : minVector;
			
			return;
		}
		
		if(idx >= n) return;
		
		combination(idx+1, cnt);
		
		for(int i=0; i<2; ++i) cur[i] += coord[idx][i];
		combination(idx+1, cnt+1);
		for(int i=0; i<2; ++i) cur[i] -= coord[idx][i];
	}
}
