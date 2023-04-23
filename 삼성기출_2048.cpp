#include <iostream>
#include <vector>

using namespace std;

int n; //격자 크기
int map[21][21];
int input_map[21][21];
int dir[6];
int ans = 0;

void copy() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = input_map[i][j];
		}
	}
}

void output() {

	cout << "############" << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}
vector<int> real_move(vector<int> v) {

	vector<int> vt;

	for (int i = 0; i < v.size(); i++) {
		if (i == v.size() - 1 || v[i] != v[i + 1]) {
			ans = max(ans, v[i]);
			vt.push_back(v[i]);
		}
		else {
			ans = max(ans, v[i] * 2);
			vt.push_back(v[i] * 2);
			i++;
		}
	}

	//cout << "----------" << "\n";
	//for (int i = 0; i < vt.size(); i++) {
	//	cout << vt[i] << " ";
	//}
	return vt;
}

void left() {

	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < n; j++) {
			if (map[i][j] != 0) {
				v.push_back(map[i][j]);
				map[i][j] = 0;
			}
		}
		v = real_move(v);

		if (v.size() == 0) {
			continue;
		}
		for (int j = 0; j < n; j++) {
			map[i][j] = v[j];
			if (j == v.size() - 1) {
				break;
			}
		}
	}
}

void right() {

	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = n - 1; j >= 0; j--) {
			if (map[i][j] != 0) {
				v.push_back(map[i][j]);
				map[i][j] = 0;
			}
		}
		v = real_move(v);

		int idx = 0;
		if (v.size() == 0) {
			continue;
		}
		for (int j = n - 1; j >= 0; j--) {
			map[i][j] = v[idx];
			if (idx == v.size() - 1) {
				break;
			}
			idx++;
		}
	}
}

void down() {

	for (int j = 0; j < n; j++) {
		vector<int> v;
		for (int i = n - 1; i >= 0; i--) {
			if (map[i][j] != 0) {
				v.push_back(map[i][j]);
				map[i][j] = 0;
			}
		}
		v = real_move(v);

		int idx = 0;
		if (v.size() == 0) {
			continue;
		}
		for (int i = n - 1; i >= 0; i--) {
			map[i][j] = v[idx];
			if (idx == v.size() - 1) {
				break;
			}
			idx++;
		}
	}
}

void up() {

	for (int j = 0; j < n; j++) {
		vector<int> v;
		for (int i = 0; i < n; i++) {
			if (map[i][j] != 0) {
				v.push_back(map[i][j]);
				map[i][j] = 0;
			}
		}
		v = real_move(v);

		int idx = 0;

		if (v.size() == 0) {
			continue;
		}
		for (int i = 0; i < n; i++) {
			map[i][j] = v[idx];
			if (idx == v.size() - 1) {
				break;
			}
			idx++;
		}
	}
}

void solve() {

	for (int i = 0; i < 5; i++) {
		//	output();
		if (dir[i] == 1) {
			up();
		}
		else if (dir[i] == 2) {
			down();
		}
		else if (dir[i] == 3) {
			left();
		}
		else if (dir[i] == 4) {
			right();
		}
	}
}
void permutation(int pos, int cnt) {

	if (pos == cnt) {
		//for (int i = 0; i < 5; i++) {
		//	cout << dir[i] << " ";
		//}
		//cout << "\n";
		copy();
		solve();
		return;
	}

	for (int i = 1; i <= 4; i++) {
		dir[pos] = i;
		permutation(pos + 1, cnt);
	}
}
void solution() {

	permutation(0, 5);
	cout << ans;
}
void input() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input_map[i][j];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
	//	copy();
	//	up();
	//	output();
}