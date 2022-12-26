#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n; //노드 개수
int ans = 0;

bool visited[10001];
vector <pair<int,int>> vt[10001];

void input() {
	cin >> n; //노드 개수

	for (int i = 1; i < n; i++) {
		int parent, child, dist;
		cin >> parent >> child >> dist;
		vt[parent].push_back({ child, dist });
		vt[child].push_back({ parent, dist });
	}
}

void bfs(int start) {

	queue<pair<int, int>> q; //현재 노드와 지금까지 거리
	memset(visited, false, sizeof(visited));

	q.push({ start, 0 });
	visited[start] = true;

	while (!q.empty()) {
		int now_node = q.front().first; //기준 노드
		int now_dist = q.front().second; //지금까지 거리
		q.pop();

		for (int i = 0; i < vt[now_node].size(); i++) {
			int next_node = vt[now_node][i].first; //연결된 다음 노드
			int next_dist = vt[now_node][i].second;

			if (!visited[next_node]) { //다음 노드가 아직 방문되지 않았다면
				q.push({ next_node, now_dist + next_dist });
				visited[next_node] = true;
				ans = max(ans, now_dist + next_dist);
			}
		}
	}
}
void solution() {

	for (int i = 1; i < n; i++) {
		bfs(i);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
	cout << ans;
}