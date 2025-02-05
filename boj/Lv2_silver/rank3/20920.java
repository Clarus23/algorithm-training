import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        Map<String, Integer> frequency = new HashMap<>();
        for(int i=0; i<n; i++) {
            String word = br.readLine();
            if(word.length() < m) continue;

            frequency.put(word, frequency.getOrDefault(word, 0)+1);
        }

        List<String> keys = new ArrayList<>(frequency.keySet());
        keys.sort((o1, o2) -> {
            if(frequency.get(o2) != frequency.get(o1)) return frequency.get(o2) - frequency.get(o1);
            if(o2.length() != o1.length()) return o2.length() - o1.length();
            return o1.compareTo(o2);
        });

        for(String word : keys) {
            bw.write(word);
            bw.newLine();
        }
        bw.close();
    }
}