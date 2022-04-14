#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector <int> v;

	while (n != 0) {
		v.push_back(n % 10); //���� ������ ���� ���Ϳ� ����
		n /= 10;
	}

	sort(v.rbegin(), v.rend()); //���� ��������

	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
}
