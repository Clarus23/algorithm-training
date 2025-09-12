import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/* # BOJ G4 1976. 여행 가자
 * # 풀이 아이디어: union - find
 * 
 * # 시간복잡도: O(N^2 * α(N))
 * 
 * # 메모리: 18,612 kb
 * # 실행시간: 156 ms
 * # 체감난이도: 하
 */

public class Main {
	
	static int n, m;
	static int[] parents;
	
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());
        
        parents = new int[n+1];
        Arrays.fill(parents, -1);
        for(int row=1; row<=n; ++row) {
        	st = new StringTokenizer(br.readLine());
        	for(int col=1; col<=n; ++col) {
        		char tmp = st.nextToken().charAt(0);
        		
        		if(tmp == '0') continue;
        		merge(row, col);
        	}
        }
        
        st = new StringTokenizer(br.readLine());
        int group = find(Integer.parseInt(st.nextToken()));
        for(int i=1; i<m; ++i) {
        	if(find(Integer.parseInt(st.nextToken())) == group) continue;
        	
        	System.out.print("NO");
        	return;
        }
        
        System.out.print("YES");
    }
    
    static int find(int x) {
    	if(parents[x] < 0) return x;
    	return parents[x] = find(parents[x]);
    }
    static void merge(int x, int y) {
    	x = find(x); y = find(y);
    	
    	if(x == y) return;
    	
    	if(parents[x] == parents[y]) --parents[x];
    	else if(parents[x] > parents[y]) {
    		int tmp = x;
    		x = y;
    		y = tmp;
    	}
    	
    	parents[y] = x;
    }
}
