#include <iostream>

using namespace std;

int v; //마을
int e; //도로
int cost[401][401];

void solution() {

	int ans = 99999999;

	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (cost[i][j] > cost[i][k] + cost[k][j]) {
					cost[i][j] = cost[i][k] + cost[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (cost[i][i] != 99999999) {
			ans = min(ans, cost[i][i]);
		}
	}

	if (ans != 99999999) {
		cout << ans;
	}
	else {
		cout << -1;
	}
}
void input() {

	cin >> v >> e;

	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			cost[i][j] = 99999999;
		}
	}

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		cost[a][b] = c;
	}
}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}