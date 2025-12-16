import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		String s1 = "";
		String s2 = "";
		for(int i=0; i<n-2; ++i) {
			s1 += "0";
			s2 += "0";
		}
		
		s1 += "0O";
		s2 += "10";
		
		System.out.print(s1 + "\n" + s2);
	}
}
