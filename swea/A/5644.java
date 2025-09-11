import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.StringTokenizer;

public class Solution {
    
    static int m, a;
    static int[] bc;
    static int[][] map;
    static final int[][] dirs = new int[][] {{0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    static class User {
        int row, col;
        int[] move;
        
        User(int row, int col, int[] move) {
            this.row = row;
            this.col = col;
            this.move = Arrays.copyOf(move, move.length);
        }
        
        void move(int time) {
            row += dirs[move[time]][0];
            col += dirs[move[time]][1];
        }
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int t = Integer.parseInt(br.readLine());
        
        for(int tc=1; tc<=t; ++tc) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            
            m = Integer.parseInt(st.nextToken());
            a = Integer.parseInt(st.nextToken());
            
            User[] users = new User[2];
            int[] startTemp = new int[] {0, 9};
            for(int i=0; i<2; ++i) {
                st = new StringTokenizer(br.readLine());
                int[] move = new int[m+1];
                
                for(int j=1; j<=m; ++j) move[j] = Integer.parseInt(st.nextToken());
                
                users[i] = new User(startTemp[i], startTemp[i], move);
            }
            
            map = new int[10][10];
            bc = new int[a+1];
            for(int idx=1; idx<=a; ++idx) {
                st = new StringTokenizer(br.readLine());
                
                int col = Integer.parseInt(st.nextToken()) - 1;
                int row = Integer.parseInt(st.nextToken()) - 1;
                int coverage = Integer.parseInt(st.nextToken());
                bc[idx] = Integer.parseInt(st.nextToken());
                
                Deque<int[]> q = new ArrayDeque<>();
                q.offer(new int[] {row, col, 0});
                
                map[row][col] |= (1<<idx);
                
                while(!q.isEmpty()) {
                    int[] cur = q.poll();
                    
                    for(int i=1; i<=4; ++i) {
                        int[] next = new int[] {cur[0]+dirs[i][0], cur[1]+dirs[i][1], cur[2]+1};
                        
                        if(next[0] < 0 || next[0] >= 10 || next[1] < 0 || next[1] >= 10
                        || ((map[next[0]][next[1]] & (1<<idx)) != 0)) continue;
                        
                        map[next[0]][next[1]] |= (1<<idx);
                        
                        if(next[2] < coverage) q.offer(next);
                    }
                }
            }
            
            int power = 0;
            for(int time=0; time<=m; ++time) {
                for(int i=0; i<2; ++i) users[i].move(time);
                power += charge(users[0].row, users[0].col, users[1].row, users[1].col);
            }
            
            bw.write("#" + tc + " " + power + "\n");
        }
        bw.close();
    }
    
    static int charge(int arow, int acol, int brow, int bcol) {
        int aBatteryMask = map[arow][acol];
        int bBatteryMask = map[brow][bcol];

        int maxPower = 0;

        // 모든 BC 조합(i, j)에 대해 최대 충전량 계산.
        // i: 사용자 A가 선택할 BC, j: 사용자 B가 선택할 BC
        for (int i = 0; i <= a; i++) {
            for (int j = 0; j <= a; j++) {
                int currentPower = 0;
                // A가 i번 BC에 접속 가능한지 확인 (i=0은 접속 안함을 의미)
                boolean aIsInRange = (i != 0) && ((aBatteryMask & (1 << i)) != 0);
                // B가 j번 BC에 접속 가능한지 확인 (j=0은 접속 안함을 의미)
                boolean bIsInRange = (j != 0) && ((bBatteryMask & (1 << j)) != 0);

                // A가 i번 BC를 선택했지만 범위 밖이거나, B가 j번 BC를 선택했지만 범위 밖이면 유효하지 않은 조합
                if ((i != 0 && !aIsInRange) || (j != 0 && !bIsInRange)) {
                    continue;
                }

                if (i != j) { // 서로 다른 BC를 선택한 경우
                    if (aIsInRange) currentPower += bc[i];
                    if (bIsInRange) currentPower += bc[j];
                } else { // 같은 BC를 선택한 경우 (i == j)
                    // 둘 중 한명이라도 접속 가능하면 그 BC의 파워를 얻음
                    if (aIsInRange || bIsInRange) {
                        currentPower = bc[i];
                    }
                }
                maxPower = Math.max(maxPower, currentPower);
            }
        }
        return maxPower;
    }
}
