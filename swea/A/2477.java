import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.StringTokenizer;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	static int n, m, k;
	static int a, b;
	
	static int[] receptionTimes, repairTimes;
	static int[] arrivalTimes;
	
	static Customer[] receptionDesks, repairDesks;
	static PriorityQueue<Customer> receptionWaitQ, repairWaitQ;
	
	static int ans;
	static Set<Integer> s;
	
	static int finishCustomer;
	
	static class Customer {
		int id;
		int receptionDeskNum;
		int endTime;
		
		Customer(int id) { this.id = id; }
	}
	
	public static void main(String[] args) throws IOException {
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int t = Integer.parseInt(br.readLine());
		for(int tc=1; tc<=t; ++tc) {
			input();
			
			int time = 0;
			int cId = 1;
			while(finishCustomer < k) {
				while(cId <= k && arrivalTimes[cId] == time) receptionWaitQ.offer(new Customer(cId++));
				
				for(int i=0; i<m; ++i) {
					if(repairDesks[i] == null || repairDesks[i].endTime != time) continue;
					
					++finishCustomer;
					if(i == b && s.contains(repairDesks[i].id)) ans += repairDesks[i].id;
					repairDesks[i] = null;
				}
				
				for(int i=0; i<n; ++i) {
					if(receptionDesks[i] == null || receptionDesks[i].endTime != time) continue;
					
					repairWaitQ.offer(receptionDesks[i]);
					if(i == a) s.add(receptionDesks[i].id);
					receptionDesks[i] = null;
				}
				
				for(int i=0; i<m && !repairWaitQ.isEmpty(); ++i) {
					if(repairDesks[i] != null) continue;
					
					Customer customer = repairWaitQ.poll();
					customer.endTime = time + repairTimes[i];
					repairDesks[i] = customer;
				}
				
				for(int i=0; i<n && !receptionWaitQ.isEmpty(); ++i) {
					if(receptionDesks[i] != null) continue;
					
					Customer customer = receptionWaitQ.poll();
					customer.receptionDeskNum = i;
					customer.endTime = time + receptionTimes[i];
					receptionDesks[i] = customer;
				}
				
				++time;
			}
			
			bw.write("#" + tc + " " + (ans==0 ? -1 : ans) + "\n");
		}
		
		bw.close();
	}
	
	static void input() throws IOException {
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		
		a = Integer.parseInt(st.nextToken()) - 1;
		b = Integer.parseInt(st.nextToken()) - 1;
		
		receptionTimes = new int[n];
		repairTimes = new int[m];
		arrivalTimes = new int[k+1];
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<n; ++i) receptionTimes[i] = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<m; ++i) repairTimes[i] = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		for(int i=1; i<=k; ++i) arrivalTimes[i] = Integer.parseInt(st.nextToken());
		
		receptionDesks = new Customer[n];
		repairDesks = new Customer[m];
		
		receptionWaitQ = new PriorityQueue<>((c1, c2) -> c1.id - c2.id);
		repairWaitQ = new PriorityQueue<>((c1, c2) -> {
			if (c1.endTime == c2.endTime) {
                return c1.receptionDeskNum - c2.receptionDeskNum;
            }
            return c1.endTime - c2.endTime;
		});
		
		s = new HashSet<>();
		ans = 0;
		
		finishCustomer = 0;
	}
}
