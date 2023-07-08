#include <iostream>
#include <vector>

using namespace std;

int n; //행 개수
int m; //열 개수
int r; //라운드 횟수

struct info1 {
	int x;
	int y;
	char dir;
};

struct info2 {
	int x;
	int y;
};

vector<info1> offsets;
vector<info2> defends;

int map[101][101];
char result[101][101];

int max_x;//가장 길게 넘어지는 도미노 위치 행
int max_y; //가장 길게 넘어지는 도미노 위치 열
int cnt = 0;

bool inrange(int x, int y) {

	if (1 <= x && x <= n && 1 <= y && y <= m) {
		return true;
	}
	return false;

}
void print() {

//	cout << "#######" << "\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
}
void east_start(int x, int y) {

	cnt++;
	int num = map[x][y];
	result[x][y] = 'F'; //자기 자신을 넘어뜨린다.

	for (int j = y + 1; j < y + num; j++) {

		//cout << "x: " << x << " ny: " << j << "\n";

		if (inrange(x, j) && result[x][j] == 'S') { //아직 안 넘어져있다면
			result[x][j] = 'F'; //넘어뜨리고
			east_start(x, j); //다시 시작한다.
		}
	}
}

void west_start(int x, int y) {

	cnt++;

	int num = map[x][y];
	result[x][y] = 'F'; //자기 자신을 넘어뜨린다.

	for (int j = y - 1; j > y - num; j--) {

		if (inrange(x, j) && result[x][j] == 'S') { //아직 안 넘어져있다면
			result[x][j] = 'F'; //넘어뜨리고
			west_start(x, j); //다시 시작한다.
		}
	}
}

void south_start(int x, int y) {

	cnt++;

	int num = map[x][y];
	result[x][y] = 'F'; //자기 자신을 넘어뜨린다.

	for (int i = x + 1; i < x + num; i++) {

		if (inrange(i, y) && result[i][y] == 'S') { //아직 안 넘어져있다면
			result[i][y] = 'F'; //넘어뜨리고
			south_start(i, y); //다시 시작한다.
		}
	}
}
void north_start(int x, int y) {
	cnt++;

	int num = map[x][y];
	result[x][y] = 'F'; //자기 자신을 넘어뜨린다.

	for (int i = x - 1; i > x - num; i--) {

		if (inrange(i, y) && result[i][y] == 'S') { //아직 안 넘어져있다면
			result[i][y] = 'F'; //넘어뜨리고
			north_start(i, y); //다시 시작한다.
		}
	}
}
void one_offset(info1 in1) {
	//한번 공격한다.

	int x = in1.x;
	int y = in1.y;
	char dir = in1.dir;

	max_x = x;
	max_y = y;

	if (dir == 'E') {

		if (result[x][y] == 'S') {
			east_start(x, y);
		}
	}
	else if (dir == 'W') {
		if (result[x][y] == 'S') {
			west_start(x, y);
		}
	}
	else if (dir == 'S') {
		if (result[x][y] == 'S') {
			south_start(x, y);
		}
	}
	else {
		if (result[x][y] == 'S') {
			north_start(x, y);
		}
	}
}

void one_defend(info2 in2) {
	//한번 수비한다.

	int x = in2.x;
	int y = in2.y;

	result[x][y] = 'S';
}

void solution() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			result[i][j] = 'S';
		}
	}

	for (int i = 0; i < r; i++) {
		int x, y;
		char dir;
		info1 in1 = offsets[i];
		info2 in2 = defends[i];
		one_offset(in1);
		one_defend(in2);
	}

	cout <<  cnt << "\n";
	print();

}

void input() {

	cin >> n >> m >> r; 

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < r; i++) {
		int x, y;
		char dir;
		cin >> x >> y >> dir;
		offsets.push_back({ x, y, dir });
		cin >> x >> y;
		defends.push_back({ x,y });
	}
	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}