import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Deque<Integer> dq = new ArrayDeque<>();

        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        for(int i=0; i<n; i++) {
            st = new StringTokenizer(br.readLine());

            int op = Integer.parseInt(st.nextToken());
            if(op == 1) {
                dq.addFirst(Integer.parseInt(st.nextToken()));
                continue;
            } else if(op == 2) {
                dq.addLast(Integer.parseInt(st.nextToken()));
                continue;
            } if(op == 3) bw.write(String.valueOf(dq.isEmpty() ? -1 : dq.removeFirst()));
            else if(op == 4) bw.write(String.valueOf(dq.isEmpty() ? -1 : dq.removeLast()));
            else if(op == 5) bw.write(String.valueOf(dq.size()));
            else if(op == 6) bw.write(String.valueOf(dq.isEmpty() ? 1 : 0));
            else if(op == 7) bw.write(String.valueOf(dq.isEmpty() ? -1 : dq.peekFirst()));
            else if(op == 8) bw.write(String.valueOf(dq.isEmpty() ? -1 : dq.peekLast()));
            bw.newLine();
        }

        bw.close();
    }
}