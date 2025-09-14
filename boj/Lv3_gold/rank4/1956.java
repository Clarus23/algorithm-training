import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/* # BOJ G4 1956. 운동
 * # 풀이 아이디어: Floyd-Warshall
 * 	- 최소 dist의 cycle을 찾아야하는 문제.
 * 	- floyd-warshall을 응용하여, 자기 자신으로 가는 최소 경로를 구함.
 * 	- 모든 정점의 자기 자신으로 가는 최소 경로 중 최소 경로를 출력.
 * 	- 만약 cycle이 존재하지 않는 그래프라면 => -1을 출력
 * 
 * # 시간복잡도: O(V^3)
 * 
 * # 메모리: 58,472 kb
 * # 실행시간: 540 ms
 * # 체감난이도: 하
 */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int v = Integer.parseInt(st.nextToken());
		int e = Integer.parseInt(st.nextToken());
		
		int[][] dists = new int[v+1][v+1];
		for(int i=1; i<=v; ++i) Arrays.fill(dists[i], Integer.MAX_VALUE);
		
		for(int i=0; i<e; ++i) {
			st = new StringTokenizer(br.readLine());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			
			dists[from][to] = Integer.parseInt(st.nextToken());
		}
		
		for(int k=1; k<=v; ++k) {
			for(int from=1; from<=v; ++from) {
				if(k == from) continue;
				for(int to=1; to<=v; ++to) {
					if(k == to) continue;
					
					long dist = (long)dists[from][k] + dists[k][to];
					dists[from][to] = (dist < dists[from][to]) ? (int)dist : dists[from][to];
				}
			}
		}
		
		int minPath = Integer.MAX_VALUE;
		for(int i=1; i<=v; ++i) minPath = (dists[i][i] < minPath) ? dists[i][i] : minPath;
		
		System.out.print((minPath == Integer.MAX_VALUE ? -1 : minPath));
	}
}
