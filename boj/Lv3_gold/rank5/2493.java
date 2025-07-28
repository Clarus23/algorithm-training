import java.io.*;
import java.util.StringTokenizer;
import java.util.Deque;
import java.util.ArrayDeque;

/*
 * 아이디어
 * -> 역방향으로 순회하며
 * -> 현재 타워의 높이가 스택에 저장된 타워의 높이보다 크다면
 * -> 스택에 저장된 타워가 쏜 레이저를 현재 타워에서 수신함.
 * -> 현재 타워를 스택에 저장하고 반복
 * 
 * 시간 복잡도
 * O(N)
 */

public class Main {
	// stack 에 저장할 pair 클래스 정의
	static class Pair {
		int first;
		int second;
		
		Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		// towers 배열에 탑들의 높이 저장
		int[] towers = new int[n];
		for(int i=0; i<n; ++i) towers[i] = Integer.parseInt(st.nextToken());
		
		// stack 구현을 위한 Deque (Last에서만 offer, poll, peek 동작 수행)
		Deque<Pair> stack = new ArrayDeque<>();
		int[] answer = new int[n];
		for(int i=n-1; i>=0; --i) {
			// 현재 탑의 높이가 스택에 저장된 탑의 높이보다 크다면 정답 배열에 현재 탑의 번호 저장
			while(!stack.isEmpty() && towers[i] > stack.peekLast().second)
				answer[stack.pollLast().first] = i+1;
			
			// 현재 탑의 정보 스택에 저장
			stack.offerLast(new Pair(i, towers[i]));
		}
		
		for(int i : answer) bw.write(i + " ");
		bw.flush();
		bw.close();
	}
}
