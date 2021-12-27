#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL); //cin과 cout의 묶음 해제
	ios_base::sync_with_stdio(false);

	int a, b, c;
	cin >> a;

	for (int i = 0; i < a; i++) {
		cin >> b >> c ;
		cout << b + c << "\n";
	}
	return 0;
}