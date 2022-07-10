#include <iostream>
#include <deque>

using namespace std;

int n, m;
int num;
int leftt, rightt;
int cnt = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	deque <int> dq;

	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}

	for (int i = 0; i < m; i++) {
		cin >> num;

		for (int j = 0; j < dq.size(); j++) {
			if (dq[j] == num) {
				leftt = j;
				rightt = dq.size() - j;
				break;
			}
		}

//		cout << "left: " << leftt << " " << "right: " << rightt << "\n";

		if (leftt <= rightt) {
			for (int i = 0; i < leftt; i++) {
				int k = dq.front();
				dq.push_back(k);
				dq.pop_front();
				cnt++;
			}
//			cout << "front(): " << dq.front() << "\n";
			dq.pop_front();
		}
		else {
			for (int i = 0; i < rightt; i++) {
				int k = dq.back();
				dq.push_front(k);
				dq.pop_back();
				cnt++;
			}
//			cout << "front(): " << dq.front() << "\n";
			dq.pop_front();
		}
	}

	cout << cnt << "\n";
}