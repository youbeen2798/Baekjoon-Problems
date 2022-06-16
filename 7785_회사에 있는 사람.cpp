#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	set <string> s;

	cin >> n;

	while (n--) {
		string name, work;
		cin >> name >> work;

		if (work == "enter") {
			s.insert(name);
		}
		if (work == "leave") {
			s.erase(name);
		}
	}

	for (auto iter = s.rbegin(); iter != s.rend(); iter++) {
		cout << *iter << "\n";
	}

}