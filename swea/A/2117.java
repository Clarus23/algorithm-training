import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

/* # SWEA A 2117. [모의 SW 역량테스트] 홈 방범 서비스
 * # 풀이 아이디어: Brute-force
 * 	- 모든 집들의 위치를 list에 저장한다.
 * 	- 그 후 모든 칸 row, col에 대해서 집들의 거리를 구해 sorting한다.
 * 	- 이익이 나는 k값에 포함되는 집들의 개수 를 maxHouse 변수에 업데이트한다.
 * 		- 이때, maxHouse 개수가 집의 개수와 같다면 탐색을 종료한다.
 * 	- 모든 탐색이 끝난 후, maxHouse 개수를 출력한다.
 * 
 * # 시간복잡도: O(H*N^2) (단, H는 집의 개수)
 * 
 * # 메모리: 42,096 kb
 * # 실행시간: 196 ms
 * # 체감난이도: 하
 */

class Solution {
	
	static class House implements Comparable<House> {
		int row, col;
		int distance;
		
		public House(int row, int col) {
			super();
			this.row = row;
			this.col = col;
		}

		@Override
		public int compareTo(House o) {
			return this.distance - o.distance;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int t = Integer.parseInt(br.readLine());
		for(int tc=1; tc<=t; ++tc) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			
			List<House> houseList = new ArrayList<>();
			for(int row=0; row<n; ++row) {
				st = new StringTokenizer(br.readLine());
				for(int col=0; col<n; ++col) {
					char temp = st.nextToken().charAt(0);
					
					if(temp == '0') continue;
					houseList.add(new House(row, col));
				}
			}

			int maxHouse = 0;
			for(int row=0; row<n; ++row) {
				for(int col=0; col<n; ++col) {
					for(int i=0; i<houseList.size(); i++) {
						House house = houseList.get(i);
						house.distance = (Math.abs(row - house.row) + Math.abs(col - house.col));
					} Collections.sort(houseList);
					
					for(int idx=houseList.size()-1; idx>=0; --idx) {
						int k = houseList.get(idx).distance;
						
						int cost = k*k + (k+1)*(k+1);
						int profit = (idx+1)*m;
						
						if(cost > profit) continue;
						
						maxHouse = ((idx+1) > maxHouse) ? (idx+1) : maxHouse;
						break;
					}
					
					if(maxHouse == houseList.size()) break;
				} if(maxHouse == houseList.size()) break;
			}
			bw.write("#" + tc + " " + maxHouse + "\n");
		}
		
		bw.close();
	}
}
