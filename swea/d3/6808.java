import java.io.*;
import java.util.StringTokenizer;

/*
 * Idea
 * - dfs를 수행하며
 * - 규영이 이기면 point에 plus
 * - 규영이 지면 point에 minus
 * -> 마지막 카드까지 뽑았을때 point가 양수면 규영의 승리, 음수면 규영의 패배
 * 
 * 시간 복잡도 : O(n!)
 * 체감 난이도 : 하
 */
public class Solution {
	// 규영이의 승, 패를 저장할 변수
	static int win, lose;
	// 규영이의 카드와, 인영이의 카드
	static int[] kCard = new int[9];
	static int[] iCard = new int[9];
	// point 가 양수 -> 규영의 점수가 높음
	// point 가 음수 -> 규영의 점수가 낮음
	static int point;
	// dfs시 이미 뽑은 카드인지 확인하기 위한 boolean 배열
	static boolean[] isExist = new boolean[9];
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		int testCase = Integer.parseInt(br.readLine());
		for(int t=1; t<=testCase; ++t) {
			st = new StringTokenizer(br.readLine());
			
			boolean[] existCard = new boolean[18];
			for(int i=0; i<9; ++i) {
				kCard[i] = Integer.parseInt(st.nextToken());
				existCard[kCard[i] - 1] = true;
			}
			int top=0;
			for(int i=0; i<18; ++i)
				if(!existCard[i]) iCard[top++] = i+1;
			
			win = 0; lose = 0; point = 0;
			dfs(0);
			
			bw.write("#" + t + " " + win + " " + lose + "\n");
		}
		
		bw.close();
	}
	
	static void dfs(int depth) {
		// 카드를 모두 뽑았으면 win lose 판단
		if(depth == 9) {
			if(point > 0) ++win;
			else if(point < 0) ++lose;
			return;
		}
		
		for(int i=0; i<9; ++i) {
			if(isExist[i]) continue;
			
			int curPoint = kCard[depth] + iCard[i];
			// 뽑은 카드를 체크하고, 승점 계산 
			isExist[i] = true;
			if(kCard[depth] > iCard[i]) point += curPoint;
			else point -= curPoint;
			
			// dfs 수행
			dfs(depth+1);
			
			// 다시 초기 상태로 되돌림
			isExist[i] = false;
			if(kCard[depth] > iCard[i]) point -= curPoint;
			else point += curPoint;
		}
	}
}
