import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: union - find
 * ## union으로 합치고
 * ## find로 찾는다.
 * 
 * # 메모리: 107,184 kb
 * # 실행시간: 449 ms
 * # 체감난이도: 중하
 */

public class Solution {
    
    static int n, m;
    static int[] parent;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        
        int t = Integer.parseInt(br.readLine());
        for(int tc=1; tc<=t; ++tc) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            
            parent = new int[n];
            for(int i=0; i<n; ++i) parent[i] = -1;
            
            bw.write("#" + tc + " ");
            for(int i=0; i<m; ++i) {
                st = new StringTokenizer(br.readLine());
                int op = Integer.parseInt(st.nextToken());
                int x = Integer.parseInt(st.nextToken()) - 1;
                int y = Integer.parseInt(st.nextToken()) - 1;
                
                if(op == 0) union(find(x), find(y));
                else {
                    x = find(x); y = find(y);
                    bw.write((x == y ? "1" : "0"));
                }
            }
            
            bw.write("\n");
        }
        bw.close();
    }
    
    static int find(int x) {
        if(parent[x] < 0) return x;
        else return (parent[x] = find(parent[x]));
    }
    
    static void union(int x, int y) {
        x = find(x);
        y = find(y);
        
        if(x == y) return;
        
        if(parent[x] == parent[y]) --parent[x];
        if(parent[x] > parent[y]) {
            int temp = x;
            x = y;
            y = temp;
        }
        parent[y] = x;
    }
}    