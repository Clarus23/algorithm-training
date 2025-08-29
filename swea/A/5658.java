import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

/*
 * # 풀이 아이디어: TreeSet, sliding window
 * - 원형으로 놓인 숫자들을 처리하기 위해, 입력받은 문자열의 맨 앞 N/4 길이만큼을 복사하여 문자열 뒤에 이어 붙입니다.
 * - 이렇게 하면 원형 배열을 선형으로 간주하고 슬라이딩 윈도우 방식으로 모든 숫자를 추출할 수 있습니다.
 * - 추출한 숫자들의 중복을 제거하고 내림차순으로 정렬하기 위해 TreeSet<String>(Comparator.reverseOrder()) 자료구조를 사용합니다.
 * - 정렬된 Set에서 K번째 값을 찾아 16진수를 10진수로 변환하여 출력합니다.
 *
 * # 시간복잡도: O(N²)
 * - N개의 숫자를 TreeSet에 추가하는 과정이 시간 복잡도를 결정합니다.
 * - 문자열을 자르는 substring 연산이 O(N)이고, TreeSet에 삽입하는 연산이 O(logN)이므로, N번 반복하면 N * (O(N) + O(logN)) 입니다.
 * - 따라서 최종 시간 복잡도는 O(N²)이 됩니다.
 *
 * # 메모리: 27,264 kb
 * # 실행시간: 127 ms
 * # 체감난이도: 하
 */

public class Solution {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int t = Integer.parseInt(br.readLine());
		for(int tc=1; tc<=t; ++tc) {
			Set<String> s = new TreeSet<>(Comparator.reverseOrder());
			
			StringTokenizer st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int k = Integer.parseInt(st.nextToken());
			
			int window = n/4;
			String numbers = br.readLine();
			numbers += numbers.substring(0, window);
			
			for(int i=0; i<n; ++i) s.add(numbers.substring(i, i+window));
			
			int id = 0;
			for(String item : s) {
				if(++id == k) {
					int num = 0; id = 0;
					for(int i=window-1; i>=0; --i) {
						if(item.charAt(i) >= 'A') num += ((10+item.charAt(i)-'A') * Math.pow(16, id++));
						else num += ((item.charAt(i)-'0') * Math.pow(16, id++));
					}
					
					bw.write("#" + tc + " " + num + "\n");
					break;
				}
			}
		}
		bw.close();
	}
}
