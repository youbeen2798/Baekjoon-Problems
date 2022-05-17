#include <iostream>

using namespace std;

int n;
int cost[501];
int tri[501][501];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	
	for (int i = 0; i < 501; i++) {
		tri[0][i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			cin >> cost[j]; 
		}

		tri[i][0] = tri[i - 1][0] + cost[0];
		for (int j = 1; j < i - 1; j++) {
			tri[i][j] = max(tri[i - 1][j - 1], tri[i - 1][j]) + cost[j];
		}
		tri[i][i - 1] = tri[i - 1][i - 2] + cost[i - 1];
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < tri[n][i])
			max = tri[n][i];
	}
	cout << max;
}