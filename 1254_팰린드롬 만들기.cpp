#include <iostream>

using namespace std;

string st;

bool dp[60][60];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> st;

	string st2 = "";

	int mx2 = 0;

	for (int i = st.size() - 1; i >= 0; i--) {
		st2 += st[i];
	}

	for (int k = st2.size() - 1; k >= 0; k--) { //k = 0
		for (int j = k; j <= st2.size() - 1; j++) { // j = 0
			if (j == k) {
				dp[k][j] = true;
				if (k == 0) {
					mx2 = max(mx2, j - k + 1);
				}
				continue;
			}
			if (st2[k] == st2[j]) {
				if (j == k + 1) {
					dp[k][j] = true;
					if (k == 0) {
						mx2 = max(mx2, j - k + 1);
					}
				}
				else {
					if (dp[k + 1][j - 1]) {
						dp[k][j] = true;
						if (k == 0) {
							mx2 = max(mx2, j - k + 1);
						}
					}
				}
			}
		}
	}


	int answer = (st.size() - mx2) * 2 + mx2;

	cout << answer;

}