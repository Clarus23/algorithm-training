import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String word = br.readLine();
        int cnt=0;
        for(int i=0; i<word.length(); i++) {
            if(i < word.length()-1) {
                if((word.charAt(i+1) == '=' && (word.charAt(i) == 'c' || word.charAt(i) == 's' || word.charAt(i) == 'z'))
                    || (word.charAt(i+1) == '-' && (word.charAt(i) == 'c' || word.charAt(i) == 'd'))
                    || (word.charAt(i+1) == 'j' && (word.charAt(i) == 'l' || word.charAt(i) == 'n'))) i++;
            }
            if(i < word.length()-2) {
                if(word.charAt(i+2) == '=' && word.charAt(i+1) == 'z' && word.charAt(i) == 'd') i += 2;
            }

            cnt++;
        }

        bw.write(Integer.toString(cnt));
        bw.close();
    }
}