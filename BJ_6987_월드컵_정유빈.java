package algorithm_study;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class BJ_6987_월드컵_정유빈 {

		static int [][] arr = new int[6][3];
		static boolean possible = false;
	    static StringBuilder sb = new StringBuilder();
	    
		static void dfs(int j, int k) {
				
	          if(possible){
	               return;
	           }
	            
			if(j == 5) {
	               boolean finish = true;
				for(int i = 0; i < 6; i++) {
					for(int p = 0; p < 3; p++) {
						if(arr[i][p] != 0) {
	                           finish = false;
						return;
							}
					}
				}
				
	               if(finish){
	                   possible = true;
	                   return;
	               }
			}
				
			if(arr[j][0] > 0 && arr[k][2] > 0) {
	               
	            arr[j][0] -=1;
				arr[k][2] -=1;
	                
				if(k == 5) {					
					dfs(j+1, j+2);					
				}
				else {
					dfs(j, k+1);
				}
	                
	              arr[j][0] +=1;
				arr[k][2] +=1;
			}
			if(arr[j][1] > 0 && arr[k][1] > 0) {
	             arr[j][1] -=1;
	             arr[k][1] -=1;
	                
				if(k == 5) {				
					dfs(j+1, j+2);
				}
				else {
					dfs(j, k+1);
				}
	                arr[j][1] +=1;
					arr[k][1] +=1;
			}
			if(arr[j][2] > 0 && arr[k][0] > 0) {
	                
	             arr[j][2] -=1;
				arr[k][0] -=1;
	                
				if(k == 5) {					
					dfs(j+1, j+2);
				}
				else {					
					dfs(j, k+1);
				}
	                
	              arr[j][2] +=1;
				arr[k][0] +=1;
			}
		}
			
		static void solution() {
			possible = false;
			dfs(0,1);
	                
			if(possible) {
				sb.append(1 + " ");
			}
			else {
				sb.append(0 + " ");
			}
		}
		public static void main(String[] args) throws IOException {
				// TODO Auto-generated method stub

			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
				
			for(int i = 0; i < 4; i++) {
				StringTokenizer tokenizer = new StringTokenizer(br.readLine());
					
				for(int j = 0; j < 6; j++) {
					for(int k = 0; k < 3; k++) {
						arr[j][k] = Integer.parseInt(tokenizer.nextToken());
					}
				}
					
				solution();
					
			}
	            
	           System.out.println(sb.toString());
		}

	}
