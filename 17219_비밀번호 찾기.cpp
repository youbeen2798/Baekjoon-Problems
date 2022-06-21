#include <iostream>
#include <map>
using namespace std;

int n, m;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	map<string, string> mp;

	for (int i = 0; i < n; i++) {
		string web, password;
		cin >> web >> password;
		mp.insert({ web, password });
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		cout << mp[s] << "\n";
	}
}