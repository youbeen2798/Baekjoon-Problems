#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m; //도시의 개수, 버스 개수
int real_start; //출발점의 도시 번호
int real_end; //도착지의 도시 번호

vector<pair<int, int>> v[1001]; //도착지, 버스비용
int dist[1001];

void solution() {

	for (int i = 1; i <= n; i++) {
		dist[i] = 999999999;
	}
	queue<pair<int, int>> q;
	q.push({ real_start, 0 });

	while (!q.empty()) {
		int now_node = q.front().first;
		int now_dist = q.front().second;

		q.pop();

		for (int i = 0; i < v[now_node].size(); i++) {
			int next_node = v[now_node][i].first;
			int next_dist = v[now_node][i].second;

			if (now_dist + next_dist < dist[next_node]) {
				dist[next_node] = now_dist + next_dist;
				//			cout << "node: " << next_node << " dist: " << now_dist + next_dist << "\n";
				q.push({ next_node, now_dist + next_dist });
			}
		}
	}

	cout << dist[real_end];
}

void input() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int start, end, cost;
		//start : 출발 도시 번호
		//end : 도착지 도시 번호
		//start에서 end까지 버스 비용
		cin >> start >> end >> cost;
		v[start].push_back({ end, cost });
		//도착지와 버스비용
	}

	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}

	cin >> real_start >> real_end;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}