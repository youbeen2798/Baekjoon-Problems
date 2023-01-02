#include <iostream>

using namespace std;

string st;

void input() {
	cin >> st;
}

void finish() {
	cout << "NOISE";
	exit(0);
}
void solution() {
	for (int i = 0; i < st.size(); i++) {
		cout << "i: " << i << "\n";
		if (st[i] == '0') { //i = 13
			if (i + 1 >= st.size()) {
				finish();
			}
			if (!(st[i+1] == '1')) {
				finish();
			}
			i++;
		}
		else if (st[i] == '1') {
			if (i + 3 >= st.size()) {
				finish();
			}
			if (!(st[i + 1] == '0' && st[i + 2] == '0')) {
				finish();
			}
			if (st[i + 3] == '0') {
				int one_start = -1;
				for (int j = i + 3; j < st.size(); j++) {
					if (st[j] == '1') {
						one_start = j;
						break;
					}
				}
				if (one_start == -1) { //0뒤에 1이 안 왔다면
					finish();
				}
				for (int j = one_start; j < st.size(); j++) {
					if (st[j] == '1') {
						i = j;
					}
					else {
						break;
					}
				}
				//현재 i=5
	//			cout << "중간 i: " << i << "\n";
				if (i + 2 < st.size() && st[i + 1] == '0' && st[i + 2] == '0' && st[i-1] != '0') {
					i -= 1;
				}
			}
			else if (st[i + 3] == '1') {
				for (int j = i + 3; j < st.size(); j++) {
					if (st[j] == '1') {
						i = j;
					}
					else {
						break;
					}
				}
				//현재 i=5
//				cout << "중간 i: " << i << "\n";
				if (i + 2 < st.size() && st[i + 1] == '0' && st[i + 2] == '0' && st[i-1] != '0') {
					i -= 1;
				}
			}
		}
	}

	cout << "SUBMARINE";
}
//1000011110000111
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}