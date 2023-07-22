#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n;

vector<int> adj[3010];
bool cycle[3010]; //순환선 여부
bool visited[3010]; //방문 여부
int dist[3010];
bool flag_cycle; 

void dfs(int start, int now, int line) {

	visited[now] = true;
	cycle[now] = true;

	for (int i = 0; i < adj[now].size(); i++) {
		int adj_st = adj[now][i];

		if (start == adj_st && line >= 2) { //순환이라면
			flag_cycle = true;
			return;
		}

		if (!visited[adj_st]) { //아직 방문하지 않았다면
			dfs(start, adj_st, line + 1);
		}

		if (flag_cycle) {
			return;
		}
	}

	visited[now] = false;

	if (!flag_cycle) {
		cycle[now] = false;
	}
}
void find_cycle() {
	//순환선 찾기
	for (int i = 1; i <= n; i++) {
		if (!flag_cycle) {
			dfs(i, i, 0);
		}
		else {
			break;
		}
	}
}

void bfs(int station) {


	memset(visited, false, sizeof(visited));
	queue<pair<int,int>> q;
	q.push({station, 0});
	visited[station] = true;

	while (!q.empty()) {

		int a = q.front().first;
		int d = q.front().second;
		q.pop();

		vector<int> adj_v = adj[a];
		for (int i = 0; i < adj_v.size(); i++) {
			int adj_v_st = adj_v[i]; //인접한 역

			if (cycle[adj_v_st]) { //인접한 역이라면
				dist[station] = d + 1;
				return;
			}

			if (!visited[adj_v_st]) { //방문하지 않았으면
				q.push({ adj_v_st, d + 1 });
				visited[adj_v_st] = true;
			}

			
		}
	}
}
void solve_dist() {

	for (int i = 1; i <= n; i++) {

		if (!cycle[i]) {
			bfs(i);
		}
		else {
			dist[i] = 0;
		}
	}
}
void solution() {

	find_cycle();
	solve_dist();

	for (int i = 1; i <= n; i++) {
		cout << dist[i] << " ";
	}
}
void input() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a); 
	}

}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}