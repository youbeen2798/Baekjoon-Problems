#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int r, c, k;
int arr[101][101];
int answer = 0;
int row, col;
int num_cnt[101];

void solve() {

	while (1) {

		if (arr[r][c] == k) { //���� ������ �����ϸ�
			cout << answer;
			break;
		}
		if (answer > 100) { //100�� ������ �Ѿ��
			cout << -1;
			exit(0);
		}

		answer++;

		if (row >= col) { //���� ũ�Ⱑ �� ũ�ٸ�

			int max_col = 0;
			for (int i = 1; i <= row; i++) {

				memset(num_cnt, 0, sizeof(num_cnt)); //�ʱ�ȭ

				for (int j = 1; j <= col; j++) {
					if (arr[i][j] == 0) {
						continue;
					}
					num_cnt[arr[i][j]]++; //���� ���ϱ�
				}

				vector<pair<int, int>> v;

				for (int j = 1; j <= 100; j++) {
					if (num_cnt[j] != 0) {
						v.push_back({ num_cnt[j], j });
					}
				}

				int v_size = v.size() * 2;

				max_col = max(max_col, min(100, v_size)); //���� ū ���� ũ�� ����

				for (int j = 1; j <= col; j++) {
					arr[i][j] = 0;
				}

				sort(v.begin(), v.end());

				int idx = 1;

				if (v.size() < 50) {
					for (int j = 0; j < v.size(); j++) {
						arr[i][idx++] = v[j].second;
						arr[i][idx++] = v[j].first;
						
					}
				}
				else {
					for (int j = 0; j < 50; j++) {
						arr[i][idx++] = v[j].second; //2
						arr[i][idx++] = v[j].first; //1
					}
				}

			}

			col = max_col;
		}
		else {

			int max_row = 0;

			for (int i = 1; i <= col; i++) {

				memset(num_cnt, 0, sizeof(num_cnt));
				for (int j = 1; j <= row; j++) {
					if (arr[j][i] == 0) {
						continue;
					}
					num_cnt[arr[j][i]]++;
				}

				vector<pair<int, int>> v;

				for (int j = 1; j <= 100; j++) {
					if (num_cnt[j] != 0) {
						v.push_back({ num_cnt[j], j });
					}
				}

				sort(v.begin(), v.end());

				for (int j = 1; j <= row; j++) {
					arr[j][i] = 0;
				}

				int k = v.size() * 2;
				max_row = max(max_row, min(k, 100)); //���� ū ���� ũ�� ����

				int idx = 1;

				if (v.size() < 50) {
					for (int j = 0; j < v.size(); j++) {
						arr[idx++][i] = v[j].second;
						arr[idx++][i] = v[j].first;
					}
				}
				else {
					for (int j = 0; j < 50; j++) {
						arr[idx++][i] = v[j].second;
						arr[idx++][i] = v[j].first;
					}
				}
			}

			row = max_row;
		}
	}

}

void input() {
	cin >> r >> c >> k;

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> arr[i][j];
		}
	}

	row = 3;
	col = 3;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}