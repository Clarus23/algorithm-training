import java.io.*;
import java.util.HashSet;
import java.util.Set;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Set<String> s = new HashSet<>();
        int cnt=0;
        int n = Integer.parseInt(br.readLine());
        for(int i=0; i<n; i++) {
            String name = br.readLine();
            if(name.equals("ENTER")) {
                cnt += s.size();
                s.clear();
                continue;
            }

            s.add(name);
        } cnt += s.size();

        System.out.print(cnt);
    }
}