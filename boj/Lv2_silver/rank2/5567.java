import java.io.*;
import java.util.StringTokenizer;
import java.util.List;
import java.util.Deque;
import java.util.LinkedList;

/*
 * Idea
 * - 친구관계를 저장할 배열 friends를 LinkedList로 구현
 * - 0번(상근이)를 q에 넣어 bfs 순회
 * - 상근이와 현재 친구의 거리가 2를 넘어가면 => 부르지 않음
 * - 상근이와 현재 친구의 거리가 1(친구),2(친구의 친구)라면 => 부름
 * 
 * 시간 복잡도 : O(N^2)
 * 메모리 : 	18880 kb
 * 시간 :		164 ms
 * 체감 난이도 : 하
 */
public class Main {
	// q에 저장할 Pair class 구현
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
		int m = Integer.parseInt(br.readLine());
		
		// 결혼식에 불렀는지 여부를 저장할 배열
		boolean[] isAttend = new boolean[n];
		
		// 친구관계 graph를 저장할 2차원 배열(구현체 : LinkedList)
		List<Integer>[] friends = new LinkedList[n];
		for(int i=0; i<n; ++i) friends[i] = new LinkedList<Integer>();
		
		// 차례대로 입력받으며 graph 만들기
		StringTokenizer st;
		for(int i=0; i<m; ++i) {
			 st = new StringTokenizer(br.readLine());
			 int a = Integer.parseInt(st.nextToken()) - 1;
			 int b = Integer.parseInt(st.nextToken()) - 1;
			 
			 friends[a].add(b);
			 friends[b].add(a);
		}
		
		// 실제 결혼식에 참석할 친구수를 저장할 변수
		int attendNum = 0;
		// bfs 순회를 위한 q (인터페이스 : deque, 구현체 linkedlist)
		Deque<Pair> q = new LinkedList<>();
		q.offerLast(new Pair(0,0));
		isAttend[0] = true;
		while(!q.isEmpty()) {
			Pair cur = q.pollFirst();
			
			for(int friend : friends[cur.first]) {
				if(isAttend[friend]) continue;
				
				++attendNum;
				isAttend[friend] = true;
				if(cur.second < 1) q.offerLast(new Pair(friend, cur.second+1));
			}
		}
		
		bw.write(attendNum + "");
		bw.close();
	}
}
