#include <iostream>

using namespace std;

int n;
int l;
int arr[101][101];
int row_arr[101];
int col_arr[101];
bool row_saro_exists[101][101];
bool col_saro_exists[101][101];

void not_need_gyoungsaro_row() {
	//���϶�
	//���ΰ� �ʿ����� ���� ��

	for (int i = 0; i < n; i++) {
		bool can_walk = true;
		for (int j = 0; j < n - 1; j++) {
			if (arr[i][j] != arr[i][j + 1]) {
				can_walk = false;
				break;
			}
		}
		if (can_walk) {
			row_arr[i] = true;
		}
	}
}

void not_need_gyoungsaro_col() {
	//���϶�
	//���ΰ� �ʿ����� ���� ��

	for (int j = 0; j < n; j++) {
		bool can_walk = true; 
		for (int i = 0; i < n - 1; i++) {
			if (arr[i][j] != arr[i + 1][j]) {
				can_walk = false;
				break;
			}
		}
		if (can_walk) {
			col_arr[j] = true;
		}
	}
}
void not_need_gyoungsaro() {

	not_need_gyoungsaro_row();
	not_need_gyoungsaro_col();
}

void need_gyoungsaro_row() {
	//���϶�
	//���ΰ� �ʿ��� ��

	//���ʿ��� ����������
	for (int i = 0; i < n; i++) {
		bool can_walk = true;
		for (int j = 0; j < n - 1; j++) {
			//�ö󰡸�
			if (arr[i][j] + 1 == arr[i][j + 1]) {
				for (int k = j - l + 1; k <= j; k++) {
					if (0 <= k && k < n && arr[i][j] == arr[i][k] && !col_saro_exists[i][k]) {
						col_saro_exists[i][k] = true;
						continue;
					}
					can_walk = false;
					break;
				}
			}
			//��������
			else if (arr[i][j] - 1 == arr[i][j + 1]) {
				for (int k = j + 1; k <= j + l; k++) {
					if (0 <= k && k < n && arr[i][j + 1] == arr[i][k] && !col_saro_exists[i][k]) {
						col_saro_exists[i][k] = true;
						continue;
					}
					can_walk = false;
					break;
				}
			}
			//���̰� 1�̻� ���� ����
			else if (abs(arr[i][j] - arr[i][j + 1]) > 1) {
				can_walk = false;
				break;
			}

			if (!can_walk) {
				break;
			}
		}
		if (can_walk) {
			row_arr[i] = true;
		}
	}
}

void need_gyoungsaro_col() {
	//���϶�
	//���ΰ� �ʿ��� ��

	for (int j = 0; j < n; j++) {
		bool can_walk = true;
		for (int i = 0; i < n - 1; i++) {
			//�ö󰡸�
			if (arr[i][j] + 1 == arr[i + 1][j]) {
				for (int k = i - l + 1; k <= i; k++) {
					if (0 <= k && k < n && arr[i][j] == arr[k][j] && !row_saro_exists[k][j]) {
						row_saro_exists[k][j] = true;
						continue;
					}
					can_walk = false;
					break;
				}
			}
			//��������
			else if (arr[i][j] - 1 == arr[i + 1][j]) {
				for (int k = i + 1; k <= i + l; k++) {
					if (0 <= k && k < n && arr[i + 1][j] == arr[k][j] && !row_saro_exists[k][j] == true) {
						row_saro_exists[k][j] = true;
						continue;
					}
					can_walk = false;
					break;
				}
			}
			//���̰� 1�̻� ���� ����
			else if (abs(arr[i][j] - arr[i + 1][j]) > 1) {
				can_walk = false;
				break;
			}

			if (!can_walk) {
				break;
			}
		}
		if (can_walk) {
			col_arr[j] = true;
		}
	}
}
void need_gyoungsaro() {
	need_gyoungsaro_row();
	need_gyoungsaro_col();
}

void print() {

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += row_arr[i];
		ans += col_arr[i];
	}

	for (int i = 0; i < n; i++) {
	}

	cout << ans;
}
void solution() {

	not_need_gyoungsaro();
	need_gyoungsaro();
	print();
}
void input() {

	cin >> n >> l; 

	for(int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}