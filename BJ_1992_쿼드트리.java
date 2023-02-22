package algorithm_study;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ_1992_쿼드트리 {

	static int n;
	static char [][] arr = new char[65][65];
	
	static boolean check(int x, int y, int num) {
		
		int first_num = arr[x][y];
		for(int i = x; i < x + num; i++) {
			for(int j = y; j < y + num; j++) {
				if(arr[i][j] != first_num) {
					return false;
				}
			}
		}
		
		return true;
	}
	static void solution(int x, int y, int num) {
		
		int halfX = x + num / 2; //4
		int halfY = y + num / 2; //4
		
		
		if(!check(x,y,num)) {
			System.out.print("(");
			solution(x, y, num/ 2);
			solution(x, halfY, num/ 2);
			solution(halfX, y, num/ 2);
			solution(halfX, halfY, num/ 2);
			System.out.print(")");
		}
		else {
			System.out.print(arr[x][y]);
			
		}
		
		
		
	}
	
	static void input() throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		
		for(int i = 0; i < n; i++) {
			String st = br.readLine();
			for(int j = 0; j < n; j++) {
				arr[i][j] = st.charAt(j);
			}
		}
		
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		input();
		solution(0,0, n);
	}

}
