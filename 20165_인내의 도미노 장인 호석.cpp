#include <iostream>
#include <vector>

using namespace std;

int n; //�� ����
int m; //�� ����
int r; //���� Ƚ��

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

int max_x;//���� ��� �Ѿ����� ���̳� ��ġ ��
int max_y; //���� ��� �Ѿ����� ���̳� ��ġ ��
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
	result[x][y] = 'F'; //�ڱ� �ڽ��� �Ѿ�߸���.

	for (int j = y + 1; j < y + num; j++) {

		//cout << "x: " << x << " ny: " << j << "\n";

		if (inrange(x, j) && result[x][j] == 'S') { //���� �� �Ѿ����ִٸ�
			result[x][j] = 'F'; //�Ѿ�߸���
			east_start(x, j); //�ٽ� �����Ѵ�.
		}
	}
}

void west_start(int x, int y) {

	cnt++;

	int num = map[x][y];
	result[x][y] = 'F'; //�ڱ� �ڽ��� �Ѿ�߸���.

	for (int j = y - 1; j > y - num; j--) {

		if (inrange(x, j) && result[x][j] == 'S') { //���� �� �Ѿ����ִٸ�
			result[x][j] = 'F'; //�Ѿ�߸���
			west_start(x, j); //�ٽ� �����Ѵ�.
		}
	}
}

void south_start(int x, int y) {

	cnt++;

	int num = map[x][y];
	result[x][y] = 'F'; //�ڱ� �ڽ��� �Ѿ�߸���.

	for (int i = x + 1; i < x + num; i++) {

		if (inrange(i, y) && result[i][y] == 'S') { //���� �� �Ѿ����ִٸ�
			result[i][y] = 'F'; //�Ѿ�߸���
			south_start(i, y); //�ٽ� �����Ѵ�.
		}
	}
}
void north_start(int x, int y) {
	cnt++;

	int num = map[x][y];
	result[x][y] = 'F'; //�ڱ� �ڽ��� �Ѿ�߸���.

	for (int i = x - 1; i > x - num; i--) {

		if (inrange(i, y) && result[i][y] == 'S') { //���� �� �Ѿ����ִٸ�
			result[i][y] = 'F'; //�Ѿ�߸���
			north_start(i, y); //�ٽ� �����Ѵ�.
		}
	}
}
void one_offset(info1 in1) {
	//�ѹ� �����Ѵ�.

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
	//�ѹ� �����Ѵ�.

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