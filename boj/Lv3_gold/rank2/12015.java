import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: DP + Binary Search
 * 	- lis[i] -> i번째 길이의 마지막 값 中 최소값.
 * 	- Binary Search를 이용해 lis[] 값을 i마다 update
 * 
 * # 시간복잡도: O(n*log(n))
 * 
 * # 메모리: 98,996 kb
 * # 실행시간: 600 ms
 * # 체감난이도: 하
 */

public class Main {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		int[] arr = new int[n];
		int[] lis = new int[n];
		
		int size = 0;
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0; i<n; ++i) {
			arr[i] = Integer.parseInt(st.nextToken());
			
			int s = 0, e = size;
			while(s < e) {
				int m = (s+e)/2;
				
				if(lis[m] < arr[i]) s = m+1;
				else e = m;
			}
			
			lis[e] = arr[i];
			if(e == size) ++size;
		}
		
		System.out.print(size);
	}
}	
