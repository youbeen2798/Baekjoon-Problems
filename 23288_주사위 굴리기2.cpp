#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m, k;

int arr[21][21];
int dir = 0; //0 = ��, 1 = ��, 2 = ��, 3 = ��
bool clocks = true; // true�� �ð����, false�� �ݽð����
int x = 0;
int y = 0;
int nx;
int ny;
int jusawi[6] = { 1, 2, 5, 3, 4, 6 };
int ans = 0;

bool stop = false;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visited[21][21];

int bfs(int x, int y) {

	int k = arr[x][y];
	memset(visited, false, sizeof(visited));
	int ans = 0;
	ans++;

	queue <pair<int, int>> q;

	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m && visited[nx][ny] == false && arr[nx][ny] == k ) {
				q.push({ nx, ny });
				visited[nx][ny] = true;
				ans++;
			}
		}
	}

	return ans;
}
bool move(int x, int y) { //���� x, y
	
	dir += 4;
	dir %= 4; //�������� ����

	nx = x;
	ny = y;

	if (dir == 0) { //��
		ny++;
	}

	else if (dir == 1) { //��
		nx++;
	}

	else if (dir == 2) { //��
		ny--;
	}

	else{ //��
		nx--;
	}

	if (0 <= nx && nx < n && 0 <= ny && ny < m) {
		return true;
	}

	return false;

}
vector<int> rotation(int jusawi[6]) { //�ֻ��� ȸ��

	//���������� �𸣴� �ڵ�1
	dir += 4; 
	dir %= 4;

	vector<int> tmp;

	if (dir == 0) { //�������� ȸ���� ��	
		tmp.push_back(jusawi[4]);
		tmp.push_back(jusawi[1]);
		tmp.push_back(jusawi[2]);
		tmp.push_back(jusawi[0]);
		tmp.push_back(jusawi[5]);
		tmp.push_back(jusawi[3]);
	}
	else if (dir == 1) { //��
		tmp.push_back(jusawi[1]);
		tmp.push_back(jusawi[5]);
		tmp.push_back(jusawi[0]);
		tmp.push_back(jusawi[3]);
		tmp.push_back(jusawi[4]);
		tmp.push_back(jusawi[2]);
	}
	
	else if (dir == 2) { //��
		tmp.push_back(jusawi[3]);
		tmp.push_back(jusawi[1]);
		tmp.push_back(jusawi[2]);
		tmp.push_back(jusawi[5]);
		tmp.push_back(jusawi[0]);
		tmp.push_back(jusawi[4]);
	}

	else if (dir == 3) { //��
		tmp.push_back(jusawi[2]);
		tmp.push_back(jusawi[0]);
		tmp.push_back(jusawi[5]);
		tmp.push_back(jusawi[3]);
		tmp.push_back(jusawi[4]);
		tmp.push_back(jusawi[1]);
	}

	return tmp;
}

void input() {
	cin >> n >> m >> k; //���� ũ�� >> ���� ũ��

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
}


void solution() {

//	cout << "---------------------------------" << "\n";
//	cout << "�̵��� ����: " << dir << "\n";
	if (move(x, y)) { //�̵��������� �� ĭ ������
		x = nx;
		y = ny;
	}
	else {
		dir += 2;
		move(x, y); //�ݴ�������� ��ĭ ��������
		x = nx;
		y = ny;
	}

//	cout << "�̵� �� �ֻ��� ��ġ: ";
//	cout << "x: " << x << " " << "y: " << y << "\n";

	int ������ = arr[x][y];
//	cout << "������: " << ������ << "\n";
	
	vector <int> tmp = rotation(jusawi); //�ֻ��� ȸ��

//	cout << "�ٲ� �ֻ��� ���: ";
	for (int i = 0; i < tmp.size(); i++) {
		jusawi[i] = tmp[i];
//		cout << jusawi[i] << " "; // 4 2 5 1 6 3 ( �ٲ� �ֻ��� ��� )
	}
//	cout << "\n";

	int �ֻ����� = jusawi[5];
//	cout << "�ֻ��� �Ʒ���: " << �ֻ����� << "\n";

	if (������ > �ֻ�����) {
		dir -= 1;
		ans += bfs(x, y) * arr[x][y];
//		cout << "bfs: " << bfs(x, y) << "\n";
//		cout << "����: " << dir << "\n";
	}
	else if (������ < �ֻ�����) {
		dir += 1;
		ans += bfs(x, y) * arr[x][y];
//		cout << "bfs: " << bfs(x, y) << "\n";
//		cout << "����: " << dir << "\n";
	}
	else {
		ans += bfs(x, y) * arr[x][y];
//		cout << "���� ����";
	}
}


	/*
	vector <int> tmp = rotation(jusawi); //�ֻ��� ȸ��

	for (int i = 0; i < tmp.size(); i++) {
		jusawi[i] = tmp[i];
		cout << jusawi[i]; // 4 2 5 1 6 3 ( �ٲ� �ֻ��� ��� )
	}

	int bottom = jusawi[5]; //�ֻ��� �Ʒ���

	if (bottom > arr[x][y]) { //���� �ֻ��� �Ʒ����� �������� �� ũ�ٸ�
		//�ð�������� �̵�
		dir += 1; //dir = 1
		
		int nxt = move(dir, x, y).first;
		int 

		int ny = mo
	}
	*/
	
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	for (int i = 0; i < k; i++) {
		solution();
		if (stop) {
			cout <<  ans << "\n";
			break;
		}
	}
	if (!stop) {
		cout << ans << "\n";
	}

	/*
	solution();
	solution();
	solution();
	*/


}