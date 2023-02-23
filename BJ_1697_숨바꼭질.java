package algorithm_study;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

	public class BJ_1697_숨바꼭질 {
		
	static int n,k;
	static int[] times = new int[100001];
	
	static void solution() {
		
		Queue<Integer> q = new LinkedList<>();
			
		for(int i = 0; i <= 100000; i++) {
			times[i] = Integer.MAX_VALUE;
		}
		
			
		q.add(n);
		times[n] = 0;
			
		while(!q.isEmpty()) {
			int a = q.poll();
			int now_time = times[a];
				
			if(a == k) {
				System.out.println(now_time);
				break;
			}

				
			if(a - 1 >= 0 && a -1 <= 100000 && now_time + 1 <= times[a - 1]) {
				times[a-1] = now_time + 1;
				int b = a - 1;
				int time = now_time + 1;
				
				q.add(a-1);
			}
			if(a + 1 >=0 && a + 1 <= 100000 && now_time + 1 <= times[1 +a]) {
				times[a+1] = now_time + 1;
				int b = a +1;
				int time = now_time + 1;
				
				q.add(a+1);
			}
			if(2*a  >=0 && 2*a <= 100000 && now_time + 1 <= times[2*a]) {
				times[2*a] = now_time + 1;
				int b = 2 * a;
				int time = now_time + 1;
				q.add(2*a);
			}
		}
	}
		
	static void input() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tokenizer = new StringTokenizer(br.readLine());
		n = Integer.parseInt(tokenizer.nextToken());
		k = Integer.parseInt(tokenizer.nextToken());
			
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		input();
	        
	     if(n == k){
	          System.out.println(0);
	          System.exit(0); 
	      }
		solution();
	}

	}
