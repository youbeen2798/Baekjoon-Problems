#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	if (N % 2 == 0) { //�Է°��� ¦���̸�
		cout << "CY";
	}
	else {
		cout << "SK"; //�Է°��� Ȧ���̸�
	}
	return 0;

}