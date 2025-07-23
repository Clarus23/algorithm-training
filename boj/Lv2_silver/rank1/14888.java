import java.io.*;
import java.util.StringTokenizer;
import java.util.ArrayDeque;
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
	
	private static class State {
		int[] ops;
		int result;
		int depth;
		
		State(int[] ops, int result, int depth) {
			this.ops = ops.clone();
			this.result = result;
			this.depth = depth;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(br.readLine());
		
		int[] op = new int[4];
		int[] a = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0; i<n; i++) a[i] = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<4; i++) op[i] = Integer.parseInt(st.nextToken());
		
		int min = Integer.MAX_VALUE;
		int max = Integer.MIN_VALUE;
		
		Queue<State> q = new ArrayDeque<>();
		q.offer(new State(op, a[0], 0));
		while(!q.isEmpty()) {
			State cur = q.poll();
			
			if(cur.depth == n-1) {
				min = Math.min(min,  cur.result);
				max = Math.max(max, cur.result);
				continue;
			}
			
			for(int i=0; i<4; ++i) {
				if(cur.ops[i] == 0) continue;
				
				int[] nextOps = cur.ops.clone();
				--nextOps[i];
				
				int nextVal = cur.result;
				if(i == 0) nextVal += a[cur.depth+1];
				else if(i == 1) nextVal -= a[cur.depth+1];
				else if(i == 2) nextVal *= a[cur.depth+1];
				else nextVal /= a[cur.depth+1];
				
				q.offer(new State(nextOps, nextVal, cur.depth+1));
			}
		}
		
		bw.write(max + "\n" + min);
		bw.flush();
		bw.close();
	}
}
