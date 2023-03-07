#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int n;
int m;
int k;
int arr[11][11];
int nutrient[11][11];
deque<int> tree[11][11];

int dx[8] = { 1, -1, 0, 0,   1, 1, -1, -1 };
int dy[8] = { 0, 0,  1, -1, -1, 1, -1,  1 };

void spring() {
	//������ �ڽ��� ���̸�ŭ ����� �԰�, ���̰� 1 �����Ѵ�.

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < tree[i][j].size(); k++) {
				//������ ���
				if (arr[i][j] >= tree[i][j][k]){
					arr[i][j] -= tree[i][j][k];
					tree[i][j][k] += 1;
					continue;
				}
				tree[i][j][k] *= -1;
			}
		}
	}
}

void summer() {
	//���� ���� ������ ������� ���ϰ� �ȴ�. 
	//������ ���� �������� ���̸� 2�� ���� ���� ������ �ִ� ĭ�� ������� �߰��ȴ�. 
	//�Ҽ��� �Ʒ��� ������.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int size = tree[i][j].size();
			for (int k = size - 1; k >= 0; k--) {
				//���� ���� ���� �������
				if (tree[i][j][k] < 0) {
					//2�� ���� ���� ������ �ִ� 
					int dividebytwo = (-1 * tree[i][j][k]) / 2;
					arr[i][j] += dividebytwo;
					tree[i][j].pop_back();
				}
			}
		}
	}

}

void authum() {
	//�����ϴ� ������ ���̰� 5�� ����̾�� �ϸ�, 
	//������ 8���� ĭ�� ���̰� 1�� ������ �����. 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < tree[i][j].size(); k++) {
				int tree_age = tree[i][j][k];

				if (tree_age % 5 == 0) {
					//���� 5�� ������
					for (int k = 0; k < 8; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (1 <= nx && nx <= n && 1 <= ny && ny <= n) {
							tree[nx][ny].push_front(1);
						}
					}
				}
			}
		}
	}
}

void winter() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] += nutrient[i][j];
		}
	}
}
void solution() {

	for (int i = 1; i <= k; i++) {
		spring();
		summer();
		authum();
		winter();
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += tree[i][j].size();
		}
	}

	cout << ans;
}
void input() {

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = 5;
			cin >> nutrient[i][j];
		}
	}


	for (int i = 0; i < m; i++) {
		int x, y, z; //���� ��ġ: (x,y), ����: z
		cin >> x >> y >> z;
		tree[x][y].push_back(z);
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}