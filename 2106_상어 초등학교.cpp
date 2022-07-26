#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

int seat[21][21];
vector <int> v[401]; //학생과 좋아하는 학생들 저장하는 벡터

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int good[5] = { 0,1, 10, 100, 1000 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int number = n * n;

	while (number--) {
		bool found = false;

		int x, y; //자리
		int st, a, b, c, d;
		cin >> st >> a >> b >> c >> d;
		v[st].push_back(a); //v[4] = {2,5,1,7}
		v[st].push_back(b);
		v[st].push_back(c);
		v[st].push_back(d);

		//1번 단계
		vector <pair<int, int>> vec1[5];

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (seat[i][j] == 0) { //비어있을 때
					int cnt = 0;
					for (int dir = 0; dir < 4; dir++) {
						int nx = i + dx[dir];
						int ny = j + dy[dir];

						if (nx < 1 || n < nx || ny < 1 || n < ny) {
							continue;
						}
						if (seat[nx][ny] == a || seat[nx][ny] == b || seat[nx][ny] == c || seat[nx][ny] == d) {
							cnt++;
						}
					}
					vec1[cnt].push_back({ i,j }); //vector[4] = {{1,2}}; <= (1,2)에 인접한 칸은 4개
				}
			}
		}

		int after1;
		for (int i = 4; i >= 0; i--) { //인접한 칸이 많은 것부터 확인
			if (vec1[i].empty()) {
				continue;
			}
			int size = vec1[i].size();

			if (size == 1) {
				x = vec1[i][0].first;
				y = vec1[i][0].second;
				found = true;
				break;
			}
			else {
				after1 = i;
				break;
			}
		}

		if (found) {
			seat[x][y] = st;
			continue;
		}

		//2단계

		int after2;
		vector <pair<int, int>> vec2[5];
		for (auto x : vec1[after1]) { // x = {1,5}, {2,4}

			int cnt = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nx = x.first + dx[dir];
				int ny = x.second + dy[dir];

				if (nx < 1 || n < nx || ny < 1 || n < ny) {
					continue;
				}
				if (seat[nx][ny] == 0) {
					cnt++;
				}

			}
			vec2[cnt].push_back({ x.first, x.second });
		}


		for (int i = 4; i >= 0; i--) {
			if (vec2[i].empty()) {
				continue;
			}
			int size = vec2[i].size();
			if (size == 1) {
				x = vec2[i][0].first;
				y = vec2[i][0].second;
				found = true;
				break;
			}
			else {
				after2 = i;
				break;
			}
		}

		if (found) {
			seat[x][y] = st;
			continue;
		}

		//3번
		sort(vec2[after2].begin(), vec2[after2].end());

		x = vec2[after2][0].first;
		y = vec2[after2][0].second;
		found = true;

		if (found) {
			seat[x][y] = st;
			continue;
		}

	}

	long long answer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			int num = seat[i][j];
			int cnt = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];

				if (nx < 1 || n < nx || ny < 1 || n < ny) {
					continue;
				}

				if (seat[nx][ny] == v[num][0] || seat[nx][ny] == v[num][1]
					|| seat[nx][ny] == v[num][2] || seat[nx][ny] == v[num][3]) {
					cnt++;
				}
			}

			answer += good[cnt];
		}
	}

	cout << answer;
}