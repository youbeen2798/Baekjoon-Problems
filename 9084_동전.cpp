#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); //����� ������
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T; //TestCase �Է¹ޱ�

	for (int i = 0; i < T; i++) {
		int dp[10001] = { 0 };
		dp[0] = 1; //0���� ä��� ����� 1��
		int N;
		cin >> N; //���� ���� �Է¹ޱ�
		int* coin = new int[N];
		for (int j = 0; j < N; j++) {
			cin >> coin[j]; //������ �� �ݾ� �Է¹ޱ�
		}
		int money;
		cin >> money; //ä������ �� �Է¹ޱ�

		for (int k = 0; k < N; k++) {
			for (int m = coin[k]; m <=  money; m++)
				dp[m] = dp[m] + dp[m - coin[k]]; // ���������� Ư�� ������ �Է��� ���� ���� �ʾ��� ��
		}

		cout << dp[money] <<"\n";
	}
}