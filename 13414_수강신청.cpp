#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int k, l;
string input;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> k >> l;

	map <string,int> m;

	for (int i = 0; i < l; i++) {
		string st;
		cin >> st;

		m[st] = i + 1;
	}

	vector <pair<int, string>> v;

	for (auto i = m.begin(); i != m.end(); i++) {
		v.push_back({ i->second, i->first });
	}

	sort(v.begin(), v.end());

	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		cnt++;
		cout << v[i].second << "\n";
		if (cnt == k) {
			break;
		}
	}
	
}