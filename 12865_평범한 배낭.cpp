#include <iostream>
#define MAX 101

using namespace std;
int N, K;

int weight[MAX];
int value[MAX];
int dp[MAX][100001];

int Max(int A, int B) {
	if (A > B)
		return A;
	else
		return B;
}


void Input()
{
	cin >> N >> K; // 물건 개수 >> 최대 무게
	for (int i = 1; i <= N; i++)
	{
		cin >> weight[i] >> value[i]; // 각 물건 무게 >> 각 물건 가치
	}
}

void Solution()
{
	for (int j = 1; j <= N; j++) //각 물건마다
	{
		for (int m = 1; m <= K; m++) //1부터 최대 무게까지
		{
			if (m >= weight[j]) //만약 무게가 각 물건의 무게보다 크다면
				dp[j][m] = Max(dp[j - 1][m], dp[j-1][m - weight[j]] + value[j]); // 해당 차례의 물건을 아예 넣지 않은것과 넣은 것의 가치를 비교
			else //만약 무게가 각 물건의 무게보다 작다면
				dp[j][m] = dp[j - 1][m]; // 해당 물건을 넣지 않고 최대 무게를 만드는 것
		}
	}

	cout << dp[N][K] << "\n"; // 가장 가치가 높은 것 
}

void Solve()
{
	Input();
	Solution();
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solve();
}