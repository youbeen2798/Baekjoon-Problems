#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <bool> premium(long long m) { //m���� �Ҽ� ���� �Ǻ����ִ� �Լ�(0�̸� �Ҽ�, 1�̸� �Ҽ� �ƴ�)
	vector <bool> v(m + 1);

	v[0] = 1;
	v[1] = 1;

	for (int i = 2; i <= sqrt(m); i++) {
		if (v[i] == 1) {
			continue;
		}
		for (int j = 2*i; j <= m; j+= i) {
			v[j] = 1;
		}
	}
	return v;
}

int main() {
	ios_base::sync_with_stdio(0); //����� ������
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	long long* array = new long long[n]; //�迭 ����

	for (int i = 0; i < n; i++) {
		cin >> array[i]; //�迭 ���� �Է�
	}

	sort(array, array + n); //�迭 �����ؼ�
	long long m = array[n - 1]; //�迭���� ���� ū ���� ����

	vector <bool> vt = premium(m); //1���� �迭���� ���� ū ����(m)���� �Ҽ��� 0, �Ҽ��� �ƴϸ� 1

	vector <long long> vs;
	for (int i = 0; i < n; i++) {
		if (vt[array[i]] == 0) { // �迭 ���Ұ� �Ҽ��̸�
			vs.push_back(array[i]); //vs �迭�� ����
		}
	}

	if (vs.size() == 0) {
		cout << "-1";
		return 0;
	}

	sort(vs.begin(), vs.end()); //�Ҽ��� ����ִ� �迭�� �����ؼ�
	vs.erase(unique(vs.begin(), vs.end()), vs.end()); //�迭 �ߺ� ���� ����


	//�Ҽ����� �ּҰ������ �Ҽ����� ���� ����
	long long result = 1;
	for (int i = 0; i < vs.size(); i++) {
		result *= vs[i]; // �Ҽ� ���ҵ��� ����
	}

	cout << result; //�ּҰ���� ���


}