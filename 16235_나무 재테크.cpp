#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int m;
int k;
int arr[11][11];
int nutrient[11][11];
vector<int> tree[11][11];

int dx[8] = { 1, -1, 0, 0,   1, 1, -1, -1};
int dy[8] = { 0, 0,  1, -1, -1, 1, -1,  1};

void spring() {
	//나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다.

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sort(tree[i][j].begin(), tree[i][j].end());
			for (int k = 0; k < tree[i][j].size(); k++) {
				//나머지 양분
				int now_tree_age = tree[i][j][k];
				int namuzi_nutrient = arr[i][j] - now_tree_age;
				if (namuzi_nutrient < 0) {
					//양분이 부족하다면
					tree[i][j][k] *= -1; //죽는다.
				}
				else {
					//양분이 부족하지 않다면 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다.
					arr[i][j] = namuzi_nutrient;
					tree[i][j][k] += 1; 
				}		
			}
		}
	}
}

void summer() {
	//봄에 죽은 나무가 양분으로 변하게 된다. 
	//각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다. 
	//소수점 아래는 버린다.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sort(tree[i][j].rbegin(), tree[i][j].rend());

			int size = tree[i][j].size();
			for (int k = size - 1; k >= 0; k--) {
				//만약 봄에 죽은 나무라면
				if (tree[i][j][k] < 0) {
					//2로 나눈 값이 나무가 있던 
					int dividebytwo = (-1 * tree[i][j][k]) / 2;
					arr[i][j] += dividebytwo;
					tree[i][j].pop_back();
				}
			}
		}
	}

}

void authum() {
	//번식하는 나무는 나이가 5의 배수이어야 하며, 
	//인접한 8개의 칸에 나이가 1인 나무가 생긴다. 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < tree[i][j].size(); k++) {
				int tree_age = tree[i][j][k];

				if (tree_age % 5 == 0) {
					//만약 5의 배수라면
					for (int k = 0; k < 8; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (1 <= nx && nx <= n && 1 <= ny && ny <= n) {
							tree[nx][ny].push_back(1);
						}
					}
				}
			}
		}
	}
}

void winter() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] += nutrient[i][j];
		}
	}
}
void solution() {

	for (int i = 1; i <= k; i++) {
		spring();
		summer();
		authum();
		winter();
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += tree[i][j].size();
		}
	}

	cout << ans;
}
void input() {

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = 5;
			cin >> nutrient[i][j];
		}
	}


	for (int i = 0; i < m; i++) {
		int x, y, z; //나무 위치: (x,y), 나이: z
		cin >> x >> y >> z;
		tree[x][y].push_back(z);
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}