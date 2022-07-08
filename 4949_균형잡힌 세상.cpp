#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s2;
	stack <char> s;


	while (1) {
		bool hello = false;
		getline(cin, s2);
		if (s2 == ".") {
			return 0;
			break;
		}
		else {
			for (int i = 0; i < s2.size(); i++) {
				if (s2[i] == '(' || s2[i] == '[') {
					s.push(s2[i]);
				}
				else if (s2[i] == ')') {
					if (s.empty()) {
						cout << "no" << "\n";
						while (!s.empty()) {
							s.pop();
						}
						hello = true;
						break;
					}
					else {
						if (s.top() == '(') {
							s.pop();
							continue;
						}
						else {
							cout << "no" << "\n";
							while (!s.empty()) {
								s.pop();
							}
							hello = true;
							break;
						}
					}
				}
				else if (s2[i] == ']') {
					if (s.empty()) {
						cout << "no" << "\n";
						while (!s.empty()) {
							s.pop();
						}
						hello = true;
						break;
					}
					else {
						if (s.top() == '[') {
							s.pop();
							continue;
						}
						else {
							cout << "no" << "\n";
							while (!s.empty()) {
								s.pop();
							}
							hello = true;
							break;
						}
					}
				}
			}
			if (hello) {
				continue;
			}
			if (s.size() == 0) {
				cout << "yes" << "\n";				
			}
			else {
				cout << "no" << "\n";
				while (!s.empty()) {
					s.pop();
				}
			}
		}

	}
}