#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s1, s2;
int ans = 0;
int main() {	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	getline(cin, s1);
	getline(cin, s2);

	for (int i = 0; i < s1.size(); i++) {
		bool correct = true;
		for (int j = i; j < s2.size() + i; j++) {
			if (s1[j] != s2[j - i]) {
				correct = false;
				break;
			}
		}
		if (correct) {
			cout << "i: " << i << "\n";
			ans++;
			if (i + s2.size() - 1 >= s1.size()) {
				cout << "break" << "\n";
				break;
			}
			else {
				i += s2.size() - 1;
			}
		}
	}

	cout << ans;

}