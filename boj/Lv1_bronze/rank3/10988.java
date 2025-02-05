import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));

        String str = input.readLine();
        String reverse = new StringBuffer(str).reverse().toString();

        if(str.equals(reverse)) output.write("1");
        else output.write("0");

        output.close();
    }
}