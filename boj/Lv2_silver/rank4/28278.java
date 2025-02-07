import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Deque<Integer> stack = new ArrayDeque<>();

        int n = Integer.parseInt(br.readLine());
        StringTokenizer st;
        for(int i=0; i<n; i++) {
            st = new StringTokenizer(br.readLine());

            int op = Integer.parseInt(st.nextToken());
            if(op == 1) {
                stack.addFirst(Integer.parseInt(st.nextToken()));
                continue;
            } if(op == 2) bw.write(String.valueOf(stack.isEmpty() ? -1 : stack.removeFirst()));
            else if(op == 3) bw.write(String.valueOf(stack.size()));
            else if(op == 4) bw.write(String.valueOf(stack.isEmpty() ? 1 : 0));
            else bw.write(String.valueOf(stack.isEmpty() ? -1 : stack.peekFirst()));

            bw.newLine();
        }

        bw.close();
    }
}