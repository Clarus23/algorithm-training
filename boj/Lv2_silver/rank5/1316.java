import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());
        int cnt=0;
        for(int i=0; i<t; i++) {
            char[] word = br.readLine().toCharArray();
            boolean[] isAppear = new boolean[26];

            char prev = word[0];
            isAppear[word[0]-'a'] = true;
            boolean isGroupWord = true;
            for(char c : word) {
                if(c == prev) continue;
                if(!isAppear[c-'a']) {
                    prev = c;
                    isAppear[c-'a'] = true;
                } else {
                    isGroupWord = false;
                    break;
                }
            }

            if(isGroupWord) cnt++;
        }

        System.out.print(cnt);
    }
}