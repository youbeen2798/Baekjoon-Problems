#include <iostream>
#include <cstdio>

using namespace std;

char c1[1001];
char c2[1001];

int dp[1005][1005] = { 0, };

string s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		c1[i + 1] = s[i];
	}
	int a = s.size();


	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		c2[i + 1] = s[i];
	}
	int b = s.size();

	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			dp[i][j] = max(max( dp[i - 1][j - 1] + (c1[i] == c2[j]), dp[i - 1][j]), dp[i][j - 1]);
		}
	}
	
	cout << dp[a][b];

}