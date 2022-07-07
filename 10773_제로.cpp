#include <iostream>
#include <stack>
using namespace std;

int k;
int num;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> k;

	stack <int> s;

	for (int i = 0; i < k; i++) {
		cin >> num;
		if (num) {
			s.push(num);
		}
		else {
			s.pop();
		}
	}

	int sum = 0;
	while (!s.empty()) {
		sum += s.top();
//		cout << s.top() << " ";
		s.pop();
	}

	cout << sum;
}