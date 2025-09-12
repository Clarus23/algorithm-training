import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/* # BOJ G3 1719. 택배
 * # 풀이 아이디어: 플로이드 워셜
 * 	- 플로이드 워셜을 이용하여 경로표를 구한다.
 * 
 * # 시간복잡도: O(N^3)
 * 
 * # 메모리: 29,460 kb
 * # 실행시간: 692 ms
 * # 체감난이도: 중하
 */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		int[][] routeTable = new int[n+1][n+1];
		int[][] edges = new int[n+1][n+1];
		for(int i=1; i<=n; ++i) Arrays.fill(edges[i], Integer.MAX_VALUE);
		
		for(int i=0; i<m; ++i) {
			st = new StringTokenizer(br.readLine());
			
			int v1 = Integer.parseInt(st.nextToken());
			int v2 = Integer.parseInt(st.nextToken());
			int dist = Integer.parseInt(st.nextToken());
			
			edges[v1][v2] = dist;
			edges[v2][v1] = dist;
			
			routeTable[v1][v2] = v2;
			routeTable[v2][v1] = v1;
		}
		
		for(int k=1; k<=n; ++k) {
			for(int from=1; from<=n; ++from) {
				if(from == k) continue;
				for(int to=1; to<=n; ++to) {
					if(to == k || to == from) continue;
					
					long cand = (long)edges[from][k] + edges[k][to];
					if(cand < edges[from][to]) {
						routeTable[from][to] = routeTable[from][k];
						edges[from][to] = (int)cand;
					}
				}
			}
		}
		
		for(int row=1; row<=n; ++row) {
			for(int col=1; col<=n; ++col) {
				System.out.print((routeTable[row][col] == 0 ? "-" : routeTable[row][col]) + " ");
			}System.out.println();
		}
	}
}	
