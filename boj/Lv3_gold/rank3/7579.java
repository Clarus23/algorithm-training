import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/* # BOJ G3 7579. 앱
 * # 풀이 아이디어: DP
 * 	- 일반적인 knapsack과는 달리 "가방 이상의 용량의" "최소 cost"를 가져와야한다.
 * 	- 여기서 생각을 반대로 하여, 전체 메모리에서 구하려는 m값을 빼고, 읿반적인 knapsack처럼 최대 코스트를 구한다.
 * 
 * # 시간복잡도: O(NM)
 * 
 * # 메모리: 31,092 kb
 * # 실행시간: 856 ms
 * # 체감난이도: 중하
 */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		int memory = -m;
		int totalCost = 0;
		
		int[][] apps = new int[n][2];
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<n; ++i) {
			apps[i][0] = Integer.parseInt(st.nextToken());
			memory += apps[i][0];
		}
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<n; ++i) {
			apps[i][1] = Integer.parseInt(st.nextToken());
			totalCost += apps[i][1];
		}
		
		int[] costs = new int[memory+1];	
		for(int[] app : apps) {
			for(int mem = memory; mem>=0; --mem) {
				if(mem < app[0]) break;
				costs[mem] = Math.max(costs[mem], costs[mem-app[0]] + app[1]);
			}
		}
		
		System.out.print(totalCost - costs[memory]);
	}
}
