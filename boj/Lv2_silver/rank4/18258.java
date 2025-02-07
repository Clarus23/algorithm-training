import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Deque<Integer> queue = new ArrayDeque<>();

        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        for(int i=0; i<n; i++) {
            st = new StringTokenizer(br.readLine());

            String op = st.nextToken();
            if(op.equals("push")) {
                queue.addLast(Integer.parseInt(st.nextToken()));
                continue;
            } if(op.equals("pop")) bw.write(String.valueOf(queue.isEmpty() ? -1 : queue.removeFirst()));
            else if(op.equals("size")) bw.write(String.valueOf(queue.size()));
            else if(op.equals("empty")) bw.write(String.valueOf(queue.isEmpty() ? 1 : 0));
            else if(op.equals("front")) bw.write(String.valueOf(queue.isEmpty() ? -1 : queue.peekFirst()));
            else if(op.equals("back")) bw.write(String.valueOf(queue.isEmpty() ? -1 : queue.peekLast()));
            bw.newLine();
        }

        bw.close();
    }
}