#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int m;
int arr[50][50];
int shark_x; //��� ��
int shark_y; //��� ��

vector<int> gusuls;
int ans[4];

void bumb(int di, int si) {
	//����� �Ÿ�
	if (di == 1) { //��
		for (int i = 1; i <= si; i++) {
			arr[shark_x - i][shark_y] = 0;
		}
	}
	else if (di == 2) { //�Ʒ�
		for (int i = 1; i <= si; i++) {
			arr[shark_x + i][shark_y] = 0;
		}
	}
	else if (di == 3) { //����
		for (int i = 1; i <= si; i++) {
			arr[shark_x][shark_y - i] = 0;
		}
	}
	else { //������
		for (int i = 1; i <= si; i++) {
			arr[shark_x][shark_y + i] = 0;
		}
	}
}


vector<int> get_gusuls() {

	vector<int> tmp_gusuls;
	int x = shark_x;
	int y = shark_y;

	for (int i = 1; i <= n - 2; i += 2) {
		//����
		for (int j = 1; j <= i; j++) {
			y--;

			if (arr[x][y] != 0) {
				tmp_gusuls.push_back(arr[x][y]);
			}
		}
		//�Ʒ���
		for (int j = 1; j <= i; j++) {
			x++;
			if (arr[x][y] != 0) {
				tmp_gusuls.push_back(arr[x][y]);
			}
		}
		//������
		for (int j = 1; j <= i + 1; j++) {
			y++;
			if (arr[x][y] != 0) {
				tmp_gusuls.push_back(arr[x][y]);
			}
		}
		//����
		for (int j = 1; j <= i + 1; j++) {
			x--;
			if (arr[x][y] != 0) {
				tmp_gusuls.push_back(arr[x][y]);
			}
		}
	}

	for (int i = 1; i <= n - 1; i++) {
		y--;
		if (arr[x][y] != 0) {
			tmp_gusuls.push_back(arr[x][y]);
		}
	}

	return tmp_gusuls;
}

void real_arrange(vector<int> gusuls) {
	//������ �ٽ� �迭�� ����

	memset(arr, 0, sizeof(arr));
	int x = shark_x;
	int y = shark_y;
	int idx = 0;

	int diff = gusuls.size() - n * n - 1;

	for (int i = 0; i < diff; i++) {
		gusuls.pop_back();
	}


	while (true) {
		for (int i = 1; i <= n - 2; i += 2) {
			//����
			for (int j = 1; j <= i; j++) {
				y--;
				if (idx >= gusuls.size()) {
					return;
				}
				arr[x][y] = gusuls[idx++];
			}
			//�Ʒ���
			for (int j = 1; j <= i; j++) {
				x++;
				if (idx >= gusuls.size()) {
					return;
				}
				arr[x][y] = gusuls[idx++];
			}
			//������
			for (int j = 1; j <= i + 1; j++) {
				y++;
				if (idx >= gusuls.size()) {
					return;
				}
				arr[x][y] = gusuls[idx++];
			}
			//����
			for (int j = 1; j <= i + 1; j++) {
				x--;
				if (idx >= gusuls.size()) {
					return;
				}
				arr[x][y] = gusuls[idx++];
			}
		}

		for (int i = 1; i <= n - 1; i++) {
			y--;
			if (idx >= gusuls.size()) {
				return;
			}
			arr[x][y] = gusuls[idx++];
		}
	}
}
void arrange() {

	vector<int> tmp_gusuls = get_gusuls();
	real_arrange(tmp_gusuls);
}


bool over_four_bumb() {
	//�����ϴ� ������ 4�� �̻� �����ϴ� ������ ���� ��

	bool bumb_possible = false; //�����Ұ� �ִ��� Ȯ��

	//�����ϱ� �� ����
	vector<int> before_bumb_gusuls = get_gusuls();

	//���� �� ����
	vector<int> after_bumb_gusuls;

	for (int i = 0; i < before_bumb_gusuls.size(); i++) {
		int num = before_bumb_gusuls[i];
		vector<int> tmp;
		tmp.push_back(num);
		int same_num_cnt = 1;

		for (int j = i + 1; j < before_bumb_gusuls.size(); j++) {
			if (before_bumb_gusuls[j] == num) {
				same_num_cnt++;
				tmp.push_back(num);
				continue;
			}
			break;
		}

		//4�� �̻� �����ϴ� ������ ���� �� 
		if (same_num_cnt >= 4 && num != 0) {
			i += same_num_cnt - 1;
			ans[num] += same_num_cnt;
			bumb_possible = true; //���� �Ұ� ����
			continue;
		}

		//4�� �̻� �����ϴ� ������ ���� �� 
		i += same_num_cnt - 1;
		for (int j = 0; j < tmp.size(); j++) {
			after_bumb_gusuls.push_back(tmp[j]);
		}
	}

	if (bumb_possible) {

		real_arrange(after_bumb_gusuls);

		return true;
	}
	return false;
}

void gusul_num_change() {

	//�����ϱ� �� ����
	vector<int> before_bumb_gusuls = get_gusuls();
	
	//���� �� ����
	vector<int> after_bumb_gusuls;

	for (int i = 0; i < before_bumb_gusuls.size(); i++) {
		int num = before_bumb_gusuls[i];
		vector<int> tmp;
		tmp.push_back(num);
		int same_num_cnt = 1;

		for (int j = i + 1; j < before_bumb_gusuls.size(); j++) {
			if (before_bumb_gusuls[j] == num) {
				same_num_cnt++;
				tmp.push_back(num);
				continue;
			}
			break;
		}

		i += same_num_cnt - 1;
		if (num == 0) {
			break;
		}
		after_bumb_gusuls.push_back(same_num_cnt);
		after_bumb_gusuls.push_back(num);
	}


	real_arrange(after_bumb_gusuls);
}

void get_ans() {

	int real_ans = 0;

	for (int i = 1; i <= 3; i++) {
		real_ans += ans[i] * i;
	}

	cout << real_ans;
	exit(0);
}

void solution(int di, int si) {
	//����� �Ÿ�
	
	bumb(di, si); //���� ����
	arrange();

	while(true) {
		if (!over_four_bumb()) {
			break;
		}
	}

	gusul_num_change();
	
}




void input() {
	cin >> n >> m;

	shark_x = (n + 1) / 2;
	shark_y = (n + 1) / 2;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int di, si; //����� �Ÿ�
		cin >> di >> si;
		solution(di, si);
	}

	get_ans();
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
}