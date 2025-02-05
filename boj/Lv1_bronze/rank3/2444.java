import java.io.*;

public class 2444 {
    public static void main(String[] args) throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(input.readLine());
        for(int i=0; i<n; i++) {
            for(int j=i; j<n-1; j++) output.write(" ");
            for(int j=0; j<=2*i; j++) output.write("*");
            output.newLine();
        } for(int i=n-2; i>=0; i--) {
            for(int j=i; j<n-1; j++) output.write(" ");
            for(int j=0; j<=2*i; j++) output.write("*");
            output.newLine();
        }

        output.close();
    }
}