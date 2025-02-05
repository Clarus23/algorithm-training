import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Set<String> rainbowDancer = new HashSet<>();
        rainbowDancer.add("ChongChong");

        int n = Integer.parseInt(br.readLine());
        for(int i=0; i<n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String nameA = st.nextToken();
            String nameB = st.nextToken();

            if(rainbowDancer.contains(nameA) || rainbowDancer.contains(nameB)) {
                rainbowDancer.add(nameA);
                rainbowDancer.add(nameB);
            }
        }

        System.out.println(rainbowDancer.size());
    }
}