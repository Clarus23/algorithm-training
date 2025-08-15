import java.io.*;
import java.util.StringTokenizer;

/*
 * Idea
 * - 구간합 배열 sum 생성
 * - sum[e] - sum[s-1] 이 s~e까지의 합
 * 
 * 시간 복잡도: O(N)
 * 메모리: 61356 kb
 * 시간:   644ms
 */

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		int[] num = new int[n+1];	// 입력 받은 숫자
		int[] sum = new int[n+1];	// 구간합
		st = new StringTokenizer(br.readLine());
		for(int i=1; i<=n; ++i) {
			num[i] = Integer.parseInt(st.nextToken());
			sum[i] = num[i] + sum[i-1];	// 구간합 구하기
		}
		
		for(int i=0; i<m; ++i) {
			st = new StringTokenizer(br.readLine());
			
			int s = Integer.parseInt(st.nextToken());
			int e = Integer.parseInt(st.nextToken());
			
			bw.write((sum[e] - sum[s-1]) + "\n");
		}
		
		bw.close();
	}
}
