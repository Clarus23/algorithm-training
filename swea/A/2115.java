import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Solution {
	
	static int n, m, c;
	static int[][] honeyPot;
	static int[][] maxHoney;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int t = Integer.parseInt(br.readLine());
		for(int tc=1; tc<=t; ++tc) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			
			honeyPot = new int[n][n];
			maxHoney = new int[n][n-m+1];
			for(int row=0; row<n; ++row) {
				st = new StringTokenizer(br.readLine());
				for(int col=0; col<n; ++col) honeyPot[row][col] = Integer.parseInt(st.nextToken());
			}
			
			for(int row=0; row<n; ++row) {
				for(int col=0; col<=n-m; ++col) {
					maxHoney[row][col] = maxHoneyFunc(row, col);
				}
			}
			
			int maxMaxProfit = 0;
			for(int selectedRow=0; selectedRow<n; ++selectedRow) {
				for(int selectedCol=0; selectedCol<=n-m; ++selectedCol) {
					int curMaxProfit = 0;
					
					for(int col=selectedCol+m; col<=n-m; ++col)
						curMaxProfit = (maxHoney[selectedRow][col] > curMaxProfit) ? maxHoney[selectedRow][col] : curMaxProfit;
					for(int row=selectedRow+1; row<n; ++row)
						for(int col=0; col<=n-m; ++col)
							curMaxProfit = (maxHoney[row][col] > curMaxProfit) ? maxHoney[row][col] : curMaxProfit;
					
					curMaxProfit += maxHoney[selectedRow][selectedCol];
					maxMaxProfit = (curMaxProfit > maxMaxProfit) ? curMaxProfit : maxMaxProfit;
				}
			}
			
			bw.write("#" + tc + " " + maxMaxProfit + "\n");
		}
		bw.close();
	}
	
	static int maxHoneyFunc(int row, int col) {
		
		int maxProfit = 0;
		for(int subSet=0; subSet<(1<<m); ++subSet) {
			int profit = 0;
			int honey = 0;
			
			for(int i=0; i<m; ++i) {
				if((subSet & (1<<i)) == 0) continue;
				
				honey += honeyPot[row][col+i];
				profit += (honeyPot[row][col+i] * honeyPot[row][col+i]);
				if(honey > c) break;
			}
			
			if(honey > c) continue;
			maxProfit = (profit > maxProfit) ? profit : maxProfit;
		}
		
		return maxProfit;
	}
}
