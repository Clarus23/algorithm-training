import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.util.List;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        List<Integer> roads = new ArrayList<>(n-1);
        List<Integer> citys = new ArrayList<>(n);

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n-1; i++) roads.add(Integer.parseInt(st.nextToken()));
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n-1; i++) citys.add(Integer.parseInt(st.nextToken()));
        citys.add(-1);

        int index = 0;
        long cost = 0;
        while(index < n-1) {
            int curCost = citys.get(index);
            long distance = roads.get(index);

            while(index < n-1) {
                int nextCost = citys.get(++index);
                if(curCost > nextCost) break;

                distance += roads.get(index);
            }

            cost += distance*curCost;
        }

        System.out.print(cost);
    }
}