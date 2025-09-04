import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Solution {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int t = Integer.parseInt(br.readLine());
		for(int tc=1; tc<=t; ++tc) {
			int[] cost = {0, 0, 0, 0};
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int i=0; i<4; ++i) cost[i] = Integer.parseInt(st.nextToken());
			
			st = new StringTokenizer(br.readLine());
			int[] month = new int[13];
			month[0] = 0;
			for(int i=1; i<=12; ++i) {
				int day = Integer.parseInt(st.nextToken());
				
				month[i] = Math.min(day*cost[0], cost[1]);
				month[i] = Math.min(month[i] + month[i-1], cost[2] + month[(i<=2) ? 0 : (i-3)]);
			}
			
			bw.write("#" + tc + " " + Math.min(cost[3], month[12]) + "\n");
		}
		
		bw.close();
	}
}
