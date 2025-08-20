import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: BFS 탐색
 * ## 방향 그래프의 bfs 탐색
 * ## 번호가 제멋대로 박혀있으므로, 배열을 쓰기보단 Map을 사용해서 key에 시작노드, value에 도착노드들의 List를 설정
 * ## 마찬가지로 방문 처리를 위해 Set을 사용(Set에 원소가 들어있으면 이미 방문한 노드)
 * ## ans 배열을 만들어 {node 번호, 방문 depth}를 저장
 * ## 노드들을 bfs 순회하며 ans 배열 update
 * 
 * # 시간복잡도: O(N) <- 간선만큼 탐색
 * 
 * # 메모리: 26,112 kb
 * # 실행시간: 94 ms
 * # 난이도: 하
 */

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        for(int tc=1; tc<=10; ++tc) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            
            int n = Integer.parseInt(st.nextToken())/2;
            int startNode = Integer.parseInt(st.nextToken());
            
            Map<Integer, List<Integer>> graph = new HashMap<Integer, List<Integer>>();
            st = new StringTokenizer(br.readLine());
            for(int i=0; i<n; ++i) {
                int from = Integer.parseInt(st.nextToken());
                int to = Integer.parseInt(st.nextToken());
                
                if(!graph.containsKey(from)) graph.put(from, new ArrayList<>());
                graph.get(from).add(to);
            }
            
            int[] ans = new int[] {-1, -1};
            
            Set<Integer> isVisited = new HashSet<>();
            Deque<int[]> q = new ArrayDeque<int[]>();
            
            isVisited.add(startNode);
            q.offer(new int[] {startNode, 0});
            while(!q.isEmpty()) {
                int[] cur = q.poll();
                
                if(!graph.containsKey(cur[0])) continue;
                for(int next : graph.get(cur[0])) {
                    if(isVisited.contains(next)) continue;
                    
                    isVisited.add(next);
                    q.offer(new int[] {next, cur[1]+1});
                    
                    if(cur[1]+1 > ans[1]) {
                        ans[0] = next;
                        ans[1] = cur[1]+1;
                    } else if(cur[1]+1 == ans[1] && next > ans[0]) ans[0] = next;
                }
            }
            
            bw.write("#" + tc + " " + ans[0] + "\n");
        }
        
        bw.close();
    }
}