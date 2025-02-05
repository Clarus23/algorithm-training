import java.io.*;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Map<String, Double> map = Map.of(
                "A+", 4.5,
                "A0", 4.0,
                "B+", 3.5,
                "B0", 3.0,
                "C+", 2.5,
                "C0", 2.0,
                "D+", 1.5,
                "D0", 1.0,
                "F", 0.0
        );

        double credit = 0.0;
        double grade = 0.0;
        for(int i=0; i<20; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            st.nextToken();

            double thisCredit = Double.parseDouble(st.nextToken());
            String thisGrade = st.nextToken();
            if(thisGrade.equals("P")) continue;

            credit += thisCredit;
            grade += (map.get(thisGrade) * thisCredit);
        }

        System.out.printf("%.6f", grade/credit);
    }
}