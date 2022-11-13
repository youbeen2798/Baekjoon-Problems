#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
int arr[51][51];
int times[51][51];
bool visited[51][51];


int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

vector<pair<int, int>> v;
vector <int> answers;

struct location {
	int x;
	int y;
};
queue <pair<location, int>> q;

int ans = 0;

int solution() {

	ans = 0;
	while (!q.empty()) {
		int a = q.front().first.x;
		int b = q.front().first.y;
		int cnt = q.front().second;
		ans = max(cnt, ans);
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ { nx,ny }, cnt + 1 });
				times[nx][ny] = cnt + 1;
			}
		}
	}

	return ans;
}

int confirmation() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) { //�湮 �� �� ���� �ִٸ�
				return -1;
			}
		}
	}
	return ans;
}

void reset() {
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) { //��
				visited[i][j] = true;
			}
		}
	}
}
void combination(vector<pair<int, int>> arr, vector<pair<int, int>> comb, int r, int idx, int depth) {

	if (r == 0) {
//		cout << "���̷���" << "\n";
		for (int i = 0; i < comb.size(); i++) {
//			cout << comb[i].first << " " << comb[i].second << "\n";
			q.push({ { comb[i].first, comb[i].second }, 0 });
			visited[comb[i].first][comb[i].second] = true;
		}
		solution();
		//���� ���̷����� �� ������ �ʾҴٸ� -1, �� �����ٸ� �ð��� ����
		answers.push_back(confirmation());
		reset();
	}
	else if (depth == arr.size()) {
		return;
	}
	else {
		//arr[depth]�� ���� ���
		comb[idx] = arr[depth];
		combination(arr, comb, r - 1, idx + 1, depth + 1);

		//arr[depth]�� ���� ���� ���
		combination(arr, comb, r, idx, depth + 1);
	}
}

void input() {
	cin >> n >> m; //�������� ũ��, ���� �� �ִ� ���̷��� ����

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) { //��
				visited[i][j] = true;
			}
			else if (arr[i][j] == 2) { //���̷���
				v.push_back({ i,j });
			}
		}
	}

	vector <pair<int, int>> comb(m);
	combination(v, comb, m, 0, 0);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();

	answers.erase(remove(answers.begin(), answers.end(), -1), answers.end());

	if (answers.empty()) {
		cout << -1;
		return 0;
	}
	sort(answers.begin(), answers.end());
	
	cout << answers[0];
}