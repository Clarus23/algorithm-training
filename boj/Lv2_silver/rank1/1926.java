import java.io.*;
import java.util.StringTokenizer;
import java.util.Deque;
import java.util.LinkedList;

/*
 * Idea
 * - board 를 하나씩 순회
 * - false(0)를 만나면 => continue
 * - true(1)를 만나면
 *   + ++count
 *   + bfs 수행
 * 	   + 사방을 탐색하며 true를 만나면
 * 	     + ++size
 * 	     + q에 삽입
 * 	     + 이하 반복 
 * - count => 그림의 개수 // size => 각 그림의 크기
 * - maxSize 보다 size가 크다면 update
 * 
 * 시간 복잡도 : O(N^2)
 * 메모리 : 	61928 kb
 * 시간 :		536 ms
 * 체감 난이도 : 하
 */
public class Main {
	// row, col 값을 저장하기 위한 Pair class
	static class Pair {
		int first;
		int second;
		
		Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}
		Pair(Pair p) {
			this.first = p.first;
			this.second = p.second;
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		// 사방 탐색을 위한 dirs 배열
		Pair[] dirs = new Pair[4];
		dirs[0] = new Pair(-1, 0);
		dirs[1] = new Pair(0, -1);
		dirs[2] = new Pair(0, 1);
		dirs[3] = new Pair(1, 0);
		
		// "1" 이면 true / "0" 이면 false 를 저장
		boolean[][] board = new boolean[n][m];
		for(int row=0; row<n; ++row) {
			st = new StringTokenizer(br.readLine());
			for(int col=0; col<m; ++col) {
				board[row][col] = (st.nextToken().equals("1"));
			}
		}
		
		int count = 0;		// 그림의 개수
		int maxSize = 0;	// 그림 중 최대 사이즈
		for(int row=0; row<n; ++row) {
			for(int col=0; col<m; ++col) {
				if(!board[row][col]) continue;
				
				++count;
				Deque<Pair> q = new LinkedList<>();		// bfs 순회를 위한 queue (deque interface, 삽입 삭제가 빈번하니 LinkedList로 구현)
				q.offerLast(new Pair(row, col));
				board[row][col] = false;
				int size = 1;
				while(!q.isEmpty()) {
					Pair cur = q.pollFirst();
					
					for(int d=0; d<4; ++d) {	// 사방 탐색
						Pair fringe = new Pair(cur.first+dirs[d].first, cur.second+dirs[d].second);
						if(fringe.first < 0 || fringe.first >= n					// 배열의 범위를 벗어나거나, 현재 칸이 false 이면 continue
								|| fringe.second < 0 || fringe.second >= m
								|| !board[fringe.first][fringe.second]) continue;
						
						q.offerLast(new Pair(fringe));
						board[fringe.first][fringe.second] = false;
						++size;
					}
				}
				
				maxSize = (size > maxSize) ? size : maxSize;
			}
		}
		bw.write(count + "\n" + maxSize);
		bw.close();
	}
}
