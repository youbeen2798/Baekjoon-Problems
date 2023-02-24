package algorithm_study;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BJ_13023_ABCDE_정유빈 {

	static int n,m;
	
	static ArrayList<Integer>[] friends = new ArrayList[2001]; 
	static boolean [] selected = new boolean[2001];
	static boolean possible = false;
	static void dfs(int start, int cnt) {
		
		selected[start] = true;
		
		if(cnt == 5) {
			System.out.println(1);
			System.exit(0);
		}
		
		for(int i = 0; i < friends[start].size(); i++) {
			int friend = friends[start].get(i); //친구
			if(!selected[friend]) {
				selected[friend] = true;
				dfs(friend, cnt + 1);
				selected[friend] = false;
			}
		}
	}
	
	static void reset() {
		for(int i = 0; i < n; i++) {
			selected[i] = false;
		}
	}
	static void solution() {
		for(int i = 0; i < n; i++) {
			reset(); 
			dfs(i,1);
		}
		
		System.out.println(0);
	}
	static void input() throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer tokenizer = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(tokenizer.nextToken());
		m = Integer.parseInt(tokenizer.nextToken());
				
		for(int i = 0; i < n; i++) {
			friends[i] = new ArrayList<>();
		}
		
		for(int i = 0; i < m; i++) {
			int a,b;
			tokenizer = new StringTokenizer(br.readLine());
			a = Integer.parseInt(tokenizer.nextToken());
			b = Integer.parseInt(tokenizer.nextToken());
			friends[a].add(b);
			friends[b].add(a);
		}
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		input();
		solution();
	}

}
