//BFS Ȥ�� DFS�� Ǯ�� ����
//�ش� �ڵ�� DFS�� Ǯ���� 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int input[100][100];
bool map[100][100];
bool visited[100][100];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int cnt = 0; //���� ����
vector <int> v; //���� ���� ���� ����

void reset() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = false;
			visited[i][j] = false;
		}
	}
	cnt = 0;
}

void DFS(int x, int y) {
	visited[x][y] = 1;

	for (int k = 0; k < 4; k++) {

		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if (map[nx][ny] == 1 && visited[nx][ny] == 0) {
				DFS(nx, ny);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int maxheight = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input[i][j];
			if (maxheight < input[i][j])
				maxheight = input[i][j];
		}
	}

	for (int h = 1; h <= maxheight; h++) { //1�̻� �ִ� ����

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (input[i][j] >= h) {
					map[i][j] = true;
				}
				else {
					map[i][j] = false;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 1 && visited[i][j] == 0) {
					DFS(i, j);
					cnt++;
				}
			}
		}

		v.push_back(cnt);

		reset(); //�ʱ�ȭ
	}

	sort(v.begin(), v.end()); //�������� ����
	cout << v[v.size() - 1]; //�ִ� ���
}