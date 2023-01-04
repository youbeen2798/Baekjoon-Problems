#include <iostream>
using namespace std;

string st;

void solution() {

	while (true) {
		bool flag = false;
		for (int i = 0; i < st.size() - 1; i++) {
			char c1 = st[i];
			char c2 = st[i + 1];
			if (c1 == '(' && c2 == ')') {
				flag = true;
				st.erase(st.begin() + i + 1);
				st.erase(st.begin() + i);
			}
		}
		if (!flag) {
			cout << st.size() << "\n";
			exit(0);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> st;

	solution();

	//왼쪽에 )만큼 붙이기
}