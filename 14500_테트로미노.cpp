#include <iostream>

using namespace std;

int n, m;
int arr[501][501];
int real_ans = 0;

pair<int, int> dxdy[17][4] = {
	{{0,0}, {0,1}, {0,2}, {0,3}},
	{{0,0}, {1,0}, {2,0}, {3,0}},
	{{0,0}, {1,0}, {0,1}, {1,1}},
	{{0,0}, {1,0}, {2,0}, {2,1}},
	{{0,0}, {0,1}, {0,2}, {-1,2}},
	{{0,0}, {1,0}, {1,1}, {1,2}},
	{{0,0}, {0,1}, {-1,1}, {-2,1}},
	{{0,0}, {0,1}, {0,2}, {1,0}},
	{{0,0}, {0,1}, {0,2}, {1,2}},
	{{0,0}, {1,0}, {1,1}, {2,1}},
	{{0,0}, {1,0}, {0,1}, {-1,1}},
	{{0,0}, {0,1}, {-1,1}, {-1,2}},
	{{0,0}, {0,1}, {1,1}, {1,2}},
	{{0,0}, {1,0}, {1,1}, {2,0}},
	{{0,0}, {0,1}, {0,2}, {1,1}},
	{{0,0}, {0,1}, {-1,1}, {1,1}},
	{{0,0}, {0,1}, {-1,1}, {0,2}}
};

int mini_solution(int x, int y) {

	int tmp_ans = 0;

	for (int i = 0; i < 17; i++) {
		bool possible = true;
		int mini_tmp_ans = 0;

		for (int j = 0; j < 4; j++) {

			int nx = x + dxdy[i][j].first;
			int ny = y + dxdy[i][j].second;

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				mini_tmp_ans += arr[nx][ny];
			}
			else {
				possible = false;
			}
		}
		if (possible) {
			tmp_ans = max(tmp_ans, mini_tmp_ans);
		}
	}

	return tmp_ans;
}
void solution() {

	//mini_solution(0, 4);

	 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			real_ans = max(real_ans, mini_solution(i, j));
		}
	}
	cout << real_ans;
	
}

void input() {
	cin >> n >> m; //세로 크기와 가로 크기

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
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