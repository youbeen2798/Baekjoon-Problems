#include <iostream>

using namespace std;

int n;
int m;
int k;

//����
//1: ��, 2 : �Ʒ�, 3 : ����, 4: ������

int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,-1,1 };

struct shark {
	int x;
	int y;
	int dir;
	int dirmap[5][5];
	bool die;
};

int map[21][21];

//������ �Ѹ� ��� ��ȣ, ���� �ð�
pair<int,int> smell[21][21];

shark sharks[401];

void spread_smell() {
	//�� ó������ ��� �� �ڽ��� ��ġ�� �ڽ��� ������ �Ѹ���.
	
	for (int i = 1; i <= m; i++) {
		if (!sharks[i].die) {
			smell[sharks[i].x][sharks[i].y] = { i, k };
		}
	}
}

void one_shark_move(int shark_num) {
	//shark_num �� �̵��Ѵ�.

	//������� ����.
	
	//���� ��� ����
	int now_shark_dir = sharks[shark_num].dir;
	int now_shark_x = sharks[shark_num].x; //���� ��� ��
	int now_shark_y = sharks[shark_num].y; //���� ��� ��

	int next_shark_x = -1; //�̵��� ��� ��
	int next_shark_y = -1; //�̵��� ��� ��
	int next_shark_dir = -1; //�̵��� ��� ����


	//1.���� ���� ������ ���� ĭ���� �̵��Ѵ�. 
	for (int i = 1; i <= 4; i++) {

		//�̵��Ϸ��� ����
		int dir = sharks[shark_num].dirmap[now_shark_dir][i];
		int nx = now_shark_x + dx[dir];
		int ny = now_shark_y + dy[dir];

		//������ ���� �ش� �ڸ��� ���������
		if (1 <= nx && nx <= n && 1 <= ny && ny <= n && smell[nx][ny].first == 0) {
			
			if (map[nx][ny] != 0) {
				sharks[shark_num].die = true; //�� �״´�.
				map[now_shark_x][now_shark_y] = 0; //�� �ִ� �ڸ��� ��������.
				return;
			}
			next_shark_x = nx;
			next_shark_y = ny;
			next_shark_dir = dir;
			break;
		}
	}


	if (next_shark_x != -1) {
		//�̵��� �� �ִٸ�
		sharks[shark_num].x = next_shark_x;
		sharks[shark_num].y = next_shark_y;
		sharks[shark_num].dir = next_shark_dir;
		
		//�� �� map ����
		map[now_shark_x][now_shark_y] = 0;
		map[next_shark_x][next_shark_y] = shark_num;
		return;
	}

	//2. �ڽ��� ������ �ִ� ĭ�� �������� �̵��Ѵ�.
	for (int i = 1; i <= 4; i++) {

		//�̵��Ϸ��� ����
		int dir = sharks[shark_num].dirmap[now_shark_dir][i];
		int nx = now_shark_x + dx[dir];
		int ny = now_shark_y + dy[dir];
		if (1 <= nx && nx <= n && 1 <= ny && ny <= n && smell[nx][ny].first == shark_num){
			
			if (map[nx][ny] != 0) {
				sharks[shark_num].die = true; //�� �״´�.
				map[now_shark_x][now_shark_y] = 0; //�� �ִ� �ڸ��� ��������.
				return;
			}
			next_shark_x = nx;
			next_shark_y = ny;
			next_shark_dir = dir;
			break;
		}
	}

	//�̵��� �� �ִٸ�
	sharks[shark_num].x = next_shark_x;
	sharks[shark_num].y = next_shark_y;
	sharks[shark_num].dir = next_shark_dir;

	//�� �� map ����
	map[now_shark_x][now_shark_y] = 0;
	map[next_shark_x][next_shark_y] = shark_num;

}

void all_shark_move() {

	
	for (int i = 1; i <= m; i++) {

		if (sharks[i].die) {
			continue;
		}
		one_shark_move(i);
	}	
}

void smell_minus() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (smell[i][j].first != 0) {
				smell[i][j].second--;

				if (smell[i][j].second == 0) {
					smell[i][j].first = 0;
				}
			}
		}
	}
}

bool finish() {
	//�� ������ false

	for (int i = 2; i <= m; i++) {
		if (!sharks[i].die) {
			return false;
		}
	}

	return true;
}
void solution() {

	spread_smell();

	for (int i = 1; i <= 1000; i++) {
		all_shark_move();
		smell_minus();
		spread_smell();

		if (finish()) {
			cout <<  i;
			exit(0);
		}
	}

	cout << -1;


}
void input() {

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				sharks[map[i][j]].x = i;
				sharks[map[i][j]].y = j;
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		cin >> sharks[i].dir;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 1; k <= 4; k++) {
				cin >> sharks[i].dirmap[j][k];
			}
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