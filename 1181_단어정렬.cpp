#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string i, string j) {
	if (i.length() == j.length()) { //���̰� ������
		return i < j; //����������
	}
	else {
		return i.length() < j.length(); //���̰� ª���ͺ���
	}
}

int main() {

	ios_base::sync_with_stdio(0); //����� ������
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector <string> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), compare); //�迭 ����


	for (int i = 0; i < n; i++) {
		cout << v[i] << "\n";
		for (int j = i + 1; j < n; j++) {
			if (v[j] == v[i]) { //�ݺ��Ǵ� ���Ҵ� ��� ���� 
				i = j;
			}
		}
	}
}