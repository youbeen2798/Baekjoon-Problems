#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;

int n;

bool isprime[500040];

void eratos() {

	memset(isprime, true, sizeof(isprime));
	isprime[1] = false;
	for (int i = 2; i < 500040; i++) {
		if (isprime[i] == false) {
			continue;
		}
		else {
			for (int j = i + i; j < 500040; j += i) {
				isprime[j] = false;
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	long long answerA = 0;

	//제약조건 A
	for (int i = 3; i <= n; i++) {
		if (i % 2 == 0) {
			answerA += i / 2 - 1;
		}
		else {
			answerA += i / 2;
		}
	}
	cout << answerA << "\n";

	//제약조건 B
	long long answerB = 0;
	vector <int> v;
	set <int> s;

	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			v.push_back(i);
			v.push_back(n / i);
			s.insert(i);
			s.insert(n / i);
		}
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	eratos();

	for (int i = 0; i < v.size(); i++) {
		for (int j = i; j < v.size(); j++) {
			int sum = v[i] + v[j];
			if (s.find(sum) != s.end()) {
				answerB++;
			}
		}
	}

	cout << answerB << "\n";

	//제약조건C
	vector <int> v2;
	long long answerC = 0;

	for (int i = 2; i <= n; i++) {
		if (isprime[i]) {
			v2.push_back(i); // 2 3 5 7 11 13
		}
	}


	for (int i = 0; i < v2.size(); i++) {
		for (int j = i; j < v2.size(); j++) {
			int sum = v2[i] + v2[j];
			if (sum <= n && isprime[sum]) {
				answerC++;
			}
		}
	}

	cout << answerC << "\n";


}