#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

int n, m;
int arr[50][50];
pair<int, int> shark;

vector<int> gusuls;
vector <pair<int, int>> mabub;

map<int, pair<int, int>> maps;
vector <int> v;
bool stop_bumb;
map <int, int> bumped;

void first(int shark_x, int shark_y, int di, int si) { //제일 처음에 상어 구슬

	if (di == 1) { //위로
		for (int i = 1; i <= si; i++) {
			int x = arr[shark_x - i][shark_y];
			arr[shark_x - i][shark_y] = -1;
		}
	}
	else if (di == 2) { //아래로
		for (int i = 1; i <= si; i++) {
			int x = arr[shark_x + i][shark_y];
			arr[shark_x + i][shark_y] = -1;
		}
	}
	else if (di == 3) { //왼쪽으로
		for (int i = 1; i <= si; i++) {
			int x = arr[shark_x][shark_y - i];
			arr[shark_x][shark_y - i] = -1;
		}
	}
	else if (di == 4) { //오른쪽으로
		for (int i = 1; i <= si; i++) {
			int x = arr[shark_x][shark_y + i];
			arr[shark_x][shark_y + i] = -1;
		}
	}
}

void write_map() {

	int cnt = n * n - 1;
	int size = n - 1; //6만큼

	int k = size / 2;
	for (int i = 1; i <= k; i++) { //1부터 3까지

		int start_x = i; //1
		int start_y = i; //1

		for (int j = 0; j < size; j++) {
			maps.insert({ cnt,{ start_x, start_y + j} });
			cnt--;
		}

		start_y = i + size; // start_y = 7;
		for (int j = 0; j < size; j++) {
			maps.insert({ cnt,{ start_x + j, start_y} });
			cnt--;
		}

		start_x = i + size;
		for (int j = 0; j < size; j++) { //왼쪽
			maps.insert({ cnt,{ start_x, start_y - j} });
			cnt--;
		}

		start_y = i;
		for (int j = 0; j < size; j++) {
			maps.insert({ cnt,{ start_x - j, start_y} });
			cnt--;
		}
		size -= 2;
	}

}

void bumb() {
	//arr이 4개 이상 구슬이 있을 때 -1로 바꿔준다.

	int cnt = 0;

	vector <pair<int, int>> tmp;

	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i] == 0) {
			break;
		}
		else if (v[i] == v[i + 1]) {
			cnt++;
		}
		else {
			if (cnt >= 3) {
				tmp.push_back({ i,cnt });
			}
			cnt = 0;
		}
	}

	for (int i = 0; i < tmp.size(); i++) {
		int x = tmp[i].first; //4
		int y = tmp[i].second; //4
		bumped[v[x]] += ++y;
		for (int j = 0; j < y; j++) { //x - j = 1 ~ x - j = 5
			v[x - j] = -1; //v[4], v[3], v[2], v[1]
		}
	}

	vector <int> tmp_v;


	for (int i = 0; i < v.size(); i++) {
		if (v[i] != -1) {
			tmp_v.push_back(v[i]);
		}
	}

	v.clear();
	v = tmp_v;




	if (tmp.size() > 0) {
		stop_bumb = false;
	}
	else {
		stop_bumb = true;
	}
}

void move2() {

	memset(arr, 0, sizeof(arr));

	for (int i = 0; i < v.size(); i++) {
		pair<int, int> p = maps[i + 1];
		arr[p.first][p.second] = v[i];
	}
}

void move3() {

	memset(arr, 0, sizeof(arr));

	if (v.size() < n * n) {
		for (int i = 0; i < v.size(); i++) {
			pair<int, int> p = maps[i + 1];
			arr[p.first][p.second] = v[i];
		}
	}

	else {
		for (int i = 0; i < n * n; i++) {
			pair<int, int> p = maps[i + 1];
			arr[p.first][p.second] = v[i];
		}
	}
}
void before_move() {
	v.clear();
	for (int i = 1; i <= n * n; i++) {
		pair<int, int> p = maps[i];
		int x = p.first;
		int y = p.second;
		if (arr[x][y] != -1) {
			v.push_back(arr[x][y]);
		}
	}
}
void move() {

	memset(arr, 0, sizeof(arr));

	for (int i = 0; i < v.size(); i++) {
		pair<int, int> p = maps[i + 1];
		arr[p.first][p.second] = v[i];
	}
}

void double_v() {

	vector <pair<int, int>> vt;

	int cnt = 0;

	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i] != 0) {
			if (v[i] == v[i + 1]) {
				cnt++;
			}
			else {
				vt.push_back({ v[i], cnt + 1 });
				cnt = 0;
			}
		}
	}

	v.clear();

	for (int i = 0; i < vt.size(); i++) {
		v.push_back(vt[i].second);
		v.push_back(vt[i].first);
	}
}

void solution() {

	for (int i = 0; i < mabub.size(); i++) {
		int di = mabub[i].first;
		int si = mabub[i].second;

		first(shark.first, shark.second, di, si); //상어 구슬 삭제

		before_move();
		move();

		while (true) {
			bumb(); //4개 이상인 것들
			if (stop_bumb) {
				break;
			}
			move2();

		}
		double_v();
		move3();


	}
}
void input() {
	cin >> n >> m;

	write_map();
	//상어 위치
	shark.first = (n + 1) / 2;
	shark.second = (n + 1) / 2;


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	//블리자드 마법의 방향 di와 거리 si

	for (int i = 0; i < m; i++) {
		int di;
		int si;
		cin >> di >> si; //방향과 거리
		mabub.push_back({ di,si });
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	bumped[1] = 0;
	bumped[2] = 0;
	bumped[3] = 0;

	input();
	solution();



	cout << 1 * bumped[1] + 2 * bumped[2] + 3 * bumped[3];

}