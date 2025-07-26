import java.io.*;

/*
 * Idea
 *  - 훼손 되지 않은 isbn 값들을 저장
 *  - 0부터 9까지 값들을 더해가며 10으로 떨어지는 수 찾기
 *  - 10으로 떨어지는걸 만든 수가 바로 정답.
 *  
 * 시간 복잡도
 *  입력 : O(N)
 *  출력 : O(1)
 *  총 시간 복잡도 : O(N)
 *  
 */

public class Solution {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String isbn = br.readLine();
		
		int scratch = 0;
		int check = 0;
		for(int i=0; i<13; ++i) {
			if(isbn.charAt(i) == '*') {
				scratch = i;
				continue;
			} else {
				check += (i%2 == 0) ? isbn.charAt(i)-'0' : (isbn.charAt(i)-'0')*3;
			}
		}
		for(int ans=0; ans<10; ++ans) {
			if(scratch%2 == 0) {
				if((ans + check) % 10 == 0) {
					bw.write(ans + "");
					break;
				}
			} else {
				if((3*ans + check) % 10 == 0) {
					bw.write(ans + "");
					break;
				}
			}
		}
		
		bw.flush();
		bw.close();
	}
}
