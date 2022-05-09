#include <iostream> 
#include <queue> 
using namespace std;

string map[100];
int dis[100][100];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int n, m;
queue <pair<int, int> > q;



void bfs(int x, int y) {

	q.push(make_pair(x, y)); //0 0
	dis[x][y] = 1; //dis[0][0] =1

	while (!q.empty()) {

		x = q.front().first; //0
		y = q.front().second; //0
		q.pop();
		for (int k = 0; k < 4; k++) {
			int new_x = x + dx[k]; //1
			int new_y = y + dy[k]; //0

			if (0 <= new_x && new_x < n && 0 <= new_y
				&& new_y < m && map[new_x][new_y] == '1'
				&& dis[new_x][new_y] == 0)
			{
				q.push(make_pair(new_x, new_y)); // 1 0
				dis[new_x][new_y] = dis[x][y] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	bfs(0, 0);

	cout << dis[n - 1][m - 1];
}