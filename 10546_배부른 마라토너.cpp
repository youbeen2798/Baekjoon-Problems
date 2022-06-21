#include <iostream>
#include <set>
using namespace std;

int n;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	multiset <string> s;

	for (int i = 0; i < n; i++) {
		string st;
		cin >> st;
		s.insert(st);
	}

	for (int i = 0; i < n - 1; i++) {
		string st;
		cin >> st;
		s.erase(s.find(st));
		cout << "s.size(): " << s.size() << "\n";
	}

	for (auto item : s) {
		cout << item;
	}
}