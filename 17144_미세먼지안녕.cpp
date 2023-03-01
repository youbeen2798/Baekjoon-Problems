#include <iostream>
#include <vector>
#include <cstring>


using namespace std;

int r, c, t;
int arr[51][51];
int plus_dust[51][51];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

pair<int, int> air_fresh1; //���� û���� �� ����
pair<int, int> air_fresh2; //���� û���� �Ʒ� ����

void real_spread(int x, int y) {

	int dust_amount = arr[x][y]; //���� �ִ� ���� ��

	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		//������ ���� �����鼭 �̼������� �ִٸ�
		if (1 <= nx && nx <= r && 1 <= ny && ny <= c && arr[nx][ny] != -1) {
			plus_dust[nx][ny] += dust_amount / 5;
			cnt++;
		}
	}

	//3�� �Ѹ� ��ŭ 3�� - 
	plus_dust[x][y] -= cnt * (dust_amount / 5);
}
void dust_spread() {

	memset(plus_dust, 0, sizeof(plus_dust));

	//�̼������� Ȯ��ȴ�.
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			//����û���Ⱑ �ƴϰ�, �̼������� �ִٸ� Ȯ��ȴ�.
			if (arr[i][j] != -1 && arr[i][j] != 0) {
				real_spread(i, j);
			}
		}
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			arr[i][j] += plus_dust[i][j];
		}
	}
}

void dust_rotate1() {

	//����û���� �ٷ� ���� �ִ� ���� ����
	int air_fresh_x = air_fresh1.first;
	int air_fresh_y = air_fresh1.second;

	arr[air_fresh_x - 1][air_fresh_y] = 0;


	//�Ʒ���
	for (int i = air_fresh_x - 2; i >= 0; i--) {
		arr[i + 1][air_fresh_y] = arr[i][air_fresh_y];
	}

	//��������
	for (int j = 1; j <= c; j++) {
		arr[1][j - 1] = arr[1][j];
	}

	//��������
	for (int i = 2; i <= air_fresh_x; i++) {
		arr[i - 1][c] = arr[i][c];
	}

	//����������
	for (int j = c - 1; j >= air_fresh_y + 1; j--) {
		arr[air_fresh_x][j + 1] = arr[air_fresh_x][j];
	}
	arr[air_fresh_x][air_fresh_y + 1] = 0;
}

void dust_rotate2() {

	//�Ʒ� û�ұ� ��ȯ
	int air_fresh_x = air_fresh2.first;
	int air_fresh_y = air_fresh2.second;

	//����
	for (int i = air_fresh_x + 1; i < r; i++) {
		arr[i][1] = arr[i + 1][1];
	}

	//��������
	for (int j = 0; j < c; j++) {
		arr[r][j] = arr[r][j + 1];
	}

	//�Ʒ���
	for (int i = r; i > air_fresh_x; i--) {
		arr[i][c] = arr[i - 1][c];
	}

	//����������
	for (int j = c; j > air_fresh_y + 1; j--) {
		arr[air_fresh_x][j] = arr[air_fresh_x][j - 1];
	}

	arr[air_fresh_x][air_fresh_y + 1] = 0;

}
void dust_rotate() {
	//������ ��ȸ�Ѵ�.
	dust_rotate1();
	dust_rotate2();
}
void output() {

	long ans = 0;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (arr[i][j] != -1) { //���� û���Ⱑ �ƴ϶��
				ans += arr[i][j];
			}
		}
	}

	cout << ans;
}

void solution() {

	for (int i = 0; i < t; i++) {
		dust_spread();
		dust_rotate();
	}
	output();

}
void input() {

	vector<pair<int, int>> air_freshes;

	cin >> r >> c >> t;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == -1) { //���� û������
				air_freshes.push_back({ i,j });
			}
		}
	}

	air_fresh1 = air_freshes[0];
	air_fresh2 = air_freshes[1];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}