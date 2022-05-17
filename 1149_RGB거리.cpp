#include <iostream>

using namespace std;

long long house[1001][3];
int n;
int cost[3];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	house[0][0] = 0;
	house[0][1] = 0;
	house[0][2] = 0;

	for (int i = 1; i <= n; i++) {
		cin >> cost[0] >> cost[1] >> cost[2];

		house[i][0] = min(house[i - 1][1], house[i - 1][2]) + cost[0];
		house[i][1] = min(house[i - 1][0], house[i - 1][2]) + cost[1];
		house[i][2] = min(house[i - 1][0], house[i - 1][1]) + cost[2];
	}
	
//	cout << house[n][0] << " " << house[n][1] <<  " " << house[n][2] << "\n";
	
	int mini = 1000000000;

	for (int i = 0; i < 3; i++) {
		if (house[n][i] < mini) {
			mini = house[n][i];
		}
	}

	cout << mini;
}