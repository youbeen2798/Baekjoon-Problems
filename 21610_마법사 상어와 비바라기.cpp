#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
int map[51][51];
bool cloud[51][51] = { true, };

int dx[4] = { 1,1,-1,-1 };
int dy[4] = { 1, -1,-1,1 };

//1번. 모든 그룸이 이동
vector <pair<int,int>>  move_cloud(int di, int si, vector <pair<int,int>> a) {
	if (di == 1) { //왼쪽으로 //열 감소
		for (int i = 0; i < a.size(); i++) {
			a[i].second -= si;

			while (1) {
				if (a[i].second <= 0) {
					a[i].second += n;
				}
				else {
					break;
				}
			}

			while (1) {
				if (n < a[i].second) {
					a[i].second -= n;
				}
				else {
					break;
				}
			}
		}

		return a;

	}
	if (di == 2) { //왼쪽 위 대각선으로 //행 감소 열 감소
		for (int i = 0; i < a.size(); i++) {
			a[i].first -= si;
			a[i].second -= si;

			while (1) {
				if (a[i].second <= 0) {
					a[i].second += n;
				}
				else {
					break;
				}
			}

			while (1) {
				if (n < a[i].second) {
					a[i].second -= n;
				}
				else {
					break;
				}
			}

			while (1) {
				if (a[i].first <= 0) {
					a[i].first += n;
				}
				else {
					break;
				}
			}

			while (1) {
				if (n < a[i].first) {
					a[i].first -= n;
				}
				else {
					break;
				}
			}
		}
		return a;

	}
	if (di == 3) { //위쪽으로 //행 감소
		for (int i = 0; i < a.size(); i++) {
			a[i].first -= si;

			while (1) {
				if (a[i].first <= 0) {
					a[i].first += n;
				}
				else {
					break;
				}
			}

			while (1) {
				if (n < a[i].first) {
					a[i].first -= n;
				}
				else {
					break;
				}
			}
		}
		return a;

	}
	if (di == 4) { //오른쪽 위 대각선으로 //행 감소 열 증가
		for (int i = 0; i < a.size(); i++) {
			a[i].first -= si;
			a[i].second += si;

			while (1) {
				if (a[i].second <= 0) {
					a[i].second += n;
				}
				else {
					break;
				}
			}

			while (1) {
				if (n < a[i].second) {
					a[i].second -= n;
				}
				else {
					break;
				}
			}

			while (1) {
				if (a[i].first <= 0) {
					a[i].first += n;
				}
				else {
					break;
				}
			}

			while (1) {
				if (n < a[i].first) {
					a[i].first -= n;
				}
				else {
					break;
				}
			}
		}
		return a;
	}
	if (di == 5) { //오른쪽으로 //열 증가
		for (int i = 0; i < a.size(); i++) {
			a[i].second += si;

			while (1) {
				if (a[i].second <= 0) {
					a[i].second += n;
				}
				else {
					break;
				}
			}

			while (1) {
				if (n < a[i].second) {
					a[i].second -= n;
				}
				else {
					break;
				}
			}
		}
		return a;
	}
	if (di == 6) { //오른쪽 아래 대각선으로 //행 증가 열 증가
		for (int i = 0; i < a.size(); i++) {
			a[i].first += si;
			a[i].second += si;

			while (1) {
				if (a[i].second <= 0) {
					a[i].second += n;
				}
				else {
					break;
				}
			}

			while (1) {
				if (n < a[i].second) {
					a[i].second -= n;
				}
				else {
					break;
				}
			}

			while (1) {
				if (a[i].first <= 0) {
					a[i].first += n;
				}
				else {
					break;
				}
			}

			while (1) {
				if (n < a[i].first) {
					a[i].first -= n;
				}
				else {
					break;
				}
			}
		}
		return a;
	}
	if (di == 7) { //아래로 //행 증가
		for (int i = 0; i < a.size(); i++) {
			a[i].first += si;


			while (1) {
				if (a[i].first <= 0) {
					a[i].first += n;
				}
				else {
					break;
				}
			}

			while (1) {
				if (n < a[i].first) {
					a[i].first -= n;
				}
				else {
					break;
				}
			}
		}
		return a;

	}
	if (di == 8) { //왼쪽 아래 대각선으로 //행 증가 열 감소
		for (int i = 0; i < a.size(); i++) {
			a[i].first += si;
			a[i].second -= si;

			while (1) {
				if (a[i].second <= 0) {
					a[i].second += n;
				}
				else {
					break;
				}
			}

			while (1) {
				if (n < a[i].second) {
					a[i].second -= n;
				}
				else {
					break;
				}
			}

			while (1) {
				if (a[i].first <= 0) {
					a[i].first += n;
				}
				else {
					break;
				}
			}

			while (1) {
				if (n < a[i].first) {
					a[i].first -= n;
				}
				else {
					break;
				}
			}
		}
		return a;
	}
}
//2번. 각 구름에서 비가 내려 구름이 있는 칸의 바구니에 저장된 물이 1 증가
void waterplusone(vector <pair<int, int>> a) {
	for (int i = 0; i < a.size(); i++) {
		map[a[i].first][a[i].second]++;
	}
}

void bugma(vector <pair<int, int>> a) {

	for (int i = 0; i < a.size(); i++) {
		int cnt = 0;
		
		for (int j = 0; j < 4; j++) {

			int new_x = a[i].first + dx[j];
			int new_y = a[i].second + dy[j];

			if (1 <= new_x && new_x <= n && 1 <= new_y && new_y <= n && map[new_x][new_y] != 0) {
				cnt++;
			}
		}

		map[a[i].first][a[i].second] += cnt;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	vector <pair<int, int>> a;

	a.push_back({ n,1 });
	a.push_back({ n,2 });
	a.push_back({ n-1,1 });
	a.push_back({ n-1,2 });


	for (int i = 0; i < m; i++) {
		int di, si;
		cin >> di >> si;
		a = move_cloud(di, si, a);
		waterplusone(a);
		bugma(a);

		vector <pair<int, int>> b;

		memset(cloud, true, sizeof(cloud));

		for (int j = 0; j < a.size(); j++) {
			cloud[a[j].first][a[j].second] = false;
		}

		a.clear();

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (cloud[i][j]) {
					if (map[i][j] >= 2) {
						a.push_back({ i,j }); //구름이 있는 곳
						map[i][j] -= 2;
					}
					else {
						cloud[i][j] = false;
					}
				}
			}
		}
	}

	int answer = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			answer += map[i][j];
		}
	}
	
	cout << answer;

	
}