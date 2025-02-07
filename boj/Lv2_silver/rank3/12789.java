import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        Deque<Integer> stack = new ArrayDeque<>(n);

        StringTokenizer st = new StringTokenizer(br.readLine());
        int curNumber = 1;
        for(int i=0; i<n; i++) {
            int num = Integer.parseInt(st.nextToken());

            if(num == curNumber) {
                curNumber++;
                continue;
            }
            while(!stack.isEmpty() && stack.peekFirst() == curNumber) {
                stack.removeFirst();
                curNumber++;
            } stack.addFirst(num);
        } while(!stack.isEmpty() && stack.peekFirst() == curNumber) {
            stack.removeFirst();
            curNumber++;
        }

        if(stack.isEmpty()) System.out.print("Nice");
        else System.out.print("Sad");
    }
}