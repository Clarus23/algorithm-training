import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: Krusukal algorithm
 * ## edge를 저장하기 위한 클래스 선언, compareTo 메서드 오버라이딩
 * ## union - find 를 이용해 cycle 제거
 * 
 * # 시간복잡도: O(E*logE)
 * 
 * # 메모리: 96,080 kb
 * # 실행시간: 661 ms
 * # 체감난이도: 중하
 */

public class Solution {
    
    static int[] parents;
    
    static double length;
    static int choice;
    
    static class Edge implements Comparable<Edge> {
        int s, e;
        double distance;
        
        public Edge(int s, int e, double distance) {
            super();
            this.s = s;
            this.e = e;
            this.distance = distance;
        }

        @Override
        public int compareTo(Edge o) {
            if(this.distance > o.distance) return 1;
            else if(this.distance < o.distance) return -1;
            return 0;
        }

        @Override
        public String toString() {
            return "Edge [s=" + s + ", e=" + e + ", distance=" + distance + "]";
        }
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int t = Integer.parseInt(br.readLine());
        for(int tc=1; tc<=t; ++tc) {
            int n = Integer.parseInt(br.readLine());
            
            int[][] coord = new int[n][2];
            for(int i=0; i<2; ++i) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for(int j=0; j<n; ++j) coord[j][i] = Integer.parseInt(st.nextToken());
            }
            
            double e  = Double.parseDouble(br.readLine());
            
            parents = new int[n];
            List<Edge> edges = new ArrayList<Solution.Edge>();
            for(int i=0; i<n; ++i) {
                parents[i] = -1;
                for(int j=i+1; j<n; ++j) 
                    edges.add(new Edge(i, j, Math.sqrt(Math.pow((coord[i][0] - coord[j][0]), 2) + Math.pow((coord[i][1] - coord[j][1]), 2))));
            }
                
            
            length = 0; choice = 0;
            Collections.sort(edges);
            for(Edge edge : edges) {
                if(!merge(edge.s, edge.e)) continue;
                
                length += (edge.distance*edge.distance*e);
                if(choice == n-1) break;
            }
            
            bw.write("#" + tc + " " + Math.round(length) + "\n");
        }
        
        bw.close();
    }
    
    static int find(int x) {
        if(parents[x] < 0) return x;
        
        return (parents[x] = find(parents[x]));
    }
    
    static boolean merge(int x, int y) {
        x = find(x); y = find(y);
        
        if(x == y) return false;
        
        if(parents[x] == parents[y]) --parents[x];
        else if(parents[x] > parents[y]) {
            int temp = x;
            x = y;
            y = temp;
        }
        
        parents[y] = x;
        return true;
    }
}    