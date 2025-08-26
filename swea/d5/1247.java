import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: Brute Force
 * ## 시작점(회사), 끝점(집)을 고정하고 그 사이에 있는 n개의 고객의 집을 순열로 n!가지 구한다.
 * ## 그를 위해 전처리로 n+2 * n+2 matrix를 만들어 거리를 저장해둔다.
 * ## 완전 탐색을 실행한다.
 * 
 * # 시간복잡도: O(N!)
 * 
 * # 메모리: 26,624 kb
 * # 실행시간: 224 ms
 * # 체감난이도: 하
 */


public class Solution {
    
    static int n;
    static int[][] matrix;
    
    static int minLength;
    static boolean[] isVisited;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int t = Integer.parseInt(br.readLine());
        for(int tc=1; tc<=t; ++tc) {
            n = Integer.parseInt(br.readLine());
            
            StringTokenizer st = new StringTokenizer(br.readLine());
            // 0 -> 회사, 1 -> 집, 2~n+1 -> 고객
            int[][] coord = new int[n+2][2];
            for(int i=0; i<n+2; ++i) {
                coord[i][0] = Integer.parseInt(st.nextToken());
                coord[i][1] = Integer.parseInt(st.nextToken());
            }
            
            // 전처리 -> 좌표를 거리로 변경
            matrix = new int[n+2][n+2];
            matrix[0][1] = Integer.MAX_VALUE;
            matrix[1][0] = Integer.MAX_VALUE;
            for(int i=0; i<2; ++i) {
                for(int j=2; j<n+2; ++j) {
                    int diff = Math.abs(coord[i][0] - coord[j][0]) + Math.abs(coord[i][1] - coord[j][1]);
                    matrix[i][j] = diff;
                    matrix[j][i] = diff;
                }
            }
            for(int i=2; i<n+2; ++i) {
                for(int j=2; j<n+2; ++j) {
                    int diff = Math.abs(coord[i][0] - coord[j][0]) + Math.abs(coord[i][1] - coord[j][1]);
                    matrix[i][j] = diff;
                    matrix[j][i] = diff;
                }
            }
            
            isVisited = new boolean[n+2];
            minLength = Integer.MAX_VALUE;
            for(int i=2; i<n+2; ++i) {
                isVisited[i] = true;
                dfs(1, matrix[0][i], i);
                isVisited[i] = false;
            }
            
            bw.write("#" + tc + " " + minLength + "\n");
        }
        
        bw.close();
    }
    
    static void dfs(int depth, int length, int prev) {
        if(length >= minLength) return;
        
        if(depth == n) {
            length += matrix[prev][1];
            minLength = (length < minLength) ? length : minLength;
            return;
        }
        
        for(int i=2; i<n+2; ++i) {
            if(isVisited[i]) continue;
            
            isVisited[i] = true;
            dfs(depth+1, length+matrix[prev][i], i);
            isVisited[i] = false;
        }
    }
}    