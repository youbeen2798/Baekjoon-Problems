#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;

vector <pair<int, int>> adj[1001];
int dist[1001] = { 0, };

int bfs(int start, int end) {
	queue <int> q;
	fill(dist, dist + 1001, -1);
	dist[start] = 0;

	q.push(start);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto next : adj[cur]) {
			if (dist[next.first] != -1) {
				continue;
			}
			dist[next.first] = dist[cur] + next.second;
			q.push(next.first);
		}
	}

	return dist[end];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n - 1; i++) {
		int from, to, dist;
		cin >> from >> to >> dist;
		adj[from].push_back({ to,dist });
		adj[to].push_back({ from,dist });
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << bfs(a, b);
	}

}