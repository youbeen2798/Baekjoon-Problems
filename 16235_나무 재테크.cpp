#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int n; //배열 크기
int m; //나무 개수
int k;
int plus_arr[11][11]; //겨울마다 추가되는 양분
int arr[11][11]; //제일 처음에 양분
vector<int> trees[11][11]; //나이
int x, y, z; //(x,y) - 나무위치, z - 나무 나이

int sping_dead_tree_eat[11][11]; //죽은 나무가 남긴 양분

int dx[8] = { -1,-1,-1,0,0,1,1, 1 };
int dy[8] = { -1,0,1,-1,1,-1,0, 1 };

void spring() {
	//봄
	//나무가 자신의 나이만큼 양분을 먹고, 1 증가
	//하나의 칸에 여러 개의 나무가 있으면 나이거 어린 나무부터 양분을 먹는다.
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sort(trees[i][j].begin(), trees[i][j].end());
			int size = trees[i][j].size(); //size를 변수처리하는게 시간 초과에 좋음
			for (int k = 0; k < size; k++) {
				//나무의 개수만큼
				int age = trees[i][j][k]; //나무의 나이 
				if (arr[i][j] >= age) { //양분을 먹을 수 있다면 먹고
					trees[i][j][k]++; //나이 1증가
					arr[i][j] -= age;
					continue;
				}
				//아님 즉시 죽는다.
				trees[i][j][k] *= -1;
			}
		}
	}
}

void summer() {
	//봄에 죽은 나무가 양분으로 변하게 된다.
	//각각의 죽은 나무마다 나이를 2로 남은 값이 나무에 있던 칸에 양분으로 추가된다.

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = trees[i][j].size() - 1; k >= 0; k--) {
				if (trees[i][j][k] < 0) { //죽은 나무이면
					arr[i][j] -= trees[i][j][k] / 2; //  양분 추가
					trees[i][j].pop_back();
				}
			}
		}
	}
}

void fall() {
	//나무가 번식한다.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < trees[i][j].size(); k++) {
				int age = trees[i][j][k]; //나무 나이
				if (age % 5 == 0) { //나기가 5의 배수이면
					for (int t = 0; t < 8; t++) {
						//인접한 8개 칸에 나이가 1인 나무가 생긴다.
						int nx = i + dx[t];
						int ny = j + dy[t];
						if (1 <= nx && nx <= n && 1 <= ny && ny <= n) {
							trees[nx][ny].push_back(1);
						}
					}
				}
			}
		}
	}
}

void winter() {
	//양분을 추가한다.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] += plus_arr[i][j];
		}
	}
}

void solution() {

	for (int i = 0; i < k; i++) {
		spring(); //봄
		summer(); //여름
		fall(); //가을
		winter(); //겨울
	}


	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += trees[i][j].size();
		}
	}
	cout << ans;

}
void input() {
	
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = 5; //제일 처음에 양분은 5
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> plus_arr[i][j]; //칸에 추가하는 양분
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		trees[x][y].push_back(z); //(x,y)에 나이가 z인 나무가 있음
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}