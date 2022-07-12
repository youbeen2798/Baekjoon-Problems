#include <iostream>
#include <map>
#include <string>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	map <string, int> m;

	string st;

	int cnt = 0;

	while (getline(cin, st)) {
		cnt++;

		if (m.find(st) != m.end()) {
			m[st]++;
		}
		else {
			m.insert({ st,1 });
		}
	}

	cout << fixed;
	cout.precision(4);

	for (auto it = m.begin(); it != m.end(); it++) {
		float c = (float)it->second / (float)cnt * (float)100;

		cout << it->first << " " << c << "\n";
	}

}