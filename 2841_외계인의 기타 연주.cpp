#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n, p;

stack <int> s[7];
int a, b;
int cnt = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> p;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;

		while (!s[a].empty()) {
			if (s[a].top() > b) {
				cnt++;
				s[a].pop();
			}
			else {
				break;
			}
		}

		if (!s[a].empty()) {
			if (s[a].top() == b) {
				continue;
			}
		}

		s[a].push(b);
		cnt++;
	}
	cout << cnt;
}