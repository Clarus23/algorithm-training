import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
 * # 풀이 아이디어: 순열(NextPermutation) + 수식
 * ## 0번 선수를 제외한 모든 순열을 구하여 그 중 최대 점수를 출력
 * ## 점수 처리를 위한 점화식 설정
 * ## 그 후는, nextPermutation을 돌려 모든 가능한 순열에 대해 검사
 * 
 * # 메모리: 66,752 kb
 * # 실행시간: 888 ms
 * # 체감난이도: 중
 */

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
        int[][] scoreBoard = new int[n][9];
        for(int i=0; i<n; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            
            for(int j=0; j<9; ++j) scoreBoard[i][j] = Integer.parseInt(st.nextToken());
        }
        
        // 0번 선수 => 무조건 4번타자
        int[] lineup = new int[] {1, 2, 3, 4, 5, 6, 7, 8};
        int maxScore = 0;
        do {
            int score = 0; int batter = 0;
            for(int innings=0; innings<n; ++innings) {
                boolean[] base = new boolean[] {true, false, false, false};        // 홈(타자석), 1루, 2루, 3루
                int outCount = 0;
                while(outCount < 3) {
                    int curBatter;
                    if(batter == 3) curBatter = 0;
                    else curBatter = (batter < 3) ? lineup[batter] : lineup[batter-1];
                    
                    int batting = scoreBoard[innings][curBatter];
                    if(batting == 0) ++outCount;
                    else {
                        for(int i=(4-batting); i<4; ++i) score += (base[i] ? 1 : 0);    // 홈에 들어오는 선수 만큼 score 늘려줌
                        for(int i=3; i>(batting-1); --i) base[i] = base[i-batting];        // 진루한 선수들 처리
                        for(int i=1; i<batting; ++i) base[i] = false;                    // 비어있는 베이스 false로 변경
                    }
                    
                    batter = (++batter%9);
                }
            }
            
            maxScore = (score > maxScore) ? score : maxScore;
        } while(nextPermutation(lineup));
        
        System.out.print(maxScore);
    }
    
    static boolean nextPermutation(int[] arr) {
        // 1. 뒤에서부터 탐색하며 교환할 위치(i-1) 찾기
        int i = arr.length - 1;
        while (i > 0 && arr[i - 1] >= arr[i]) {
            i--;
        }

        // 마지막 순열인 경우 (내림차순 정렬 상태)
        if (i <= 0) {
            return false;
        }

        // 2. 교환할 위치(i-1)와 교환할 값(j) 찾기
        int j = arr.length - 1;
        while (arr[j] <= arr[i - 1]) {
            j--;
        }

        // 3. 두 값 교환(swap)
        swap(arr, i - 1, j);

        // 4. i부터 끝까지의 순서를 뒤집기
        int k = arr.length - 1;
        while (i < k) {
            swap(arr, i, k);
            i++;
            k--;
        }
        return true;
    }

    static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}    