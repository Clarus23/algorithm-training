import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: 시뮬레이션(단순 구현)
 * ## 왼쪽, 오른쪽 탐색하며 회전 정보를 저장, 그 후 한번에 돌림.
 * 
 * # 시간복잡도: O(1) // k가 20밖에 안되니 상수시간으로 끝남.
 * 
 * # 메모리: 26,368 kb
 * # 실행시간: 92 ms
 * # 체감난이도: 하
 */

public class Solution {
    
    static int k;
    static boolean[][] magnets;
    static int[] pointers;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int t = Integer.parseInt(br.readLine());
        for(int tc=1; tc<=t; ++tc) {
            k = Integer.parseInt(br.readLine());
            
            magnets = new boolean[4][8];
            pointers = new int[] {0, 0, 0, 0};
            
            StringTokenizer st;
            for(int i=0; i<4; ++i) {
                st = new StringTokenizer(br.readLine());
                for(int j=0; j<8; ++j) magnets[i][j] = (st.nextToken().charAt(0) == '1');
            }
            
            while(k-- > 0) {
                st = new StringTokenizer(br.readLine());
                
                int id = Integer.parseInt(st.nextToken()) - 1;
                int dir = Integer.parseInt(st.nextToken());
                
                int[] isRotation = {0, 0, 0, 0};
                isRotation[id] = -1 * dir; // 시계방향 => pointer는 반시계로 // 반시계방향 => pointer는 시계로 움직여야함.
                
                // 왼쪽 탐색 // i+1, i 를 비교해야함.
                for(int i=id-1; i>=0; --i) {
                    // 이전의 6번 극과 현재의 2번 극이 같다면 안돌아감(반복 종료)
                    if(magnets[i+1][(pointers[i+1] + 6)%8] == magnets[i][(pointers[i] + 2)%8]) break;
                    
                    // 돌아가는 정보 저장
                    isRotation[i] = -1 * isRotation[i+1];
                }
                
                // 오른쪽 탐색 // i-1, i 를 비교해야함.
                for(int i=id+1; i<4; ++i) {
                    // 이전의 2번 극과 현재의 6번 극이 같나면 안돌아감(반복 종료)
                    if(magnets[i-1][(pointers[i-1] + 2)%8] == magnets[i][(pointers[i] + 6)%8]) break;
                    
                    // 돌아가는 정보 저장
                    isRotation[i] = -1 * isRotation[i-1];
                }
                
                // 회전 처리
                for(int i=0; i<4; ++i) {
                    pointers[i] += isRotation[i];
                    pointers[i] %= 8;
                    pointers[i] = (pointers[i] == -1) ? 7 : pointers[i];
                }
            }
            
            int point = 0;
            for(int i=0; i<4; ++i) if(magnets[i][pointers[i]]) point |= (1<<i);
            
            bw.write("#" + tc + " " + point + "\n");
        }
        bw.close();
    }
}
