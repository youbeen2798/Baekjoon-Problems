package algorithm_study;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

class Pair{
	int x;
	int y;
	
	Pair(int x, int y){
		this.x = x;
		this.y = y;
	}
}
public class BJ_10026_적록색약_정유빈 {

	static int n;
	static char[][] arr = new char[101][101];
	static boolean [][] visited = new boolean[101][101];
	static int [][] copy_arr = new int[101][101];

	static int dx[] = {1,-1,0,0};
	static int dy[] = {0,0,1,-1};
	
	static void bfs(int x, int y) {
		Queue<Pair> q = new LinkedList<>();
		q.add(new Pair(x,y));
		visited[x][y] = true;
		int num = copy_arr[x][y];
		
		while(!q.isEmpty()) {
			int a = q.peek().x;
			int b = q.peek().y;
			
			System.out.println(a);

			q.poll();
			
			for(int i = 0; i < 4; i++) {
				int nx = a + dx[i];
				int ny = b + dy[i];
				
				if(0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny] && num == copy_arr[nx][ny]) {
					q.add(new Pair(nx,ny));
					visited[nx][ny] = true;
				}
			}
		}
	}
	static void solution() {
		
		for(int i = 0; i < n; i++) {
			for(int j =0; j < n; j++) {
				if(arr[i][j] == 'R' || arr[i][j] == 'G') {
					copy_arr[i][j] = 0;
				}
				else {
					copy_arr[i][j] = 1;
				}
			}
		}
		
		int ans1 = 0;
		
		for(int i = 0; i < n; i++) {
			for(int j =0; j < n; j++) {
				if(!visited[i][j]) {
					bfs(i,j);
					ans1++;
				}
			}
		}
		
		for(int i = 0; i < n; i++) {
			for(int j =0; j < n; j++) {
				visited[i][j] = false;
			}
		}
		
		for(int i = 0; i < n; i++) {
			for(int j =0; j < n; j++) {
				if(arr[i][j] == 'R' ) {
					copy_arr[i][j] = 0;
				}
				else if(arr[i][j] == 'G') {
					copy_arr[i][j] = 1;
				}
				else {
					copy_arr[i][j] = 2;
				}
			}
		}
		

		int ans2 = 0;
		for(int i = 0; i < n; i++) {
			for(int j =0; j < n; j++) {
				if(!visited[i][j]) {
					bfs(i,j);
					ans2++;
				}
			}
		}
		
		System.out.println(ans1 + " " + ans2);
		
	}
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine());
		
		for(int i =0; i < n; i++) {
			String input = br.readLine();
			for(int j = 0; j < n; j++) {
				arr[i][j] = input.charAt(j);
			}
		}
		
		solution();
	}

}
