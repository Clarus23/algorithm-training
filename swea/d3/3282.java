import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: DP
 * 	- backpack[i] => i 부피만큼의 최대 가치
 * 
 * # 시간복잡도: O(NK)
 * 
 * # 메모리: 26,496 kb
 * # 실행시간: 97 ms
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
			int k = Integer.parseInt(st.nextToken());
			
			int[][] items = new int[n][2];
			for(int i=0; i<n; ++i) {
				st = new StringTokenizer(br.readLine());
				items[i][0] = Integer.parseInt(st.nextToken());
				items[i][1] = Integer.parseInt(st.nextToken());
			}
			
			int[] backpack = new int[k+1];
			for(int[] item : items) {
				for(int i=k; i>=0; --i) {
					if(item[0] > i) break;
					
					backpack[i] = Math.max(item[1] + backpack[i-item[0]], backpack[i]);
				}
			}
			
			bw.write("#" + tc + " " + backpack[k] + "\n");
		}
		bw.close();
	}
}
