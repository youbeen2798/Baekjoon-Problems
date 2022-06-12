//����(a, e, i, o, u) �ϳ��� �ݵ�� �����Ͽ��� �Ѵ�.
//������ 3�� Ȥ�� ������ 3�� �������� ���� �� �ȴ�.
//���� ���ڰ� ���������� �ι� ���� �ȵǳ�, ee �� oo�� ����Ѵ�.

#include <iostream>

using namespace std;

char v[5] = { 'a','e','i','o','u' };

bool function(string st) {


	int cnt = 0;
	for (int i = 0; i < st.length(); i++) {
		for (int j = 0; j < 5; j++) {
			if (st[i] != v[j]) {
				cnt++;
			}
		}
	}

	if (cnt == 5 * st.length()) {
		return false;
	}

	if (st.length() > 2) {
		for (int i = 0; i < st.length() - 2; i++) {
			if (st[i] == 'a' || st[i] == 'e' || st[i] == 'i' || st[i] == 'o' || st[i] == 'u') {
				if (st[i + 1] == 'a' || st[i + 1] == 'e' || st[i + 1] == 'i' || st[i + 1] == 'o' || st[i + 1] == 'u') {
					if (st[i + 2] == 'a' || st[i + 2] == 'e' || st[i + 2] == 'i' || st[i + 2] == 'o' || st[i + 2] == 'u') {
						return false;
					}
				}
			}
		}
	}

	if (st.length() > 2) {
		for (int i = 0; i < st.size() - 2; i++) {
			if (st[i] != 'a' && st[i] != 'e' && st[i] != 'i' && st[i] != 'o' && st[i] != 'u') {
				if (st[i + 1] != 'a' && st[i + 1] != 'e' && st[i + 1] != 'i' && st[i + 1] != 'o' && st[i + 1] != 'u') {
					if (st[i + 2] != 'a' && st[i + 2] != 'e' && st[i + 2] != 'i' && st[i + 2] != 'o' && st[i + 2] != 'u') {
						return false;
					}
				}
			}
		}
	}

	if (st.length() >= 2) {
		for (int i = 0; i < st.length() - 1; i++) {
			if (st[i] == st[i + 1] && (st[i] != 'e') && st[i] != 'o') {
				return false;
			}
		}
	}
	
	return true;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1) {

		string st;
		cin >> st;

		if (st == "end") {
			return 0;
		}
		bool h = function(st);

		if (h) {
			cout << "<" << st << ">" << " is acceptable.\n";
		}
		else {
			cout << "<" << st << ">" << " is not acceptable.\n";
		}
	}

	
}