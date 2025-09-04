import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class Solution {
    
    static int deleteCnt;
    static int disappearEnergy;
    static final int[][] dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    
    static class Atom {
        int row, col;
        int dir;
        int energy;
        boolean isDeleted = false;
        
        public Atom(int col, int row, int dir, int energy) {
            super();
            this.row = row;
            this.col = col;
            this.dir = dir;
            this.energy = energy;
        }
        
        int move() {
            row += dirs[dir][0];
            col += dirs[dir][1];
            
            if(row < 0 || row > 4000 || col < 0 || col > 4000) {
                isDeleted = true;
                ++deleteCnt;
                return -1;
            }
            
            return row*4001 + col;
        }
        
        void disappear() {
        	if(isDeleted) return;
        	
        	isDeleted = true;
        	++deleteCnt;
        	disappearEnergy += energy;
        }
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int t = Integer.parseInt(br.readLine());
        for(int tc=1; tc<=t; ++tc) {
            int n = Integer.parseInt(br.readLine());
            deleteCnt = 0;
            
            Atom[] atoms = new Atom[n];
            for(int i=0; i<n; ++i) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                atoms[i] = new Atom((Integer.parseInt(st.nextToken())+1000)*2
                                  , (Integer.parseInt(st.nextToken())+1000)*2
                                  , Integer.parseInt(st.nextToken())
                                  , Integer.parseInt(st.nextToken()));
            }
            
            disappearEnergy = 0;
            while(deleteCnt < n-1) {
                Map<Integer, List<Atom>> board = new HashMap<Integer, List<Atom>>();
                for(int i=0; i<n; ++i) {
                    if(atoms[i].isDeleted) continue;
                    
                    int key = atoms[i].move();
                    if(key == -1) continue;
                    board.computeIfAbsent(key, k -> new ArrayList<>()).add(atoms[i]);
                }
                
                for(List<Atom> it : board.values()) {
                	if(it.size() < 2) continue;
                	
                	it.stream().forEach(Atom::disappear);
                }
            }
            
            bw.write("#" + tc + " " + disappearEnergy + "\n");
        }
        bw.close();
    }
}