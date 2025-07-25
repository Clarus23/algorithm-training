// 배열 입력받아 정렬 후 투 포인터로 두 수의 합 구하기.

// 1) 구하려는 수보다 큰 경우 end 포인터를 -1
// 2) 구하려는 수보다 작은 경우 start 포인터를 +1
// 3) 구하려는 수와 같을 경우 end--, start++

// 시간 복잡도
// 정렬 : O(logN)
// 투 포인터 탐색 : O(N)
// 총 시간 복잡도 : O(NlogN)
import java.io.*;
import java.util.StringTokenizer;
import java.util.Arrays;

public class Solution {

    public static void main(String[] args) throws IOException {
        // TODO Auto-generated method stub
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int[] arr = new int[n];
        for(int i=0; i<n; ++i) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        int x = Integer.parseInt(br.readLine());
        
        int ans = 0;
        Arrays.sort(arr);
                
        int start=0; int end = n-1;
        while(start != end) {
            if(arr[start] + arr[end] == x) {
                ++ans;
                ++start;
                --end;
            } else if(arr[start] + arr[end] < x) {
                ++start;
            } else {
                --end;
            }
        }
        
        bw.write(String.valueOf(ans));
        bw.flush();
        bw.close();
    }
}
