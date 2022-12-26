#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n; //��� ����
int ans = 0;

bool visited[10001];
vector <pair<int,int>> vt[10001];

void input() {
	cin >> n; //��� ����

	for (int i = 1; i < n; i++) {
		int parent, child, dist;
		cin >> parent >> child >> dist;
		vt[parent].push_back({ child, dist });
		vt[child].push_back({ parent, dist });
	}
}

void bfs(int start) {

	queue<pair<int, int>> q; //���� ���� ���ݱ��� �Ÿ�
	memset(visited, false, sizeof(visited));

	q.push({ start, 0 });
	visited[start] = true;

	while (!q.empty()) {
		int now_node = q.front().first; //���� ���
		int now_dist = q.front().second; //���ݱ��� �Ÿ�
		q.pop();

		for (int i = 0; i < vt[now_node].size(); i++) {
			int next_node = vt[now_node][i].first; //����� ���� ���
			int next_dist = vt[now_node][i].second;

			if (!visited[next_node]) { //���� ��尡 ���� �湮���� �ʾҴٸ�
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