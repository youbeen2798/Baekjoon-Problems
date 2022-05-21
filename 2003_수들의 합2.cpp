#include <iostream>
using namespace std;

int n, m;
int input[10001];
int ptrA = 0;
int ptrB = 0;
long long sum = 0;
long long answer = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> input[i];
	}

	while (ptrA <= ptrB && ptrB <= n + 1) {
		if (sum == m) {
			answer++;

			sum += input[ptrB];
			ptrB++;
		}
		else if (sum < m) {
			sum += input[ptrB];
			ptrB++;
		}
		else if (sum > m) {
			sum -= input[ptrA];
			ptrA++;

			if (ptrA > ptrB) {
				ptrB = ptrA;
				sum = input[ptrA];
			}
		}
	}
	cout << answer;

}