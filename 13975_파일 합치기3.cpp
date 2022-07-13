#include <iostream>
#include <queue>
using namespace std;

int t;
int k;
int num;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	for (int test_case = 0; test_case < t; test_case++) {
		cin >> k;

		priority_queue<long long, vector <long long >, greater<long long >> pq;

		long long result = 0;
		for (int i = 0; i < k; i++) {
			cin >> num;
			pq.push(num);
		}

		while (pq.size() != 1) {
			long long fst = pq.top();
			pq.pop();

			long long second = pq.top();
			pq.pop();

			long long sum = fst + second;
			pq.push(sum);

			result += sum;
		}

		cout << result << "\n";
	}

}