import java.io.*;
import java.util.StringTokenizer;
import java.util.LinkedList;
import java.util.Queue;

/*
 * Brute Force 문제
 * 
 * Idea
 *  - 주어진 숫자들과 연산자 개수를 이용해 가능한 모든 연산 순서 탐색
 *  - 연산자 순서를 바꿔가며 최대/최소값 구함.
 *  
 *  1. 상태(State)를 정의하여 현재까지 사용한 연산자, 결과값, 깊이를 큐에 저장
 *  2. BFS 를 이용해 완전 탐색
 *  3. 모든 숫자를 사용한 경우, 결과값을 이용해 min/max 갱신.
 *  
 * 시간 복잡도
 *  O(N!)
 */

public class Solution {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		
		Queue<Integer> list = new LinkedList<>();
		for(int i = 1; i <= n; ++i) list.offer(i);
		
		bw.write("<");
		while(list.size() > 1) {
			for(int i = 0; i < k-1; ++i) {
				list.offer(list.poll());
			}
			
			bw.write(list.poll() + ", ");
		}
		bw.write(list.poll() + ">");
		
		bw.flush();
		bw.close();
	}
}
