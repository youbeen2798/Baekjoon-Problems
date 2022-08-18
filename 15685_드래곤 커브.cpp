#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n;

vector <pair<int, int>> v;

set <pair<int, int>> s;

void solve() {

	pair<int, int> a = v[v.size() - 1];

	int size = v.size() - 1;

	for (int i = size - 1; i >= 0; i--) {
		int dy = -1 * (a.first - v[i].first);
		int dx = a.second - v[i].second;

		v.push_back({ a.first + dx, a.second + dy });
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		v.clear();
		int x1;
		int y1;
		int direction;
		int num;

		cin >> x1 >> y1 >> direction >> num;
		v.push_back({ x1,y1 }); //x좌표 y좌표

		if (direction == 0) {
			v.push_back({ x1 + 1, y1 }); //오른쪽
		}
		else if (direction == 1) {
			v.push_back({ x1,y1 - 1 }); //위쪽
		}
		else if (direction == 2) {
			v.push_back({ x1 - 1, y1 }); //왼쪽
		}
		else if (direction == 3) {
			v.push_back({ x1,y1 + 1 }); //아래쪽
		}

		for (int j = 0; j < num; j++) {
			solve();
		}

		for (int i = 0; i < v.size(); i++) {
			s.insert({ v[i].first, v[i].second });
		}

	}

	int answer = 0;

	//가로가 1일 때
	
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (s.find({ i,j }) != s.end()) {
				if (s.find({ i,j + 1}) != s.end()) {
					if (s.find({ i + 1, j }) != s.end()) {
						if (s.find({ i + 1, j + 1 }) != s.end()) {
							answer++;
						}
					}
				}
			}
		}
	}

	cout << answer;
	
}