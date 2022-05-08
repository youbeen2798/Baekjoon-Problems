#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int R, C;
	cin >> R >> C;
	bool protect = true; //양을 지킬수 있는지

	char** array = new char* [R];

	for (int i = 0; i < R; i++) {
		array[i] = new char[C];
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> array[i][j];
		}
	}

	// E W S N
	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (array[i][j] == 'W') {
				for (int k = 0; k < 4; k++) {
					int new_x = i + dx[k]; 
					int new_y = j + dy[k];

					if (-1 < new_x && new_x < R && -1 < new_y && new_y < C) {
						if (array[new_x][new_y] == 'S') { //늑대의 사방에 양이 있다면 0 출력
							protect = false;
						}
						else if (array[new_x][new_y] == '.') {
							array[new_x][new_y] = 'D';
						}
					}
				}

			}
		}
	}

	/*결과출력*/
	cout << (int)protect << "\n";

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << array[i][j];
		}
		cout << "\n";
	}
}
