// �ڿ��� N�� M�� �־����� ��, 
//1���� N���� �ڿ��� �߿��� M���� �� �������� ������ ����ϴ� ���α׷�
//���� ���� ���� �� ��� ��

#include <iostream>

using namespace std;

int n, m;
int d = 1;

int arr[8];

void func(int k) {

	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << "\n";
	}
	else {
		for (int i = 1; i <= n; i++) {
			arr[k] = i;
			func(k + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); // ����� ������
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m; //N �Է� >> M �Է�


	func(0);
}