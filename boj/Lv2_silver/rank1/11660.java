import java.io.*;
import java.util.StringTokenizer;

/*
 * Idea
 * - 2차원 구간합 배열 sum 생성
 * - sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1] 이 구해야 할 합
 * 
 * 시간 복잡도: O(N^2)
 * 메모리: 122356 kb
 * 시간:   748 ms
 * 난이도: 하
 */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		int[][] arr = new int[n+1][n+1];
		int[][] sum = new int[n+1][n+1];
		for(int row=1; row<=n; ++row) {
			st = new StringTokenizer(br.readLine());
			for(int col=1; col<=n; ++col)
				arr[row][col] = Integer.parseInt(st.nextToken());
		}
		
		// 구간 합 배열 설정
		for(int row=1; row<=n; ++row)
			for(int col=1; col<=n; ++col)
				sum[row][col] = arr[row][col] + sum[row-1][col] + sum[row][col-1] - sum[row-1][col-1];
		
		for(int i=0; i<m; ++i) {
			st = new StringTokenizer(br.readLine());
			
			int x1 = Integer.parseInt(st.nextToken());
			int y1 = Integer.parseInt(st.nextToken());
			int x2 = Integer.parseInt(st.nextToken());
			int y2 = Integer.parseInt(st.nextToken());
			
			sb.append(sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1]).append("\n");
		}
		
		System.out.print(sb.toString());
	}
}
