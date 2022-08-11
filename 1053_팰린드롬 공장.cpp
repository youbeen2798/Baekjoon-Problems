#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

string st;

int dp[51][51];

int solve(int left, int right) {

	if (dp[left][right] != -1) {
		return dp[left][right];
	}
	else if (left >= right) {
		return 0;
	}
	dp[left][right] = min({ solve(left + 1, right) + 1, solve(left, right - 1) + 1, solve(left + 1, right - 1) + (st[left] != st[right]) });

	return dp[left][right];

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> st;

	memset(dp, -1, sizeof(dp));

	int answer = solve(0, st.size() - 1);


	cout << answer << "\n";

	for (int i = 0; i < st.size() - 1; i++) {
		for (int j = i + 1; j < st.size() - 1; j++) {
			memset(dp, -1, sizeof(dp));
			swap(st[i], st[j]);
			answer = min(answer, solve(0, st.size() - 1) + 1);
			swap(st[i], st[j]);
		}
	}

	cout << answer;
}
