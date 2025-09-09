import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: DP + Binary Search
 * 	- lis[i] -> i번째 길이의 마지막 값 中 최소값.
 * 	- Binary Search를 이용해 lis[] 값을 i마다 update
 * 
 * # 시간복잡도: O(n*log(n))
 * 
 * # 메모리: 28,544 kb
 * # 실행시간: 98 ms
 * # 체감난이도: 하
 */

public class Solution {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int t = Integer.parseInt(br.readLine());
		for(int tc=1; tc<=t; ++tc) {
			int n = Integer.parseInt(br.readLine());
			
			int[] arr = new int[n];
			int[] lis = new int[n];
			
			int size = 0;
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int i=0; i<n; ++i) {
				arr[i] = Integer.parseInt(st.nextToken());
				
				int insert = size;
				int s = 0, e = size;
				while(s < e) {
					int m = (s+e)/2;
					
					if(lis[m] < arr[i]) s = m+1;
					else {
						insert = m;
						e = m;
					}
				}
				
				lis[insert] = arr[i];
				if(insert == size) ++size;
			}
			
			bw.write("#" + tc + " " + size + "\n");
		}
		bw.close();
	}
}
