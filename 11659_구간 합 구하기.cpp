#include <iostream>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	int* array = new int[n + 1];

	array[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> array[i]; //�迭 �Է� �ޱ�
		array[i] += array[i - 1]; //�迭�� ���������� ����
	}

	for (int j = 0; j < m; j++) {
		int start, end;
		cin >> start >> end;

		int result = array[end] - array[start - 1]; //���� �տ��� ���� �ƴ� �͵��� ������ ����
		cout << result << '\n';
	}
}
