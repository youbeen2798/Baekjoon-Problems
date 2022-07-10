#include <iostream>

using namespace std;

int n;
int startt;
int link;
int arr[21][21] = { 0, };
int answer = 100000000;

bool check[22] = { false };

void dfs(int cnt, int pov) { // 0, 3

	if (cnt == n / 2) {
		cout << "***" << "\n";
		startt = 0;
		link = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (check[i] == true && check[j] == true) {
//					cout << "i: " << i << "j: " << j << "\n";
//					cout << "arr[i][j]: " << arr[i][j] << "\n";
//					cout << "arr[j][i]: " << arr[j][i] << "\n";
					startt += arr[i][j];
				}
				if (check[i] == false && check[j] == false) {
					link += arr[i][j];
				}
			}
		}

//		cout << "start: " << startt << " " << "link: " << link << "\n";

		int tmp = abs(startt - link);

		if (tmp < answer) {
			answer = tmp;
		}
	}
	for (int i = pov; i < n; i++) {
		check[i] = true; //check[1] = true
		dfs(cnt + 1, i + 1);
		check[i] = false;
	}

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0, 1);

	cout <<  answer;

}