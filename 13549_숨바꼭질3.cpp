#include <iostream>
#include <queue>
using namespace std;

int n; //ÇöÀç Á¡
int k; //
bool visited[100001];

void solution() {
	queue<pair<int, int>> q;

	q.push({ n, 0 });
	visited[n] = true;

	while (!q.empty()) {
		int a = q.front().first;
		int cnt = q.front().second;

		if (a == k) {
			cout << cnt;
			break;
		}
		q.pop();

		if (!visited[2 * a] && 2 * a >= 0 && 2 * a <= 100000) {
			visited[2 * a] = true;
			q.push({ 2 * a, cnt });
		}
		if (!visited[a - 1] && a - 1 >= 0 && a - 1 <= 100000) {
			visited[a - 1] = true;
			q.push({ a - 1, cnt + 1 });
		}

		if (!visited[a + 1] && a + 1 >= 0 && a + 1 <= 100000) {
			visited[a + 1] = true;
			q.push({ a + 1, cnt + 1 });
		}
		

	}
}

void input() {
	cin >> n >> k;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}