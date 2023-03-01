#include <iostream>
#include <vector>

using namespace std;

int n;
int restaurant_x; //식당 위치 행
int restaurant_y; //식당 위치 열

struct info {
	int x;
	int y;
	long long dist;
};

vector<info> v;

int dx[5] = { 1,-1,0,0,0 };
int dy[5] = { 0,0,1,-1,0 };
long long ans = 99999999999999;

void restaurant_to_people(int x, int y) {
	//식당에서 첫 번째 손님까지 거리

	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx <= 100000 && 0 <= ny && ny <= 100000) {
			int dist = abs(restaurant_x - nx) + abs(restaurant_y - ny);
			v.push_back({ nx,ny, dist });
		}
	}
}

void people_to_people(int x, int y) {

	vector<info> new_v;

	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		long long dist = 99999999999999;

		if (1 <= nx && nx <= 100000 && 1 <= ny && ny <= 100000) {
			for (int j = 0; j < v.size(); j++) {
				int before_x = v[j].x;
				int before_y = v[j].y;
				long long before_dist = v[j].dist;

				long long next_dist = abs(nx - before_x) + abs(ny - before_y);

				long long total_dist = before_dist + next_dist;

				if (total_dist < dist) {
					dist = total_dist;
				}
			}
			new_v.push_back({ nx,ny, dist });
		}
	}

	v = new_v;
}


void output() {

	for (int i = 0; i < v.size(); i++) {
		if (v[i].dist < ans) {
			ans = v[i].dist;
		}
	}
	cout << ans;
}
void input() {
	cin >> n;

	cin >> restaurant_x >> restaurant_y;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		if (i == 0) {
			restaurant_to_people(x, y);
		}
		else {
			people_to_people(x, y);
		}
	}

	output();

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
}