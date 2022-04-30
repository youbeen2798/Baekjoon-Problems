#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector <pair<char, int>> v(36);

	for (int i = 0; i < 36; i++) {
		cin >> v[i].first >> v[i].second;
	}

	for (int i = 0; i < 35; i++) {
		if (abs(v[i].first - v[i + 1].first) == 2 && abs(v[i].second - v[i + 1].second) == 1) { //ĭ�� ĭ ������ ���̰� 2 1
			continue;
		}
		else if (abs(v[i].first - v[i + 1].first) == 1 && abs(v[i].second - v[i + 1].second) == 2) { //ĭ�� ĭ ������ ���̰� 1 2
			continue;
		}
		else {
			cout << "Invalid"; //ĭ�� ĭ ������ ���̰� 2 1 Ȥ�� 1 2�� �ƴ϶��
			return 0;
		}
	}

	if (abs(v[35].first - v[0].first) == 2 && abs(v[35].second - v[0].second) == 1) { 	//������ ĭ���� ù��° ĭ�� ���̰� 2 1
	}
	else if (abs(v[35].first - v[0].first) == 1 && abs(v[35].second - v[0].second) == 2) { //������ ĭ���� ù��° ĭ�� ���̰� 1 2
	}
	else {
		cout << "Invalid"; 	//������ ĭ���� ù��° ĭ�� ���̰� 2 1 Ȥ�� 1 2�� �ƴ϶��
		return 0;
	}


	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end()); // ��ġ�� �ߺ� ���� ����

	//�ߺ� ���� Ȯ��
	if (v.size() != 36) { // ��ġ�� ���Ұ� �ִٸ�, ��� ĭ�� �湮���� �������̹Ƿ�
		cout << "Invalid"; //Invalid ���
		return 0;
	}
	else {
		cout << "Valid"; //��ġ�� ���ҵ� ����, ĭ�� ĭ ������ ���̰� ��� 2 1 Ȥ�� 1 2�̹Ƿ�
	}
}