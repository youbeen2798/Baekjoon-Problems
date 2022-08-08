#include <iostream>
#include <string>

using namespace std;

long long l, r;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> l >> r;

	string sl = to_string(l);
	string sr = to_string(r);

	int answer = 0;

	if (sl.size() == sr.size()) {
		int size = sl.size();  //3
		for (int i = 0; i < size; i++) {
			int num1 = sl[i] - '0'; 
			int num2 = sr[i] - '0';

			if (num1 == num2 && num1 != 8) {
				continue;
			}
			if (num1 == num2 && num1 == 8) {
				answer++;
			}
			else {
				break;
			}
		}
	}
	else {
		answer = 0;
	}

	cout << answer;
}