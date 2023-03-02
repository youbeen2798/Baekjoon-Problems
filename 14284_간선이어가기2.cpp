#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n; //������ ����
int m; //������ ����
int s; //���� 1
int t; //���� 2

bool visited[5001];
long long dist[5001];
vector<pair<int,int>> nodes[5001]; //����� ������ �Ÿ�

long long ans = 999999999999; 

void bfs(int start) {

	for (int i = 1; i <= n; i++) {
		dist[i] = 999999999999;
	}

	queue<pair<int,int>> q;
	q.push({ start, 0 });
	visited[start] = true;
	dist[start] = 0; //start������ �Ÿ� : 0

	while (!q.empty()) {
		int node = q.front().first;
		int now_dist = q.front().second;

		q.pop();

		if (node == t) {
			if (now_dist < ans) {
				ans = now_dist;
				continue;
			}
		}

		for (int i = 0; i < nodes[node].size(); i++) {
			int next_node = nodes[node][i].first;
			int next_dist = nodes[node][i].second;
			int total_dist = now_dist + next_dist;


			if (dist[next_node] > total_dist) {
				dist[next_node] = total_dist;
				q.push({ next_node, total_dist });
			}
		}
	}


}
void solution() {

	bfs(s);
	cout << ans << "\n";
}

void input() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		nodes[a].push_back({ b,c });
		nodes[b].push_back({ a,c });
		//���� a�� b�� ����ġ : c
	}

	cin >> s >> t;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}