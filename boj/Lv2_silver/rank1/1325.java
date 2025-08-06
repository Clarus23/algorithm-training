import java.io.*;
import java.util.StringTokenizer;
import java.util.List;
import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;

/*
 * Idea
 * - 신뢰할 수 있는 컴퓨터의 방향 그래프 list로 구현
 * - 1 부터 n까지를 root로 bfs 수행
 * - cnt값 업데이트 하며 각각 배열에 얼마나 해킹할 수 있는지 저장
 * - 업데이트된 max cnt값과 같은 수를 해킹할 수 있는 컴퓨터들 출력
 * 
 * 시간 복잡도 : O(N^2)
 * 메모리 : 	314892 kb
 * 시간 :		10716 ms
 * 체감 난이도 : 하
 */
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		// graph로 이용할 배열 선언
		List<Integer>[] graph = new ArrayList[n+1];
		for(int i=1; i<=n; ++i) graph[i] = new ArrayList<>();
		
		// 방향 그래프
		for(int i=0; i<m; ++i) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			graph[Integer.parseInt(st.nextToken())].add(a);
		}
		
		// 최대 해킹 값 저장할 max 변수
		int max = 0;
		// 각각 얼마나 해킹 했는지를 저장할 배열
		int[] hackedCom = new int[n+1];
		// 1 ~ n 까지 bfs 수행
		for(int i=1; i<=n; ++i) {
			Deque<Integer> q = new LinkedList<>();
			boolean[] isHacked = new boolean[n+1];
			int cnt = 1;
			
			isHacked[i] = true;
			q.offerLast(i);
			while(!q.isEmpty()) {
				int cur = q.pollFirst();
				
				for(int com : graph[cur]) {
					if(isHacked[com]) continue;
					
					++cnt;
					isHacked[com] = true;
					q.offerLast(com);
				}
			}
			// max 값 업데이트, 해킹한 컴퓨터 수 저장
			hackedCom[i] = cnt;
			max = (cnt > max) ? cnt : max;
		}
		// 출력
		for(int i=1; i<=n; ++i) {
			if(hackedCom[i] < max) continue;
			bw.write(i + " ");
		}
		
		bw.close();
	}
}
