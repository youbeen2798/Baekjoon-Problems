#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <set>
#include <cstring>

using namespace std;

int n, m;
int map[51][51];
int plus_map[51][51];
vector<pair<int, int>> v;
vector<pair<int, int>> clouds;
vector<pair<int, int>> new_clouds;

int dx[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int dy[9] = { 0, -1,-1,0,1,1,1,0,-1 };

int rdx[4] = { 1,1, -1,-1 };
int rdy[4] = { 1, -1,1,-1 };

pair<int,int> cloud_move(int x, int y, int di, int si) {
//(x,y) 위치에 있는 구름이 di방향으로 si만큼 이동한다.

	int nx = x + dx[di] * si;
	int ny = y + dy[di] * si;
	pair<int, int> p = { nx,ny };


	if (nx < 1) {
		p.first = n - abs(nx) % n;
	}
	else if (nx > n && (nx % n) == 0) {
		p.first = n;
	}
	else if (nx > n) {
		p.first = nx % n;
	}

	if (ny < 1) {
		p.second = n - abs(ny) % n;
	}
	else if (ny > n && ny % n == 0) {
		p.second = n;
	}
	else if (ny > n) {
		p.second = ny % n;
	}

	return p;
}
void clouds_move(int di, int si) {
	//구름이 di방향으로 si만큼 이동한다.

	new_clouds.clear();

	for (int i = 0; i < clouds.size(); i++) {
		int x = clouds[i].first;
		int y = clouds[i].second;
		pair<int,int> p = cloud_move(x, y, di, si);
		new_clouds.push_back(p); //새로운 
	}

	clouds = new_clouds;
}

void clouds_rain() {
	//각 구름에서 비가 내려 구름이 있는 칸의 바구니에 물의 양이 1증가

	for (int i = 0; i < clouds.size(); i++) {
		int x = clouds[i].first;
		int y = clouds[i].second;
		map[x][y]++; //물의 양이 1증가
	}
}

void magic() {
	//마법을 시전한다.

	memset(plus_map, 0, sizeof(plus_map));
	for (int i = 0; i < new_clouds.size(); i++) {
		int x = new_clouds[i].first;
		int y = new_clouds[i].second;

		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			int nx = x + rdx[j];
			int ny = y + rdy[j];
			if (1 <= nx && nx <= n && 1 <= ny && ny <= n && map[nx][ny] > 0) {
				cnt++;
			}
		}
		map[x][y] += cnt;
	}
}

void cloud_and_rain() {

	set<pair<int, int>> s;

	for (int i = 0; i < clouds.size(); i++) {
		s.insert({ clouds[i] });
	}

	clouds.clear();
	new_clouds.clear();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			//바구니에 저장된 물의 양이 2이상인 
			//모든 칸에 구름이 생기고, 
			// 물의 양이 2 줄어든다.
			if (map[i][j] >= 2 && s.find({i, j}) == s.end()) {
				clouds.push_back({ i,j });
				map[i][j] -= 2;
			}
		}
	}
}

void solution() {

	//(n,1), (n,2), (n-1, 1), (n-1,2)에 비구름이 생긴다.
	clouds.push_back({ n,1 });
	clouds.push_back({ n, 2 });
	clouds.push_back({ n - 1, 1 });
	clouds.push_back({ n - 1, 2 });

	for (int i = 0; i < m; i++) {
		int di = v[i].first; //방향
		int si = v[i].second; //칸수
		clouds_move(di, si);
		clouds_rain();
		magic(); //마법을 시전한다.
		cloud_and_rain();
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += map[i][j];
		}
	}
	cout << ans;

}

void input() {

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int di, si;
		cin >> di >> si;
		v.push_back({ di, si });
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}