#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int m;
int arr[50][50];
int shark_x; //상어 행
int shark_y; //상어 열

vector<int> gusuls;
int ans[4];

void bumb(int di, int si) {
	//방향과 거리
	if (di == 1) { //위
		for (int i = 1; i <= si; i++) {
			arr[shark_x - i][shark_y] = 0;
		}
	}
	else if (di == 2) { //아래
		for (int i = 1; i <= si; i++) {
			arr[shark_x + i][shark_y] = 0;
		}
	}
	else if (di == 3) { //왼쪽
		for (int i = 1; i <= si; i++) {
			arr[shark_x][shark_y - i] = 0;
		}
	}
	else { //오른쪽
		for (int i = 1; i <= si; i++) {
			arr[shark_x][shark_y + i] = 0;
		}
	}
}


vector<int> get_gusuls() {

	vector<int> tmp_gusuls;
	int x = shark_x;
	int y = shark_y;

	for (int i = 1; i <= n - 2; i += 2) {
		//왼쪽
		for (int j = 1; j <= i; j++) {
			y--;

			if (arr[x][y] != 0) {
				tmp_gusuls.push_back(arr[x][y]);
			}
		}
		//아래쪽
		for (int j = 1; j <= i; j++) {
			x++;
			if (arr[x][y] != 0) {
				tmp_gusuls.push_back(arr[x][y]);
			}
		}
		//오른쪽
		for (int j = 1; j <= i + 1; j++) {
			y++;
			if (arr[x][y] != 0) {
				tmp_gusuls.push_back(arr[x][y]);
			}
		}
		//위쪽
		for (int j = 1; j <= i + 1; j++) {
			x--;
			if (arr[x][y] != 0) {
				tmp_gusuls.push_back(arr[x][y]);
			}
		}
	}

	for (int i = 1; i <= n - 1; i++) {
		y--;
		if (arr[x][y] != 0) {
			tmp_gusuls.push_back(arr[x][y]);
		}
	}

	return tmp_gusuls;
}

void real_arrange(vector<int> gusuls) {
	//구슬을 다시 배열에 저장

	memset(arr, 0, sizeof(arr));
	int x = shark_x;
	int y = shark_y;
	int idx = 0;

	int diff = gusuls.size() - n * n - 1;

	for (int i = 0; i < diff; i++) {
		gusuls.pop_back();
	}


	while (true) {
		for (int i = 1; i <= n - 2; i += 2) {
			//왼쪽
			for (int j = 1; j <= i; j++) {
				y--;
				if (idx >= gusuls.size()) {
					return;
				}
				arr[x][y] = gusuls[idx++];
			}
			//아래쪽
			for (int j = 1; j <= i; j++) {
				x++;
				if (idx >= gusuls.size()) {
					return;
				}
				arr[x][y] = gusuls[idx++];
			}
			//오른쪽
			for (int j = 1; j <= i + 1; j++) {
				y++;
				if (idx >= gusuls.size()) {
					return;
				}
				arr[x][y] = gusuls[idx++];
			}
			//위쪽
			for (int j = 1; j <= i + 1; j++) {
				x--;
				if (idx >= gusuls.size()) {
					return;
				}
				arr[x][y] = gusuls[idx++];
			}
		}

		for (int i = 1; i <= n - 1; i++) {
			y--;
			if (idx >= gusuls.size()) {
				return;
			}
			arr[x][y] = gusuls[idx++];
		}
	}
}
void arrange() {

	vector<int> tmp_gusuls = get_gusuls();
	real_arrange(tmp_gusuls);
}


bool over_four_bumb() {
	//폭발하는 구슬은 4개 이상 연속하는 구슬이 있을 때

	bool bumb_possible = false; //폭발할게 있는지 확인

	//폭발하기 전 구슬
	vector<int> before_bumb_gusuls = get_gusuls();

	//폭발 후 구슬
	vector<int> after_bumb_gusuls;

	for (int i = 0; i < before_bumb_gusuls.size(); i++) {
		int num = before_bumb_gusuls[i];
		vector<int> tmp;
		tmp.push_back(num);
		int same_num_cnt = 1;

		for (int j = i + 1; j < before_bumb_gusuls.size(); j++) {
			if (before_bumb_gusuls[j] == num) {
				same_num_cnt++;
				tmp.push_back(num);
				continue;
			}
			break;
		}

		//4개 이상 연속하는 구슬이 있을 때 
		if (same_num_cnt >= 4 && num != 0) {
			i += same_num_cnt - 1;
			ans[num] += same_num_cnt;
			bumb_possible = true; //폭발 할게 있음
			continue;
		}

		//4개 이상 연속하는 구슬이 없을 때 
		i += same_num_cnt - 1;
		for (int j = 0; j < tmp.size(); j++) {
			after_bumb_gusuls.push_back(tmp[j]);
		}
	}

	if (bumb_possible) {

		real_arrange(after_bumb_gusuls);

		return true;
	}
	return false;
}

void gusul_num_change() {

	//폭발하기 전 구슬
	vector<int> before_bumb_gusuls = get_gusuls();
	
	//폭발 후 구슬
	vector<int> after_bumb_gusuls;

	for (int i = 0; i < before_bumb_gusuls.size(); i++) {
		int num = before_bumb_gusuls[i];
		vector<int> tmp;
		tmp.push_back(num);
		int same_num_cnt = 1;

		for (int j = i + 1; j < before_bumb_gusuls.size(); j++) {
			if (before_bumb_gusuls[j] == num) {
				same_num_cnt++;
				tmp.push_back(num);
				continue;
			}
			break;
		}

		i += same_num_cnt - 1;
		if (num == 0) {
			break;
		}
		after_bumb_gusuls.push_back(same_num_cnt);
		after_bumb_gusuls.push_back(num);
	}


	real_arrange(after_bumb_gusuls);
}

void get_ans() {

	int real_ans = 0;

	for (int i = 1; i <= 3; i++) {
		real_ans += ans[i] * i;
	}

	cout << real_ans;
	exit(0);
}

void solution(int di, int si) {
	//방향과 거리
	
	bumb(di, si); //구슬 폭파
	arrange();

	while(true) {
		if (!over_four_bumb()) {
			break;
		}
	}

	gusul_num_change();
	
}




void input() {
	cin >> n >> m;

	shark_x = (n + 1) / 2;
	shark_y = (n + 1) / 2;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int di, si; //방향과 거리
		cin >> di >> si;
		solution(di, si);
	}

	get_ans();
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
}