#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;

bool change = true;

long long k;
long long hi;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	priority_queue<long long, vector<long long>, greater<long long>> pq;

	if (n == 1) {
		cin >> k;
		cout << k;
		exit(0);
	}

	for (int i = 0; i < n; i++) {
		cin >> k;
		pq.push(k);
	}

	hi = n * (n - 1);

	int cnt = 0;

	for (int i = 0; i < hi; i++) {
		cin >> k;
		if (k > pq.top()) {
			pq.pop();
			pq.push(k);
			cnt = 0;
		}
		else {
			cnt++;
		}
	}
	cout << pq.top();

}