#include <iostream>
#include <set>
using namespace std;

int n, m;
int k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	set <int> A;
	set <int> B;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> k;
		A.insert(k);
	}

	for (int i = 0; i < m; i++) {
		cin >> k;
		B.insert(k);
	}

	set <int>::iterator iter;

	int cnt = 0;
	int answer = 0;
	for (iter = A.begin(); iter != A.end(); iter++) {
		if (B.find(*iter) != B.end()) {
			cnt++;
		}
	}
	answer += B.size() - cnt;
	
	cnt = 0;
	for (iter = B.begin(); iter != B.end(); iter++) {
		if (A.find(*iter) != A.end()) {
			cnt++;
		}
	}

	answer += A.size() - cnt;

	cout << answer;
}