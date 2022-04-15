#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector <bool> check(int n) { //�Ҽ� ���ϴ� �Լ� (�����佺�׳׽��� ü)
	vector <bool> v(n+1);
	v[0] = 1;
	v[1] = 1;

	for (int i = 2; i <= sqrt(n); i++) { //n���� �Ҽ��� �˰� ���� ��, ������ ������ ���� ����� ����� �ȴ�!
		if (v[i] == 1) {
			continue;
		}
		for (int j = 2 * i; j <= n; j += i) {
			v[j] = 1;
		}
	}

	return v;

}
int main() {
	ios_base::sync_with_stdio(0); //����� ������
	cin.tie(0);
	cout.tie(0);

	int m, n;
	cin >> m >> n;

	vector <bool> v = check(n); // �Լ� ��ȯ�Ͽ� ���� v�� ����

	vector <int> vt;

	int sum = 0;
	for (int i = m; i <= n; i++) { //�Ҽ��ΰ͸� ���� ���� vt�� ����
		if (v[i] == 0) {
			sum += i;
			vt.push_back(i);
		}
	}
	
	if (vt.size() == 0) { //�Ҽ��� ������(���� vt�� ����� 0�̸�)
		cout << "-1";
	}
	else {
		cout << sum << "\n"; //�Ҽ��� �� ���
		cout << vt[0]; //�Ҽ� �� ���� ���� �� ���(���� ���ص� ���� ���� ���� index 0�� ����)
	}



}