import java.io.*;
import java.util.StringTokenizer;

/*
 * backtracking
 * 
 * idea
 * 	m번 dfs를 돌며 수열 출력
 * 	똑같은 수가 또 골라지면 안되기 때문에 isVisited 배열을 이용해 방문 관리
 * 
 * 시간 복잡도
 * 	dfs 수행 => O(NM)
 * 
 */
public class Main {
	static int n, m;
	static boolean[] isVisited;
	static int[] arr;
	
	// 출력 함수
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		// 방문 했는지를 저장하는 isVisited 배열과 실제 수열이 저장될 arr 배열 선언
		isVisited = new boolean[n];
		arr = new int[m];
		
		// dfs 동작
		dfs(0);
		
		// 출력 및 출력 스트림 닫기
		bw.close();
	}
	
	private static void dfs(int depth) throws IOException {
		// depth 가  m과 같으면 출력 후 종료
		if(depth == m) {
			for(int item : arr) {
				bw.write(item + " ");
			} bw.write("\n");
			return;
		}
		
		// dfs 순회 수행
		for(int i=0; i<n; ++i) {
			if(isVisited[i]) continue;
			
			isVisited[i] = true;
			arr[depth] = i+1;
			dfs(depth+1);
			isVisited[i] = false;
		}
	}

}
