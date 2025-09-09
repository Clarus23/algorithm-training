import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: DP
 * 	- 방향에 따른 dp 테이블을 작성.
 * 
 * # 시간복잡도: O(N^2) 
 * 
 * # 메모리: 14,348 kb
 * # 실행시간: 104 ms
 * # 체감난이도: 하
 */

public class Main {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		int[][][] board = new int[3][n][n];
		boolean[][] isWall = new boolean[n][n];
		for(int row=0; row<n; ++row) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int col=0; col<n; ++col) isWall[row][col] = (st.nextToken().charAt(0) == '1');
		}
		
		for(int i=1; i<n; ++i) {
			if(isWall[0][i]) break;
			
			board[0][0][i] = 1;
		}
		
		for(int row=1; row<n; ++row) {
			for(int col=2; col<n; ++col) {
				if(isWall[row][col]) continue;
				
				board[0][row][col] += (board[0][row][col-1] + board[2][row][col-1]);
				board[1][row][col] += (board[1][row-1][col] + board[2][row-1][col]);
				
				if(isWall[row-1][col] || isWall[row][col-1]) continue;
				board[2][row][col] += (board[0][row-1][col-1] + board[1][row-1][col-1] + board[2][row-1][col-1]);
			}
		}
		
		System.out.print(board[0][n-1][n-1] + board[1][n-1][n-1] + board[2][n-1][n-1]);
	}
}	
