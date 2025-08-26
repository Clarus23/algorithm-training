import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: union - find
 * ## 처음에는 모두가 자기 자신만을 안다고 가정한다. (group을 n으로 설정한다)
 * ## 관계도가 들어올때마다 group을 검사하고 다른 그룹이라면 group을 -1 해준 후, 합친다.
 * ## 모든 관계도가 들어왔을때, group의 값이 창용마을의 무리의 개수이다.
 * 
 * # 시간복잡도: O(NM)
 * 
 * # 메모리: 27,648 kb
 * # 실행시간: 96 ms
 * # 체감난이도: 하
 */


public class Solution {
    
    static int n, m;
    static int group;
    static int[] parent;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int t = Integer.parseInt(br.readLine());
        for(int tc=1; tc<=t; ++tc) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            group = n;
            
            parent = new int[n];
            for(int i=0; i<n; ++i) parent[i] = -1;
            
            for(int i=0; i<m; ++i) {
                st = new StringTokenizer(br.readLine());
                
                int x = Integer.parseInt(st.nextToken()) - 1;
                int y = Integer.parseInt(st.nextToken()) - 1;
                
                union(x, y);
            }
            
            bw.write("#" + tc + " " + group + "\n");
        }
        bw.close();
    }
    
    static int find(int x) {
        if(parent[x] < 0) return x;
        
        return (parent[x] = find(parent[x]));
    }
    
    static void union(int x, int y) {
        x = find(x); y = find(y);
        if(x == y) return;
        
        --group;
        if(parent[x] == parent[y]) --parent[x];
        if(parent[x] > parent[y]) {
            int temp = x;
            x = y;
            y = temp;
        }
        
        parent[y] = x;
    }
}    