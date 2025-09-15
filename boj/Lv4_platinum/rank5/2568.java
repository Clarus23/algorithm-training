import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/* # BOJ G5 2568. 전깃줄 - 2
 * # 풀이 아이디어: DP + LIS + 역추적
 * 	- 모든 전깃줄을 시작 정점을 기준으로 오름차순 정렬한다.
 * 	- 그러면 `겹치지 않는다` == `끝 점이 오름차순이다` 라는걸 알 수 있음
 * 	- 정렬된 전깃줄을 대상으로 최장 증가 부분수열을 구한다.
 * 	- 이는 `남아있는 전깃줄`의 `최대` 개수이므로, 전체 전깃줄의 개수에서 구한 lis의 size를 빼면 정답을 구할 수 있다.
 * 	- 역추적을 수행하며, `최장 증가 부분수열에 포함되지 않는` 원소들을 저장 후 출력한다.
 * 
 * # 시간복잡도: O(N*log(N))
 * 
 * # 메모리: 44,632 kb
 * # 실행시간: 516 ms
 * # 체감난이도: 중
 */

public class Main {
	static class Line implements Comparable<Line> {
		int start, end;

		public Line(int start, int end) {
			super();
			this.start = start;
			this.end = end;
		}

		@Override
		public int compareTo(Line o) {
			return Integer.compare(this.start, o.start);
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		Line[] lines = new Line[n];
		for(int i=0; i<n; ++i) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			lines[i] = new Line(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		} Arrays.sort(lines);
		
		
		int size = 0;
		int[] lis = new int[n];
		int[] idx = new int[n];
		for(int i=0; i<n; ++i) {
			int cur = lines[i].end;
			
			int s=0, e=size;
			while(s < e) {
				int m = (s+e)/2;
				
				if(cur > lis[m]) s = m+1;
				else e = m;
			}
			
			lis[e] = cur;
			idx[i] = e;
			if(e == size) ++size;
		}
		
		int cnt = n - size;
		StringBuilder sb = new StringBuilder();
		sb.append(cnt).append("\n");
		
		int[] ans = new int[cnt];
		int t = size-1;
		for(int i=n-1; i>=0; --i) {
			if(idx[i] != t) ans[--cnt] = lines[i].start;
			else --t;
		}
		
		for(int i=0; i<n-size; ++i) sb.append(ans[i]).append("\n");
		System.out.print(sb);
	}
}	
