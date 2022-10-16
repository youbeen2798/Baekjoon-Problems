#include <iostream>

using namespace std;

int n, m, k;
int board[21][21];
pair<int, int> smell[21][21];

//�� �Ʒ� ���� ������
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,-1,1 };

struct Shark {
	bool dead;
	int x;
	int y;
	int dir;
	int Rank[5][4];
};

Shark shark[401];

bool valid(int x, int y) {
	if (0 <= x && x < n && 0 <= y && y < n) {
		return true;
	}
	return false;
}

void remove_smell() {


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			//�̹��� ���� ���� ���� �� ���� ���̳ʽ��ϱ�!
			if (smell[i][j].second != 0 && board[i][j] == 0) {
				if (smell[i][j].second > 1) {
					smell[i][j].second--;
				}
				else {
					smell[i][j] = { 0,0 };
				}
			}
		}
	}
}
void moving() {

	//��� ����
	for (int i = 1; i <= m; i++) {

		//�� ���� �ʾ��� ��츸 �̵�
		if (!shark[i].dead) {

			//����� ��ġ�� ���� 
			int x = shark[i].x;
			int y = shark[i].y;
			int dir = shark[i].dir;
			bool found = false;

			//������ ��ġ�� ������ ���ٸ� �̵�
			for (int j = 0; j < 4; j++) {
				found = false;
				//�켱������ ���� �̵��� ��ġ�� ����
				int f_dir = shark[i].Rank[dir][j];
				int tx = x + dx[f_dir];
				int ty = y + dy[f_dir];

				//������ ���ٸ�
				if (valid(tx, ty) && smell[tx][ty].first == 0) {

					//�����̷��� �ϴ� ĭ�� �� �����Ѵٸ�
					//������ ���µ� �� �����Ѵٴ� ����, �̹� Ÿ�ӿ� �̵��� �����
					//���� ���� �켱������ �����Ƿ� ���� ����
					if (board[tx][ty] != 0) {
						board[x][y] = 0;
						shark[i].dead = true;
						found = true;
					}
					else {
						board[x][y] = 0; //���� �ִ� ��ġ�� ����
						board[tx][ty] = i;
						shark[i].x = tx; //��� ��ġ ����
						shark[i].y = ty;
						shark[i].dir = f_dir;
						found = true;
					}
					break;
				}
			}
			if (!found) { //��ġ�� �� ã�Ҵٸ�
				for (int j = 0; j < 4; j++) {

					//�켱������ ���� ����� ��ġ
					int f_dir = shark[i].Rank[dir][j];
					int tx = x + dx[f_dir];
					int ty = y + dy[f_dir];

					//���� ������ ������ �ִٸ�
					if (valid(tx, ty) && smell[tx][ty].first == i) {
						board[x][y] = 0;
						board[tx][ty] = i;
						shark[i].x = tx;
						shark[i].y = ty;
						shark[i].dir = f_dir;
						break;
					}
				}
			}
		}
	}

	//������ ���� �����
	for (int i = 1; i <= m; i++) {

		//���� ���� ���鿡 ���ؼ���
		if (!shark[i].dead) {
			int x = shark[i].x;
			int y = shark[i].y;

			smell[x][y] = { i, k };
		}
	}
}
int simulation() {

	int time = 0;

	while (time <= 1000) {
		bool flag = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] != 0 && board[i][j] != 1) { //�ٸ� �� �ִٸ�
					flag = true;
					break;
				}
			}
			if (flag) {
				break;
			}
		}

		if (!flag) {
			break;
		}

		//�� �̵���Ű�� ������ �����.
		moving();

		remove_smell();

		time += 1;
	}

	if (time > 1000) {
		return -1;
	}
	else {
		return time;
	}
}
void input() {
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0) {
				shark[board[i][j]].x = i;
				shark[board[i][j]].y = j;
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		cin >> shark[i].dir;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> shark[i].Rank[j][k];
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		int x = shark[i].x;
		int y = shark[i].y;

		smell[x][y].first = i;
		smell[x][y].second = k;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	cout << simulation();
}
