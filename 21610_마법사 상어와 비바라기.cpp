#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int arr[51][51];

vector<pair<int, int>> clouds;

int dx[9] = { 0, 0, -1, -1,-1, 0, 1, 1, 1 };
int dy[9] = { 0, -1,-1, 0, 1,  1, 1, 0, -1 };

int diagonal_dx[4] = { -1,-1,1,1 };
int diagonal_dy[4] = { -1,1,-1,1 };

pair<int,int> check_in_range(int nx, int ny) {
	if (n < nx) {
		nx = nx % n;
		if (nx == 0) {
			nx = n;
		}
	}
	else if (nx < 1) {
		nx = n - abs(nx) % n;
	}
	
	
	if (n < ny) {
		ny = ny % n;
		if (ny == 0) {
			ny = n;
		}
	}
	else if (ny < 1) {
		ny = n - abs(ny) % n;
	}
	
	return { nx,ny };
}
void cloud_move(int di, int si) {
	//구름이 di방향으로 si칸 이동한다.
	for (int i = 0; i < clouds.size(); i++) {
		int nx = clouds[i].first + dx[di] * si;
		int ny = clouds[i].second + dy[di] * si;
		
		clouds[i] = check_in_range(nx, ny);
	}
}

void rain() {
	//저장된 물의 양 1 증가
	for (int i = 0; i < clouds.size(); i++) {
		arr[clouds[i].first][clouds[i].second]++;
	}
}

void magic() {

	vector<int> nums;
	for (int i = 0; i < clouds.size(); i++) {

		int num = 0;
		for (int j = 0; j < 4; j++) {
			int nx = clouds[i].first + diagonal_dx[j];
			int ny = clouds[i].second + diagonal_dy[j];

			if (1 <= nx && nx <= n && 1 <= ny && ny <= n && arr[nx][ny] > 0) {
				num++;
			}
		}
		nums.push_back(num);
	}

	for (int i = 0; i < clouds.size(); i++) {
		arr[clouds[i].first][clouds[i].second] += nums[i];
	}
}

void make_cloud() {

	vector<pair<int, int>> tmp = clouds;
	clouds.clear();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			pair<int, int> a = { i,j }; 
			if (arr[i][j] >= 2 && find(tmp.begin(), tmp.end(), a) == tmp.end()) {
				clouds.push_back({ i,j });
				arr[i][j] -= 2; 
			}
		}
	}
}
void solution(int di, int si) {

	cloud_move(di, si);

	rain();
	magic(); //마법 시전
	make_cloud();
}



void output() {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += arr[i][j];
		}
	}
	cout << ans;
}
void input() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	clouds.push_back({ n,1 });
	clouds.push_back({ n,2 });
	clouds.push_back({ n - 1,1 });
	clouds.push_back({ n - 1,2 });
	
	for (int i = 0; i < m; i++) {
		int di, si;
		cin >> di >> si;
		solution(di, si);

	}
	output();
 }
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
}