import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어 : 단순 구현
 * ## 반복되는 코드를 줄이고자 map을 사용
 * ## 문제에 나오는 말들을 그대로 구현하면 합격됨.
 * 
 * # 실행 시간 : 101 ms
 * # 메모리 : 27,520 kb
 */

public class Solution {
    
    static int[] drow = {-1, 0, 0, 1};
    static int[] dcol = {0, -1, 1, 0};
    static char[] tankDir = {'^', '<', '>', 'v'};
    
    static Map<Character, Integer> dirs = new HashMap<>();
    
    static class Tank {
        int row, col;
        int dir;
        
        Tank() {}
        Tank(int row, int col, int dir) {
            this.row = row;
            this.col = col;
            this.dir = dir;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        dirs.put('U', 0); dirs.put('^', 0);
        dirs.put('L', 1); dirs.put('<', 1);
        dirs.put('R', 2); dirs.put('>', 2);
        dirs.put('D', 3); dirs.put('v', 3);
        
        int t = Integer.parseInt(br.readLine());
        for(int tc=1; tc<=t; ++tc) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            
            int h = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            
            Tank tank = new Tank();
            char[][] map = new char[h][w];
            for(int row=0; row<h; ++row) {
                String temp = br.readLine();
                for(int col=0; col<w; ++col) {
                    map[row][col] = temp.charAt(col);
                    
                    if(map[row][col] == '^' || map[row][col] == '<' || map[row][col] == '>' || map[row][col] == 'v')
                        tank = new Tank(row, col, dirs.get(map[row][col]));
                }
            }
            
            int n = Integer.parseInt(br.readLine());
            String ops = br.readLine();
            for(int i=0; i<n; ++i) {
                char op = ops.charAt(i);
                int row = tank.row, col = tank.col;
                int dir;
                
                
                if(op == 'S') {
                    dir = tank.dir;
                    
                    while(true) {
                        row += drow[dir];
                        col += dcol[dir];
                        
                        if(row < 0 || row >= h || col < 0 || col >= w
                                || map[row][col] == '#') break;
                        
                        if(map[row][col] == '*') {
                            map[row][col] = '.';
                            break;
                        }
                    }
                    
                    continue;
                }
                
                dir = dirs.get(op);
                row += drow[dir];
                col += dcol[dir];
                
                if(row < 0 || row >= h || col < 0 || col >= w || map[row][col] != '.') {
                    row -= drow[dir];
                    col -= dcol[dir];
                };
                
                map[tank.row][tank.col] = '.'; 
                tank.row = row;
                tank.col = col;
                tank.dir = dir;
                map[tank.row][tank.col] = tankDir[tank.dir]; 
            }
            
            bw.write("#" + tc + " ");
            for(int i=0; i<h; ++i) {
                for(int j=0; j<w; ++j) bw.write(map[i][j]);
                bw.write("\n");
            }
        }
        
        
        bw.close();
    }
}