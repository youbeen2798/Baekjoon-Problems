#include <iostream>

#define MAX 1000000000
using namespace std;

long long dp[101][10] = { 0, };
int n;
long long sum = 0;

int main()
{
	cin >> n;

	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {

		for (int j = 0; j < 10; j++) {
			if (j == 0)
				dp[i][0] = dp[i - 1][j + 1];
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

			dp[i][j] %= MAX;
		}

	}


	for (int i = 0; i <= 9; i++) {
		sum = (sum + dp[n][i]) % MAX;
	}

	cout << sum;

	return 0;
}