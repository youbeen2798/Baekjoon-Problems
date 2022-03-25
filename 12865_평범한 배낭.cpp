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
	cin >> N >> K; // ���� ���� >> �ִ� ����
	for (int i = 1; i <= N; i++)
	{
		cin >> weight[i] >> value[i]; // �� ���� ���� >> �� ���� ��ġ
	}
}

void Solution()
{
	for (int j = 1; j <= N; j++) //�� ���Ǹ���
	{
		for (int m = 1; m <= K; m++) //1���� �ִ� ���Ա���
		{
			if (m >= weight[j]) //���� ���԰� �� ������ ���Ժ��� ũ�ٸ�
				dp[j][m] = Max(dp[j - 1][m], dp[j-1][m - weight[j]] + value[j]); // �ش� ������ ������ �ƿ� ���� �����Ͱ� ���� ���� ��ġ�� ��
			else //���� ���԰� �� ������ ���Ժ��� �۴ٸ�
				dp[j][m] = dp[j - 1][m]; // �ش� ������ ���� �ʰ� �ִ� ���Ը� ����� ��
		}
	}

	cout << dp[N][K] << "\n"; // ���� ��ġ�� ���� �� 
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