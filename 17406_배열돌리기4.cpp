#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; //행 크기
int m; //열 크기
int k; //회전 연산 개수 

int input_map[51][51];
int map[51][51];
int ans = 99999999;


struct info {
	int r;
	int c;
	int s; 
};

vector<info> v;

void copy() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			map[i][j] = input_map[i][j];
		}
	}
}

void rotate(info in) {
	int r = in.r;
	int c = in.c;
	int s = in.s;

	int start_x = r - s;
	int start_y = c - s;
	int end_x = r + s;
	int end_y = c + s;

	while (true) {

		if (end_x <= start_x) {
			break;
		}

		int tmp = map[start_x][end_y];

		//위
		for (int j = end_y; j > start_y; j--) {
			map[start_x][j] = map[start_x][j - 1];
		}

		//왼쪽
		for (int i = start_x; i < end_x; i++) {
			map[i][start_y] = map[i + 1][start_y];
		}

		//아래
		for (int j = start_y; j < end_y; j++) {
			map[end_x][j] = map[end_x][j + 1];
		}
		
		//오른쪽
		for (int i = end_x; i > start_x; i--) {
			map[i][end_y] = map[i - 1][end_y];
		}

		map[start_x + 1][end_y] = tmp;
		
		start_x += 1;
		start_y += 1;
		end_x -= 1;
		end_y -= 1;
	
		//print();
	}
}

void output() {


	for (int i = 1; i <= n; i++) {
		int tmp_sum = 0;
		for (int j = 1; j <= m; j++) {
			tmp_sum += map[i][j];
		}
		ans = min(ans, tmp_sum);
	}
}
void solution() {	

	vector<int> per;

	for (int i = 0; i < k; i++) {
		per.push_back(i);
	}

	do{
		copy();
		for (int i = 0; i < k; i++) {
			info in = v[per[i]];
			rotate(in);
		}
		output();
	} while (next_permutation(per.begin(), per.end()));
}

void input() {

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> input_map[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		v.push_back({ r,c,s });
	}

}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
	cout << ans;
}