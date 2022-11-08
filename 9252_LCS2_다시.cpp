#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

string s1, s2;
int dp[1001][1001];

void input() {
	cin >> s1 >> s2;
}

void solution() {
	s1 = " " + s1;
	s2 = " " + s2;

	for (int i = 1; i < s2.size(); i++) {
		for (int j = 1; j < s1.size(); j++) {
			if (s2[i] == s1[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	int max_num = dp[s2.size() - 1][s1.size() - 1];
	cout << max_num << "\n";

	queue<pair<int, int>> q;

	int row = s2.size() - 1; //За
	int col = s1.size() - 1; //ї­

	string st = "";
	while (dp[row][col]) {

		if (dp[row][col] == dp[row - 1][col]) {
			row--;
		}
		else if (dp[row][col] == dp[row][col - 1]) {
			col--;
		}
		else {
			st += s2[row];
			row--;
			col--;
		}
	}

	if (st.size() > 0) {
		reverse(st.begin(), st.end());
		cout << st ;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}