#include <iostream>
#include <string>
#include <vector>
using namespace std;

int T;
int x, y;

pair<int,int>  mode(int now, char s, int x, int y) {
	if (now == 0) {
		if (s == 'F') {
			y++;
			return make_pair(x,y);
		}
		else if (s == 'B') {
			y--;
			return make_pair(x, y);
		}
	}
	else if (now == 1) {
		if (s == 'F') {
			x--;
			return make_pair(x, y);
		}
		else if (s == 'B') {
			x++;
			return make_pair(x, y);
		}
	}
	else if (now == 2) {
		if (s == 'F') {
			y--;
			return make_pair(x, y);
		}
		else if (s == 'B') {
			y++;
			return make_pair(x, y);
		}
	}
	else if (now == 3) {
		if (s == 'F') {
			x++;
			return make_pair(x, y);
		}
		else if (s == 'B') {
			x--;
			return make_pair(x, y);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		string st;
		cin >> st;

		vector <pair<int, int>> vt;

		x = 0;
		y = 0;
		int now = 0;

		int L_count = 0;
		int R_count = 0;

		for (int i = 0; i < st.size(); i++) {
			if (st[i] == 'L') {
				L_count++;
				now = L_count - R_count;

				if (now >= 4) {
					now = now % 4;
				}
				if (now < 0) {
					now = abs(now) % 4;
					if(now > 0)
						now = 4 - now;
				}

				continue;
			}
			else if (st[i] == 'R') {
				R_count++;
				now = L_count - R_count;

				if (now >= 4) {
					now = now % 4;
				}
				if (now < 0) {
					now = abs(now) % 4;
					if(now > 0)
						now = 4 - now;
				}

				continue;
			}
			else if (st[i] == 'F') {
				pair <int, int> a = mode(now, 'F', x, y);
				x = a.first;
				y = a.second;
				vt.push_back(make_pair(x, y));
			}
			else if (st[i] == 'B') {
				pair <int, int> a = mode(now, 'B', x, y);
				x = a.first;
				y = a.second;
				vt.push_back(make_pair(x, y));
			}			
		}

		int mn_x = 0;
		int mx_x = 0;
		int mn_y = 0;
		int mx_y = 0;

		for (int i = 0; i < vt.size(); i++) {
			if (vt[i].first <= mn_x) {
				mn_x = vt[i].first;
			}
			if (vt[i].first >= mx_x) {
				mx_x = vt[i].first;
			}
			if (vt[i].second <= mn_y) {
				mn_y = vt[i].second;
			}
			if (vt[i].second >= mx_y) {
				mx_y = vt[i].second;
			}

		}

		cout <<  (mx_x - mn_x) * (mx_y - mn_y) << "\n";
	}	
}