import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.StringTokenizer;

/* # SWEA D4 1226. [S/W 문제해결 기본] 7일차 - 미로1
 * # 풀이 아이디어: BFS
 * 
 * # 시간복잡도: O(1)
 * 
 * # 메모리: 26,240 kb
 * # 실행시간: 91 ms
 * # 체감난이도: 하
 */

public class Solution {
	
	static final int[][] dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
	
	static int[][] sAndT;
	static boolean[][] map;
	
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        for(int t=0; t<10; ++t) {
        	String tc = br.readLine();
        	
        	sAndT = new int[2][2];
        	map = new boolean[16][16];
        	for(int row=0; row<16; ++row) {
        		String temp = br.readLine();
        		for(int col=0; col<16; ++col) {
        			char c = temp.charAt(col);
        			
        			map[row][col] = (c == '1');
        			if(c == '2' || c == '3') {
        				sAndT[c - '0' - 2][0] = row;
        				sAndT[c - '0' - 2][1] = col;
        			}
        		}
        	}
        	bw.write("#" + tc + " " + bfs() + "\n");
        }
        bw.close();
    }
    
    static int bfs() {
    	Queue<int[]> q = new ArrayDeque<>();
    	q.add(sAndT[0]);
    	
    	while(!q.isEmpty()) {
    		int[] cur = q.poll();
    		
    		for(int[] dir : dirs) {
    			int[] next = {cur[0] + dir[0], cur[1] + dir[1]};
    			
    			if(isOutOfBounds(next) || map[next[0]][next[1]]) continue;
    			if(isGoal(next)) return 1;
    			
    			map[next[0]][next[1]] = true;
    			q.offer(next);
    		}
    	}
    	
    	return 0;
    }
    static boolean isOutOfBounds(int[] coord) {
    	return (coord[0] < 0 || coord[0] >= 16 || coord[1] < 0 || coord[1] >= 16);
    }
    static boolean isGoal(int[] coord) {
    	return (coord[0] == sAndT[1][0] && coord[1] == sAndT[1][1]);
    }
}
