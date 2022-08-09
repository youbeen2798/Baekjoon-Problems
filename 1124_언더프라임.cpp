#include <iostream>
#include <cstring>
using namespace std;

bool isprime[100001];

void eratos() {

	memset(isprime, true, sizeof(isprime));

	isprime[1] = false;
	for (int i = 2; i <= 100000; i++) {
		if (isprime[i] == false) {
			continue;
		}
		else {
			for (int j = i + i; j <= 100000; j += i) {
				isprime[j] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n1, n2;
	cin >> n1 >> n2;
	int answer = 0;

	eratos();
	
	for (int num = n1; num <= n2; num++) {
		int n = num;
		int cnt = 0;

		if (isprime[n]) {
			continue;
		}
		for (int i = 2; i <= n; i++) {
			while (n % i == 0) {
				n /= i;
				cnt++;
//				cout << i << "* ";
			}
		}
		
		if (isprime[cnt]) {
			answer++;
		}
//		cout << "\n";
	}

//	cout << "****" << "\n";
	cout << answer;

}