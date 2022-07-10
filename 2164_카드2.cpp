#include <iostream>
#include <queue>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	queue <int> q;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (q.size()!=1) {
		q.pop();

		int k = q.front();
		q.push(k);
		q.pop();
	}

	cout << q.front();
}