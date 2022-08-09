#include <iostream>
#include <cstring>
#include <string>
using namespace std;

bool isprime[1004000];
int n;

void eratos() {
	memset(isprime, true, sizeof(isprime));

	isprime[1] = false;

	for (int i = 2; i * i < 1004000; i++) {
		if (isprime[i] == false) {
			continue;
		}
		else {
			for (int j = i + i; j < 1004000; j += i) {
				isprime[j] = false;
			}
		}
	}
}

bool ispal(int n) {

	string st = to_string(n);

	string st2 = "";

	for (int i = st.size() - 1; i >= 0; i--) {
		st2.push_back(st[i]);
	}

	if (st == st2) {
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	eratos();

	cin >> n;

	for (int i = n;; i++) {
		if (isprime[i] == false) {
			continue;
		}
		else {
			if (ispal(i) == true) {
				cout << i;
				break;
			}
		}
	}
	

}