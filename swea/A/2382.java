import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: 시뮬레이션(단순 구현)
 * ## 각 초마다 모든 미생물의 움직임을 추적한다.
 * ## 이를 위하여 미생물의 정보를 저장할 클래스를 선언한다.
 * ## 미생물 클래스
 * #### 멤버변수
 *         - row, col: 현재 미생물 그룹의 행과 열
 *         - numOfGroup: 현재 미생물 그룹의 미생물 수
 *         - dir: 방향
 *         - isDeleted: 삭제된 (수가 0이 된, 혹은 다른 그룹에 통합된) 그룹인가?
 * #### 멤버메서드
 *         - move(): void                     => 이동 방향에 맞추어 row, col을 늘림.
 *         - meetChemical(): void             => 약품을 만났을 시 처리
 *         - merge(Microbe, boolean): void    => 병합 처리(매개변수로 들어온 그룹을 내 그룹에 통합)
 * ## 각 시간마다 미생물이 이동한 칸에 미생물의 번호를 저장하여 병합을 판단.
 * 
 * # 시간복잡도: O(M*(N^2+K))
 * 
 * # 메모리: 135,148 kb
 * # 실행시간: 2,770 ms
 * # 체감난이도: 하
 */

public class Solution {
    
    static final int[][] dirs = new int[][] {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 0: none, 1: up, 2: down, 3: left, 4: right
    static final int[] reverse = new int[] {0, 2, 1, 4, 3};
    
    static int n, m, k;
    static int sumOfMicrobe;
    
    static class Microbe {
        int row, col;
        int numOfGroup;
        int dir;
        boolean isDeleted = false;

        public Microbe(int row, int col, int numOfGroup, int dir) {
            super();
            this.row = row;
            this.col = col;
            this.numOfGroup = numOfGroup;
            this.dir = dir;
        }
        
        void move() {
            row += dirs[dir][0];
            col += dirs[dir][1];
        }
        
        void meetChemical() {
            sumOfMicrobe -= (numOfGroup/2 + numOfGroup%2);
            
            numOfGroup /= 2;
            if(numOfGroup == 0) isDeleted = true;
            dir = reverse[dir];
        }
        
        void merge(Microbe o, boolean isBig) {
            numOfGroup += o.numOfGroup;
            if(isBig) dir = o.dir;
        }

        @Override
        public String toString() {
            return "Microbe [row=" + row + ", col=" + col + ", numOfGroup=" + numOfGroup + ", dir=" + dir
                    + ", isDeleted=" + isDeleted + "]";
        }
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int t = Integer.parseInt(br.readLine());
        for(int tc=1; tc<=t; ++tc) {
            StringTokenizer st= new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());
            
            // 0 은 dummy
            sumOfMicrobe = 0;
            Microbe[] microbes = new Microbe[k+1];
            for(int i=1; i<=k; ++i) {
                st = new StringTokenizer(br.readLine());
                microbes[i] = new Microbe(Integer.parseInt(st.nextToken())        // row
                                        , Integer.parseInt(st.nextToken())        // col
                                        , Integer.parseInt(st.nextToken())        // numOfGroup
                                        , Integer.parseInt(st.nextToken()));    // dir
                sumOfMicrobe += microbes[i].numOfGroup;
            }
            
            int[][][] cur; // 한 칸에는, 현재 미생물의 번호[0]와 가장큰 그룹의 개수[1]가 들어있다.
            for(int time=0; time<m; ++time) {
                cur = new int[n][n][2];
                
                for(int i=1; i<=k; ++i) {
                    if(microbes[i].isDeleted) continue;
                    
                    // 이동
                    microbes[i].move();
                    
                    // 약품 만남 처리
                    if(isBoundary(microbes[i]))    {
                        microbes[i].meetChemical();
                        if(microbes[i].isDeleted) continue; 
                    }
                    
                    // 빈칸이었다면
                    if(cur[microbes[i].row][microbes[i].col][0] == 0) {
                        cur[microbes[i].row][microbes[i].col][0] = i;
                        cur[microbes[i].row][microbes[i].col][1] = microbes[i].numOfGroup;
                        continue;
                    }
                    
                    // 다른 미생물이 이미 있었다면
                    int targetNum = cur[microbes[i].row][microbes[i].col][0];
                    boolean isBig = false;
                    
                    if(cur[microbes[i].row][microbes[i].col][1] < microbes[i].numOfGroup) {
                        cur[microbes[i].row][microbes[i].col][1] = microbes[i].numOfGroup;
                        isBig = true;
                    }
                    
                    microbes[i].isDeleted = true;
                    microbes[targetNum].merge(microbes[i], isBig);
                }
            }
            
            bw.write("#" + tc + " " + sumOfMicrobe + "\n");
        }
        
        bw.close();
    }
    
    static boolean isBoundary(Microbe microbe) {
        return (microbe.row == 0 || microbe.row == n-1 || microbe.col == 0 || microbe.col == n-1);
    }
}    