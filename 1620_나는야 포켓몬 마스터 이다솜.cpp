#include <iostream>
#include <map>
#include <string>
using namespace std;

int n, m, k;
string st;
string name[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	map<string, int> m;

	for (int i = 1; i <= n; i++) {
		cin >> st;
		m.insert({ st,i });
		name[i] = st;
	}

	map<string, int>::iterator iter;

	for (int i = 0; i < k; i++) {
		string st;

		cin >> st;

		if (isdigit(st[0])) {
			int hi = stoi(st);

			cout << name[hi] << "\n";
		}

		else {
			cout << m[st] << "\n";
		}
	}
}