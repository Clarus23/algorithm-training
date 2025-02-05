import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] alphabet = new int[26];
        char[] word = br.readLine().toLowerCase().toCharArray();

        for(char c : word) alphabet[c - 'a']++;

        int first = 0;
        boolean flag = false;
        for(int i=1; i<26; i++) {
            if(alphabet[i] > alphabet[first]) {
                first = i;
                flag = false;
            } else if(alphabet[i] == alphabet[first]) flag = true;
        }

        if(flag) bw.write("?");
        else bw.write('A'+first);
        bw.close();
    }
}