#include <iostream>
#include <algorithm>

using namespace std;

int n;
int t[16];
int p[16];
int ans = 0;

void dfs(int day, int cost) {

	//현재 day까지 cost만큼 벌었음 10을 시작할까 말까 할 수 있음
	ans = max(ans, cost);

	if (day > n) {
		return;
	}

	//day를 포함하는 경우
	if (day + t[day] <= n + 1) {
		dfs(day + t[day], cost + p[day]);
	}

	//day를 포함하지 않는 경우
	if (day + 1 <= n) {
		ans = max(ans, cost);
		dfs(day + 1, cost);
	}
}
void solution() {

	dfs(1, 0);
	cout << ans;
}

void input() {

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}
}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}