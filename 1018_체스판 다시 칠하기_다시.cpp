#include <iostream>
#include <string>
using namespace std;

int m, n;
int d = 0;
int k = 0;
int cnt = 64;
int mins;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	int count_1 = 0;
	int count_2 = 0;

	char test1_arr[8][8] = { {'B','W','B','W','B','W','B','W'},
							{'W','B','W','B','W','B','W','B'},
							{'B','W','B','W','B','W','B','W'},
							{'W','B','W','B','W','B','W','B'},
							{'B','W','B','W','B','W','B','W'},
							{'W','B','W','B','W','B','W','B'},
							{'B','W','B','W','B','W','B','W'},
							{'W','B','W','B','W','B','W','B'} };

	char test2_arr[8][8] = { {'W','B','W','B','W','B','W','B'},
							{'B','W','B','W','B','W','B','W'},
							{'W','B','W','B','W','B','W','B'},
							{'B','W','B','W','B','W','B','W'},
							{'W','B','W','B','W','B','W','B'},
							{'B','W','B','W','B','W','B','W'},
							{'W','B','W','B','W','B','W','B'},
							{'B','W','B','W','B','W','B','W'} };


	char** test = new char* [n];

	for (int j = 0; j < n; j++) {
		test[j] = new char[m];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> test[i][j];
		}
	}

	while (k <= n-8) { 
		d = 0;
		while (d <= m-8) {
			count_1 = 0;
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if (test[i + k][j + d] != test1_arr[i][j]) { //
						count_1++;
					}
				}
			}

			count_2 = 64 - count_1;

			if (count_1 < count_2) {
				mins = count_1;
			}
			else {
				mins = count_2;
			}

			if (mins < cnt)
				cnt = mins;


			d++; 
		}
		k++;
	}

	cout << cnt;

}