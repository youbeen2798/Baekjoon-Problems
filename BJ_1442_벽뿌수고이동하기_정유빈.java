package algorithm_study;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Position_info{
	int x;
	int y;
	int wall_num;
	
	public Position_info(int x, int y, int wall_num) {
		this.x = x;
		this.y = y;
		this.wall_num = wall_num;
	}
	
}
public class BJ_1442_벽뿌수고이동하기_정유빈 {

	static int n,m,k;
	static char [][] map = new char[1001][1001];
	static int [][][] dist = {{{0,}}};
	static int [] dx = {1,-1,0,0};
	static int [] dy = {0,0,1,-1};
	static int ans = Integer.MAX_VALUE;

	
	static void solution() {
		
		Queue<Position_info> q = new LinkedList<>();
		
		q.add(new Position_info(1,1,0)); 
		dist[1][1][0] = 1;
		
		while(!q.isEmpty()) {
			
			
			int x = q.peek().x;
			int y = q.peek().y;
			int wall_num = q.peek().wall_num;
			

			q.poll();
			
			for(int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if(1<= nx && nx <= n && 1 <= ny && ny <= m) {
					if(map[nx][ny] == '0' && wall_num <= k && dist[nx][ny][wall_num] == 0) {
						dist[nx][ny][wall_num] = dist[x][y][wall_num] + 1;
						q.add(new Position_info(nx,ny, wall_num));
					}
					else if(map[nx][ny] == '1' && wall_num + 1 <= k && dist[nx][ny][wall_num + 1] == 0) {
						dist[nx][ny][wall_num + 1] = dist[x][y][wall_num] + 1;
						q.add(new Position_info(nx,ny, wall_num + 1));
					}
				}
			}
		}
		
		for(int i = 0; i <= k; i++) {
			if(dist[n][m][i] != 0) {
				ans = Math.min(ans, dist[n][m][i]);
			}
		}
		
		if(ans == Integer.MAX_VALUE) {
			System.out.println(-1);
		}
		else {
			System.out.println(ans);
		}
	}
	static void input() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tokenizer = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(tokenizer.nextToken());
		m = Integer.parseInt(tokenizer.nextToken());
		k = Integer.parseInt(tokenizer.nextToken());

		for(int i = 1; i <= n; i++) {
			String input = br.readLine();
			for(int j = 0; j < input.length(); j++) {
				map[i][j + 1] = input.charAt(j);
			}
		}
		
		dist = new int[1001][1001][k+1];
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		input();
		solution();
	}

}
