#include <iostream>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int array[1025][1025] = { 0, };
	int dp[1025][1025] = { 0, };

	int row, col;
	cin >> row >> col; //행렬 행렬값 입력받기


	for (int k = 1; k <= row; k++) {
		for (int j = 1; j <= col; j++) {
			cin >> array[k][j]; //행렬 원소 입력받기
			dp[k][j] = dp[k - 1][j] + dp[k][j - 1] + array[k][j] - dp[k - 1][j - 1]; //중복요소 제거까지
		}
	}

	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int sum = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
		cout << sum;
	}
	
}
