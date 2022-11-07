#include <iostream>
#include <queue>

using namespace std;

int n, k;
void input() {
	cin >> n >> k;
}

void solution() {
	queue<pair<int, int>> q;
	q.push({ n,0 });

	while (!q.empty()) {
		int a = q.front().first;
		int cnt = q.front().second;
		
		q.pop();
		if (a == k) {
			cout << cnt;
			break;
		}
		if (0 <= a + 1 && a + 1 <= 100000) {
			q.push({ a + 1, cnt + 1 });
		}
		if (0 <= a - 1 && a - 1 <= 100000) {
			q.push({ a - 1, cnt + 1 }); 
		}
		if (0 <= 2 * a && 2 * a <= 100000) {
			q.push({ 2 * a, cnt + 1 });
		}
	}

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}