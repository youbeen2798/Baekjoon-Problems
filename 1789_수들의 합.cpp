#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0); //����� ������
	cin.tie(0);
	cout.tie(0);

	long long S;
	cin >> S;

	long long sum = 0;
	int num = 1;
	int cnt = 0;
	while (1) {
		sum += num;
		cnt++; 
		if (sum > S) {
			cnt--;
			break;
		}
		num++; 
	}

	cout << cnt;
}