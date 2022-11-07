#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
bool visited[1000001];

int f, s, g, u, d;
void input() {
	cin >> f >> s >> g >> u >> d;
}

void solution() {

	q.push({ s,0 });
	visited[s] = true;

	while (!q.empty()) {
		int floor = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (floor == g) {
			cout << cnt;
			return;
		}
		if (0 <= floor + u && floor + u <= f && !visited[floor + u]) {
			q.push({ floor + u, cnt + 1 });
			visited[floor + u] = true;
		}
		if (0 <= floor - d && floor - d <= f && !visited[floor - d]) {
			q.push({ floor - d, cnt + 1 });
			visited[floor - d] = true;
		}
	}

	cout << "use the stairs";
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}