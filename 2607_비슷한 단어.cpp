#include <iostream>

using namespace std;

int n;
string base;
int arr[26];
int arr2[26];
int ans = 0;

void solve(string st) {

	for (int i = 0; i < 26; i++) {
		arr2[i] = arr[i];
	}
	
	if (base.size() == st.size()) { //같은 크기라면
		int num = 0;
		for (int i = 0; i < st.size(); i++) {
			if (arr2[st[i] - 'A'] > 0) {
				arr2[st[i] - 'A']--;
				continue;
			}
			num++;
			if (num >= 2) {
				return;
			}
		}
	}
	else if (base.size() == st.size() + 1) {
		//기본 문자열이 더 크다면
		//APPLE
		//APPL 
		//완전 같아야 함
		int num = 0;
		for (int i = 0; i < st.size(); i++) {
			if (arr2[st[i] - 'A'] > 0) {
				arr2[st[i] - 'A']--;
				continue;
			}
			return;
		}
	}
	else if (base.size() + 1 == st.size()) {
		int num = 0;
		for (int i = 0; i < st.size(); i++) {
			if (arr2[st[i] - 'A'] > 0) {
				arr2[st[i] - 'A']--;
				continue;
			}
			num++;
			if (num >= 2) {
				return;
			}
		}
	}
	else {
		return;
	}

	ans++;
}

void input() {
	cin >> n;
	cin >> base;

	for (int i = 0; i < base.size(); i++) {
		arr[base[i] - 'A']++;
	}

	for (int i = 0; i < n - 1; i++) {
		string st;
		cin >> st;
		solve(st);
	}
	cout << ans;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
}