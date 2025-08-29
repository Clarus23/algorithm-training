import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

/*
 * # 풀이 아이디어: 분할 정복(Divide and Conquer), 재귀(Recursion)
 * 주어진 영상(영역)이 모두 같은 값(0 또는 1)으로 이루어져 있는지 확인합니다.
 * 만약 모두 같은 값이라면 해당 값을 출력합니다.
 * 그렇지 않다면, 영역을 4개의 동일한 크기(왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래)로 나누고 각각의 영역에 대해 재귀적으로 이 과정을 반복합니다. 
 * 나누어진 영역들을 표현하기 위해 괄호'()'로 묶어줍니다.
 *
 * # 시간복잡도: O(N²)
 * 최악의 경우(모든 픽셀을 확인해야 하는 경우) 각 픽셀을 한 번씩 방문하게 됩니다.
 * 배열의 크기가 N x N이므로 총 N²개의 픽셀이 있어 시간 복잡도는 O(N²)이 됩니다.
 *
 * # 메모리: 	14,424 kb
 * # 실행시간: 104 ms
 * # 체감난이도: 하
 */

public class Main {
	
	static int[][] movie;
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		
		int n = Integer.parseInt(br.readLine());
		movie = new int[n][n];
		for(int row=0; row<n; ++row) {
			String temp = br.readLine();
			for(int col=0; col<n; ++col) {
				movie[row][col] = temp.charAt(col) - '0';
			}
		}
		
		zipping(0, 0, n, n);
		bw.close();
	}
	
	static void zipping(int startR, int startC, int endR, int endC) throws IOException {
		boolean isOne = true;
		for(int row=startR; row<endR; ++row) {
			for(int col=startC; col<endC; ++col) {
				if(movie[row][col] != movie[startR][startC]) {
					isOne = false;
					break;
				}
			} if(!isOne) break;
		}
		
		if(isOne) bw.write(Integer.toString(movie[startR][startC]));
		else {
			int midR = (startR+endR)/2;	int midC = (startC+endC)/2;
			
			bw.write("(");
			zipping(startR, startC, midR, midC);
			zipping(startR, midC, midR, endC);
			zipping(midR, startC, endR, midC);
			zipping(midR, midC, endR, endC);
			bw.write(")");
		}
	}
}
