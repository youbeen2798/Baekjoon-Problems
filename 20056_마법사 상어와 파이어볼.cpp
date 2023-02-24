#include <iostream>
#include <vector>
using namespace std;

int n, m, k;

struct fireball {
	int mi; //질량 
	int si; //속도
	int di; //방향
};

vector <fireball> map[51][51];
vector <fireball> copy_map[51][51];

int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = {  0, 1,1,1,0,-1,-1,-1 };

int arrange(int num) {
	if (1 <= num && num <= n) {
		return num;
	}
	else if (num > n) {
		if (num % n == 0) {
			return n;
		}
		return num % n;
	}
	else if(num <= 0){
		return n - (abs(num) % n);
	}
}
void move_fire_ball(int x, int y) {

	vector<fireball> fireballs = map[x][y];

	for (int i = 0; i < fireballs.size(); i++) {
		int mi = fireballs[i].mi; //질량
		int si = fireballs[i].si; //속력
		int di = fireballs[i].di; //방향

		int nx = x + dx[di] * si;
		int ny = y + dy[di] * si;

		nx = arrange(nx);
		ny = arrange(ny);

		copy_map[nx][ny].push_back({ mi, si, di });
	}

	map[x][y].clear();
}

void all_fire_ball_move() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j].size() > 0) {
				move_fire_ball(i, j);
			}
		}
	}
}

void over_two_fireball(int x, int y) {

	int sum_mi = 0; //합쳐진 질량
	int sum_si = 0; //합쳐진 속력
	bool all_even = true; //모두 짝수
	bool all_odd = true; //모두 홀수

	for (int i = 0; i < copy_map[x][y].size(); i++) {
		int mi = copy_map[x][y][i].mi;
		int si = copy_map[x][y][i].si;
		int di = copy_map[x][y][i].di;

		sum_si += si;
		sum_mi += mi;

		if (di % 2 == 0) { //짝수이면
			all_odd = false;
		}
		else {
			all_even = false;
		}	
	}

	int divided_mi = sum_mi / 5; //질량
	int divided_si = sum_si / copy_map[x][y].size(); //속력

	copy_map[x][y].clear();

	if (divided_mi == 0) {
		return;
	}

	if (all_even || all_odd) {
		for (int i = 0; i <= 3; i++) {
 			copy_map[x][y].push_back({ divided_mi, divided_si, i * 2});
		}
		return;
	}
	for (int i = 0; i <= 3; i++) {
		copy_map[x][y].push_back({ divided_mi, divided_si, i * 2 + 1 });
	}
}
void over_two_fireballs() {
	//2개 이상의 파이어볼이 있는 칸

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (copy_map[i][j].size() >= 2) {
				over_two_fireball(i, j);
			}
		}
	}
}

void copy_arr() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = copy_map[i][j];
			copy_map[i][j].clear();
		}
	}
}

void print() {

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j].size() > 0) {
				for (int k = 0; k < map[i][j].size(); k++) {
					ans += map[i][j][k].mi;
				}
			}
		}
	}
	cout << ans;
}
void solution() {
	for (int i = 0; i < k; i++) {
		all_fire_ball_move();	
		over_two_fireballs();
		copy_arr();
	}
	print();

}
void input() {
	
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		int ri, ci, mi, si, di;
		cin >> ri >> ci >> mi >> si >> di;
		map[ri][ci].push_back({ mi, si, di }); //질량, 속도, 방향
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();

	
}