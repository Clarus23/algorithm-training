import java.io.*;
import java.util.StringTokenizer;


/*
 * Idea
 * - n개의 node => A부터 차례대로
 * - binary tree 이므로 2개의 자식을 가지는 Node class 구현
 * - 0~N까지의 Node 배열(tree) 선언
 * - 재귀 함수로 pre, in, post order 구현
 * 
 * 
 * 시간 복잡도 : O(N)
 * 메모리 : 	14284 kb
 * 시간 :		108 ms
 * 체감 난이도 : 하
 */
public class Main {
	// 현재 node가 어떤 자식을 가질지 저장할 배열
	static Node[] tree;
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	// 이진 트리의 노드 구현
	static class Node {
		char left;
		char right;
		
		Node(char left, char right) {
			this.left = left;
			this.right = right;
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		StringTokenizer st;
		tree = new Node[n]; // n 만큼 배열 만들고 입력받아 tree 구현
		for(int i=0; i<n; ++i) {
			st = new StringTokenizer(br.readLine());
			tree[st.nextToken().charAt(0) - 'A'] = new Node(st.nextToken().charAt(0), st.nextToken().charAt(0));
		}
		
		// 각각 재귀 함수 불러서 출력
		preFix('A');
		bw.write("\n");
		inFix('A');
		bw.write("\n");
		postFix('A');
		bw.close();
	}
	// 각각의 함수는 전위, 중위, 후위의 순회 순서에 따라 buffer에 node를 저장
	
	// 전위순회 (c -> l -> r)
	static void preFix(char node) throws IOException {
		bw.write(node);
		if(tree[node - 'A'].left != '.') preFix(tree[node - 'A'].left);
		if(tree[node - 'A'].right != '.') preFix(tree[node - 'A'].right);
	}
	
	// 중위순회 (l -> c -> r)
	static void inFix(char node) throws IOException {
		if(tree[node - 'A'].left != '.') inFix(tree[node - 'A'].left);
		bw.write(node);
		if(tree[node - 'A'].right != '.') inFix(tree[node - 'A'].right);
	}

	// 후위순회 (l -> r -> c)
	static void postFix(char node) throws IOException {
		if(tree[node - 'A'].left != '.') postFix(tree[node - 'A'].left);
		if(tree[node - 'A'].right != '.') postFix(tree[node - 'A'].right);
		bw.write(node);
	}
}
