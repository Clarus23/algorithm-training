import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: 시뮬레이션(조합(dfs) + pruning + bfs)
 * 
 * # 메모리: 85,332 kb
 * # 실행시간: 174 ms
 * # 체감난이도: 하
 */

public class Solution {
    
    static final int[][] dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    
    static int n, w, h;
    static int minBricks;
    
    static class Brick {
        int row, col;
        int number;
        public Brick(int row, int col, int number) {
            super();
            this.row = row;
            this.col = col;
            this.number = number;
        }
        public Brick(int[] coord, int number) {
            super();
            this.row = coord[0];
            this.col = coord[1];
            this.number = number;
        }
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int t = Integer.parseInt(br.readLine());
        for(int tc=1; tc<=t; ++tc) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            
            n = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());
            h = Integer.parseInt(st.nextToken());
            
            int bricks = 0;
            int[][] board = new int[h][w];
            for(int row=0; row<h; ++row) {
                st = new StringTokenizer(br.readLine());
                for(int col=0; col<w; ++col) {
                    board[row][col] = Integer.parseInt(st.nextToken());
                    if(board[row][col] != 0) ++bricks;
                }
            }
            
            minBricks = Integer.MAX_VALUE;
            dfs(0, bricks, board);
            
        bw.write("#" + tc + " " + minBricks + "\n");
        }
        bw.close();
    }
    
    static void dfs(int depth, int bricks, int[][] board) {
        if(minBricks == 0) return;
        
        if(depth == n) {
            minBricks = (bricks < minBricks) ? bricks : minBricks;
            return;
        }
        
        for(int col=0; col<w; ++col) {
            int curBricks = bricks;
            int[][] curBoard = new int[h][w];
            for(int i=0; i<h; ++i) System.arraycopy(board[i], 0, curBoard[i], 0, w);
            
            int row = -1;
            while(++row < h && curBoard[row][col] == 0);
            
            Deque<Brick> q = new ArrayDeque<>();
            if(row != h) {
                q.offer(new Brick(row, col, curBoard[row][col]));
                curBoard[row][col] = 0;
            }
            while(!q.isEmpty()) {
                Brick cur = q.poll();
                --curBricks;
                
                for(int[] dir : dirs) {
                    for(int i=1; i<cur.number; ++i) {
                        int[] next = {cur.row + dir[0]*i, cur.col + dir[1]*i};
                        
                        if(isOutOfBounds(next) || curBoard[next[0]][next[1]] == 0) continue;
                        
                        q.offer(new Brick(next, curBoard[next[0]][next[1]]));
                        curBoard[next[0]][next[1]] = 0;
                    }
                }
            }
            
            gravity(curBoard);
            dfs(depth+1, curBricks, curBoard);
        }
    }
    
    
    static void gravity(int[][] board) {
        for(int col = 0; col<w; ++col) {
            int floor = h;
            for(int row=h-1; row>=0; --row) {
                if(board[row][col] != 0) {
                    int temp = board[row][col];
                    board[row][col] = 0;
                    board[--floor][col] = temp;
                }
            }
        }
    }
    
    static boolean isOutOfBounds(int[] coord) {
        return (coord[0] < 0 || coord[0] >= h || coord[1] < 0 || coord[1] >= w);
    }
}    
