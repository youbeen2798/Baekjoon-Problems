#include <iostream>

using namespace std;

int n,k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k; // 13 2

	int answer = 0;

	while (1){

		int cnt = 0;
		int temp = n; // 13

		while (temp > 0) {
			if (temp % 2 == 0) {
				temp /= 2;
			}
			else {
				temp /= 2; //1 0
				cnt++; // 1 2
			}
		}

		if (cnt <= k) {
			break;
		}
		else {
			n++;
			answer++;
			continue;
		}
	}

	cout << answer;

	

}