import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int n;
	static boolean[][] paper;
	
	static int[] numOfColor = {0, 0};
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		
		paper = new boolean[n][n];
		for(int row=0; row<n; ++row) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int col=0; col<n; ++col)
				paper[row][col] = (st.nextToken().charAt(0) == '1');
		}
		
		slice(0, 0, n);
		System.out.print(numOfColor[0] + "\n" + numOfColor[1]);
	}
	
	static void slice(int startR, int startC, int size) {
		boolean isOne = true;
		for(int row=startR; row<startR+size; ++row) {
			for(int col=startC; col<startC+size; ++col) {
				if(paper[row][col] == paper[startR][startC]) continue;
				
				isOne = false;
				break;
			} if(!isOne) break;
		}
		
		if(isOne) {
			++numOfColor[paper[startR][startC] ? 1 : 0];
			return;
		}
		
		size /= 2;
		slice(startR, startC, size);
		slice(startR, startC+size, size);
		slice(startR+size, startC, size);
		slice(startR+size, startC+size, size);
	}
}
