#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); //입출력 빠르게
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T; //TestCase 입력받기

	for (int i = 0; i < T; i++) {
		int dp[10001] = { 0 };
		dp[0] = 1; //0원을 채우는 방법은 1개
		int N;
		cin >> N; //동전 개수 입력받기
		int* coin = new int[N];
		for (int j = 0; j < N; j++) {
			cin >> coin[j]; //동전의 각 금액 입력받기
		}
		int money;
		cin >> money; //채워야할 돈 입력받기

		for (int k = 0; k < N; k++) {
			for (int m = coin[k]; m <=  money; m++)
				dp[m] = dp[m] + dp[m - coin[k]]; // 마지막으로 특정 동전이 입력됬을 때와 되지 않았을 때
		}

		cout << dp[money] <<"\n";
	}
}