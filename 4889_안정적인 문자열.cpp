#include <iostream>
#include <stack>
#include <string>

using namespace std;

string st;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int cnt = 0;
	int test_case = 1;

	while (getline(cin, st)) {
		//	int T;
		//	cin >> T;

		//	for (int test_case = 0; test_case < T; test_case++) {
		//		cin >> st;
		stack <char> s;

		int cnt2 = 0;
		bool hi = false;
		for (int i = 0; i < st.size(); i++) {
			if (st[i] == '-') {
				hi = true;
				break;
				//				exit(0);
			}
		}
		if (hi) {
			break;
		}

		cout << test_case << "." << " ";

		for (int i = 0; i < st.size(); i++) {
			if (st[i] == '{') {
				s.push('{');
			}
			else if (st[i] == '}') {
				if (s.empty() || s.top() == '}') {
					s.push('}');
				}
				else if (s.top() == '{') {
					s.pop();
				}
			}
		}

		cnt = 0;



		int k = s.size();
		for (int i = 0; i < k; i++) {

			if (i % 2 == 0) {
				if (s.top() == '{') {
					cnt++;
				}
				s.pop();
			}
			else {
				if (s.top() == '}') {
					cnt++;
				}
				s.pop();
			}
		}

		cout << cnt << "\n";
		test_case++;
	}
}