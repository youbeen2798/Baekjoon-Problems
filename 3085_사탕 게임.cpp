#include <iostream>
#include <vector>

using namespace std;

int n;
char arr[51][51];
char arr2[51][51];

vector <int> v;
int cnt = 0;
int mx_cnt = 0;
int final_cnt = 0;

void reset() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = arr2[i][j];
		}
	}
}

void garo() {
	mx_cnt = 0;
	cnt = 1;

	for (int i = 0; i < n; i++) {
		cnt = 1;
		for (int j = 0; j < n - 1; j++) {
			if (arr[i][j] == arr[i][j + 1]) {
				cnt++;
				if (mx_cnt <= cnt) {
					mx_cnt = cnt;
				}
			}
			else {
				cnt = 1;
			}
		}
	}
//	cout << "가로 cnt: " << mx_cnt;
}

void sero() {
	mx_cnt = 0;
	cnt = 1;

	for (int j = 0; j < n; j++) {
		cnt = 1;
		for (int i = 0; i < n - 1; i++) {
			if (arr[i][j] == arr[i + 1][j]) {
				cnt++;
				if (mx_cnt <= cnt) {
					mx_cnt = cnt;
				}
			}
			else {
				cnt = 1;
			}
		}
	}
//	cout << "세로 cnt: " << mx_cnt << "\n";

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr2[i][j] = arr[i][j];
		}
	}

	int final_cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			swap(arr[i][j], arr[i][j + 1]);
	
			/*
			for (int k = 0; k < n; k++) {
				for (int p = 0; p < n; p++) {
					cout << arr[k][p];
				}
				cout << "\n";
			}
			*/
			
			garo();
			if (final_cnt <= mx_cnt) {
				final_cnt = mx_cnt;
			}
			sero();
			if (final_cnt <= mx_cnt) {
				final_cnt = mx_cnt;
			}
			reset();
		}
	}

	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n - 1; i++) {
			swap(arr[i][j], arr[i+1][j]);

			/*
			for (int k = 0; k < n; k++) {
				for (int p = 0; p < n; p++) {
					cout << arr[k][p];
				}
				cout << "\n";
			}
			*/

			garo();
			if (final_cnt <= mx_cnt) {
				final_cnt = mx_cnt;
			}
			sero();
			if (final_cnt <= mx_cnt) {
				final_cnt = mx_cnt;
			}
			reset();
		}
	}
	cout << final_cnt;
}