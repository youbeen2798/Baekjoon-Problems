#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int r, c, k;
int arr[101][101];
int row = 3; //행 개수
int col = 3; //열 개수

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

void tmp_sort(vector<int> tmp, bool is_row, int num) { //정렬
	map<int, int> m;

	for (int i = 0; i < tmp.size(); i++) {
		if (m.find(tmp[i]) == m.end()) {
			m.insert({ tmp[i], 1 });
			continue;
		}
		m[tmp[i]]++;
	}

	//map을 정렬하기 위해 벡터로 바꿈
	vector<pair<int, int>> v(m.begin(), m.end());

	//정렬
	sort(v.begin(), v.end(), comp);

	//만약 크기가 100을 넘어 가는 경우(pair이므로 100/20 = 50)
	if (v.size() > 50) {
		//0~49 인덱스만 취급
		vector<pair<int, int>> slice(v.begin(), v.begin() + 50);
		v.clear();
		for (int i = 0; i < slice.size(); i++) {
			v[i].first = slice[i].first;
			v[i].second = slice[i].second;
		}
	}
	int size = v.size() * 2;
	if (is_row) { //행 정렬이면
		col = max(size, col); //열 크기 갱신
		for (int i = 0; i < 100; i++) {
			//행 모두 0으로 채우기
			arr[num][i] = 0;
		}
		for (int i = 0; i < v.size(); i++) {
			arr[num][i * 2] = v[i].first;
			arr[num][i * 2 + 1] = v[i].second;
		}
		return;
	}
	//열 정렬이면
	row = max(size, row); //행 크기 갱신
	for (int i = 0; i < 100; i++) {
		//열 모두 0으로 채우기
		arr[i][num] = 0;
	}
	for (int i = 0; i < v.size(); i++) {
		arr[i * 2][num] = v[i].first;
		arr[i * 2 + 1][num] = v[i].second;
	}
}

bool check() {
	//0부터 넣으므로 r 대신 r - 1
	if (arr[r - 1][c - 1] == k) {
		return true;
	}
	return false;
}
void solution() {

	for (int test = 0; test <=  100; test++) {
		if (check()) {
			cout << test;
			exit(0);
		}
		if (row >= col) { //행 개수가 더 크다면
			for (int i = 0; i < row; i++) {
				vector<int> tmp;
				for (int j = 0; j < col; j++) {
					if (arr[i][j] != 0) { //0은 제외
						tmp.push_back(arr[i][j]);
					}
				}
				tmp_sort(tmp, true, i);
			}
		}
		else { //열 개수가 더 크다면
			for (int i = 0; i < col; i++) {
				vector<int> tmp;
				for (int j = 0; j < row; j++) {
					if (arr[j][i] != 0) {
						tmp.push_back(arr[j][i]);
					}
				}
				tmp_sort(tmp, false, i);
			}
		}
	}
	cout << -1; //100초 안에 못 시행한다면
}

void input() {
	cin >> r >> c >> k;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}