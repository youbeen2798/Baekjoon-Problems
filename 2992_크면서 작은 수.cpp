#include <iostream>
#include <algorithm>
using namespace std;

string input;
string output;
int arr[10];

bool compare2(string st) {
	for (int i = 0; i < st.size() - 1; i++) {
		if (st[i] < st[i + 1]) {
			return false;
		}
	}
	return true;
}
void solution() {
	for (int i = input.size() - 1; i >= 0; i--) {
		string startt = input.substr(0, i);
		string tmp = input.substr(i, input.size());
		if (!compare2(tmp)) {
			char num = input[i];
			tmp.erase(find(tmp.begin(), tmp.end(), num)); //3
			sort(tmp.begin(), tmp.end()); //24
			for (int j = 0; j< tmp.size(); j++) {
				if (tmp[j] >= num) {
					char medium = tmp[j];
					tmp.erase(find(tmp.begin(), tmp.end(), medium)); //2
					tmp += num; //23
					sort(tmp.begin(), tmp.end()); //32
					cout << startt + medium + tmp; //15423
					exit(0);
				}
			}

		}
	}
	cout << "0";
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> input;

	solution();
}