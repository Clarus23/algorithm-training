import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: brute-force
 * 	- 0부터 999,999까지 싹 검사해본다. 
 * 
 * # 시간복잡도: O(1000000)
 * 
 * # 메모리: 33,944 kb
 * # 실행시간: 192 ms
 * # 체감난이도: 중상 
 */

public class Main {
	
	static boolean[] isBreak;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int target = Integer.parseInt(br.readLine());
		int minClick = Math.abs(100 - target);
		
		int m = Integer.parseInt(br.readLine());
		if(m == 0) {
			int cand = Integer.toString(target).length();
			minClick = (cand < minClick) ? cand : minClick;
			System.out.print(minClick);
			return;
		}
		
		isBreak = new boolean[10];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0; i<m; ++i) {
			int tmp = Integer.parseInt(st.nextToken());
			isBreak[tmp] = true;
		}
		
		
		for(int i=0; i<=1000000; ++i) {
			if(minClick == 0) break;
			
			if(!isValid(i)) continue;
			
			int cand = Math.abs(target - i) + Integer.toString(i).length();
			minClick = (cand < minClick) ? cand : minClick;
		}
		
		System.out.print(minClick);
	}
	
	static boolean isValid(int number) {
		if(number == 0 && isBreak[0]) return false; 
		while(number != 0) {
			if(isBreak[number%10]) return false;
			number/=10;
		}
		return true;
	}
}	
