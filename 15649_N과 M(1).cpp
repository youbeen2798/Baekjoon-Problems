//��Ʈ��ŷ �˰���
//���� n�� m�� �־����� �� nPm�� ��� ����� ���� ����ϴ� ���α׷�

#include <iostream>

using namespace std;

int n, m;
int arr[20] = { 0, };
bool isused[21] = { false, };

void func(int k) { //0
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << "\n";
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (!isused[i]) { 
				arr[k] = i;
				isused[i] = 1;
				func(k + 1); //���� �ε����� ���� ���ϴ� ��
				isused[i] = 0;
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0); //����� ������
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	func(0);
}