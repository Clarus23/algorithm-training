import java.io.*;
import java.util.StringTokenizer;

/*
 * Idea
 * - 도착지점(x)부터 역으로 올라가서 도착한 출발점이 정답.
 * 
 * 시간 복잡도 : O(1)
 * 체감 난이도 : 하
 */
public class Solution {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		for(int t=1; t<=10; ++t) {
			int testCase = Integer.parseInt(br.readLine());
			boolean[][] ladder = new boolean[99][100];
			for(int row=0; row<99; ++row) {
				st = new StringTokenizer(br.readLine());
				for(int col=0; col<100; ++col) 
					ladder[row][col] = (st.nextToken().equals("1"));
			}
			
			st = new StringTokenizer(br.readLine());
			int col;
			for(col=0; col<100; ++col) {
				if(st.nextToken().equals("2")) break;
			}
			
			for(int row=98; row>0; --row) {
				if(col < 99 && ladder[row][col+1]) {
					while(col < 99 && ladder[row][col+1]) ++col;
				} else if(col > 0 && ladder[row][col-1]) {
					while(col > 0 && ladder[row][col-1]) --col;
				}
			}
			
			bw.write("#" + testCase + " " + col + "\n");
		}
		
		bw.close();
	}
}
