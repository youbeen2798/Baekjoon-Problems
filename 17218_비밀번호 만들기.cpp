#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string st1;
string st2;
int num;
string dp[45][45];

void solution() {

	for (int i = 0; i < st1.size(); i++) {
		for (int j = 0; j < st2.size(); j++) {
			if (st1[i] == st2[j]) {
				dp[i + 1][j + 1] = dp[i][j] + st1[i];
			}
			else if (dp[i + 1][j].size() > dp[i][j + 1].size()) {
				dp[i + 1][j + 1] = dp[i + 1][j];
			}
			else {
				dp[i + 1][j + 1] = dp[i][j + 1];
			}
		}
	}
	
	cout << dp[st1.size()][st2.size()];
}
void input() {

	cin >> st1 >> st2;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}