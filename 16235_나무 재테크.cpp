#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int n; //�迭 ũ��
int m; //���� ����
int k;
int plus_arr[11][11]; //�ܿ︶�� �߰��Ǵ� ���
int arr[11][11]; //���� ó���� ���
vector<int> trees[11][11]; //����
int x, y, z; //(x,y) - ������ġ, z - ���� ����

int sping_dead_tree_eat[11][11]; //���� ������ ���� ���

int dx[8] = { -1,-1,-1,0,0,1,1, 1 };
int dy[8] = { -1,0,1,-1,1,-1,0, 1 };

void spring() {
	//��
	//������ �ڽ��� ���̸�ŭ ����� �԰�, 1 ����
	//�ϳ��� ĭ�� ���� ���� ������ ������ ���̰� � �������� ����� �Դ´�.
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sort(trees[i][j].begin(), trees[i][j].end());
			int size = trees[i][j].size(); //size�� ����ó���ϴ°� �ð� �ʰ��� ����
			for (int k = 0; k < size; k++) {
				//������ ������ŭ
				int age = trees[i][j][k]; //������ ���� 
				if (arr[i][j] >= age) { //����� ���� �� �ִٸ� �԰�
					trees[i][j][k]++; //���� 1����
					arr[i][j] -= age;
					continue;
				}
				//�ƴ� ��� �״´�.
				trees[i][j][k] *= -1;
			}
		}
	}
}

void summer() {
	//���� ���� ������ ������� ���ϰ� �ȴ�.
	//������ ���� �������� ���̸� 2�� ���� ���� ������ �ִ� ĭ�� ������� �߰��ȴ�.

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = trees[i][j].size() - 1; k >= 0; k--) {
				if (trees[i][j][k] < 0) { //���� �����̸�
					arr[i][j] -= trees[i][j][k] / 2; //  ��� �߰�
					trees[i][j].pop_back();
				}
			}
		}
	}
}

void fall() {
	//������ �����Ѵ�.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < trees[i][j].size(); k++) {
				int age = trees[i][j][k]; //���� ����
				if (age % 5 == 0) { //���Ⱑ 5�� ����̸�
					for (int t = 0; t < 8; t++) {
						//������ 8�� ĭ�� ���̰� 1�� ������ �����.
						int nx = i + dx[t];
						int ny = j + dy[t];
						if (1 <= nx && nx <= n && 1 <= ny && ny <= n) {
							trees[nx][ny].push_back(1);
						}
					}
				}
			}
		}
	}
}

void winter() {
	//����� �߰��Ѵ�.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] += plus_arr[i][j];
		}
	}
}

void solution() {

	for (int i = 0; i < k; i++) {
		spring(); //��
		summer(); //����
		fall(); //����
		winter(); //�ܿ�
	}


	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += trees[i][j].size();
		}
	}
	cout << ans;

}
void input() {
	
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = 5; //���� ó���� ����� 5
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> plus_arr[i][j]; //ĭ�� �߰��ϴ� ���
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		trees[x][y].push_back(z); //(x,y)�� ���̰� z�� ������ ����
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}