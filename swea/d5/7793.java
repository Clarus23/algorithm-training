import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: BFS
 * ## 큐에 악마 -> 수연 순서로 집어넣는다.
 * ## 악마가 먼저 이동을 시작하므로, 수연이의 이동관리를 복잡하게 할 필요가 없어진다.
 * ## bfs 탐색을 하며, 수연이가 큐에 몇번 들어있는지를 검사한다. (없으면 "GAME OVER")
 * ## 수연이가 여신님에게 도달했으면, distance를 저장하고 종료 후 출력한다.
 * 
 * # 시간복잡도: O(NM)
 * 
 * # 메모리: 27,136 kb
 * # 실행시간: 95 ms
 * # 체감난이도: 하
 */

public class Solution {
	
	static final int[][] dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

	static int n, m;
	static char[][] map;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int t = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= t; ++tc) {
			StringTokenizer st = new StringTokenizer(br.readLine());

			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());

			map = new char[n][m];
			
			boolean[][] isVisited = new boolean[n][m];
			Deque<int[]> q = new ArrayDeque<>();
			int[] start = null;
			for(int row=0; row<n; ++row) {
				String temp = br.readLine();
				for(int col=0; col<m; ++col) {
					map[row][col] = temp.charAt(col);
					
					if(map[row][col] == 'S') {
						start = new int[] {row, col, 0};
						map[row][col] = '.';
						isVisited[row][col] = true;
					}
					else if(map[row][col] == '*') q.offer(new int[] {row, col, -1});
				}
			} q.offer(start);
			
			
			
			int distance = 0;
			int life = 1; // 수연이의 가능성들.
			while(!q.isEmpty() && life > 0 && distance == 0) {
				int[] cur = q.poll();
				boolean isDevil = (cur[2] == -1);
				
				if(!isDevil) --life;
				
				for(int[] dir : dirs) {
					int[] next = {cur[0]+dir[0], cur[1]+dir[1], (isDevil ? -1 : (cur[2]+1))};
					
					if(isOutOfBounds(next) || (map[next[0]][next[1]] != '.' && map[next[0]][next[1]] != 'D')) continue;
					
					if(isDevil) {
						if(map[next[0]][next[1]] == 'D') continue;
						
						map[next[0]][next[1]] = 'x';
						q.offer(next);
						continue;
					}
					
					if(map[next[0]][next[1]] == 'D') {
						distance = next[2];
						break;
					}
					if(!isVisited[next[0]][next[1]]) {
						++life;
						q.offer(next);
					} isVisited[next[0]][next[1]] = true;
				}
			}
			bw.write("#" + tc + " " + (distance > 0 ? distance : "GAME OVER") + "\n");
		}
		bw.close();
	}
	
	static boolean isOutOfBounds(int[] coord) {
		return (coord[0] < 0 || coord[0] >= n || coord[1] < 0 || coord[1] >= m);
	}
}
