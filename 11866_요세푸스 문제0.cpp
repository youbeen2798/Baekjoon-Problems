#include <iostream>
#include <queue>
using namespace std;

int k, n;
int num;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	queue <int> q;

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	cout << "<";
	while (!q.empty()) {
		for (int i = 0; i < k - 1; i++) {
			num = q.front();
			q.pop();
			q.push(num);
	//		cout << "뒤로 보내기: " << num << "\n";
		}

	//	cout << "삭제: " << q.front() << "\n";
		if (q.size() == 1) {
			cout << q.front() << ">";
		}
		else {
			cout << q.front() << "," << " ";
		}
		q.pop();
	}
}