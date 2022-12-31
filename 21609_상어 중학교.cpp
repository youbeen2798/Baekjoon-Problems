#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
int arr[21][21];
bool visited[21][21];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

queue<pair<int, int>> q;
vector<pair<int, int>> max_block_group;
int max_block_muzigae_num = 0;
long score = 0;

void input() {
	cin >> n >> m; //격자 한 변의 크기, 색상의 개수
	//블록은 검은색 블록, 무지개 블록, 일반 블록
	//일반 블록은 M가지 색상이 있고, 색은 M이하의 자연수로 표현

	//검은색 블록은 -1, 무지개 블록은 0
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}


pair<int, int> find_gizun_block(vector <pair<int,int>> v) {

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;

		if (arr[x][y] != 0) {
			return { x,y };
		}
	}

}
void bfs(int x, int y) {

	memset(visited, false, sizeof(visited));

	vector<pair<int, int>> tmp;
	int color = arr[x][y];
	int num = 1;
	int tmp_muzigae_num = 0;

	q.push({ x, y });
	visited[x][y] = true;
	tmp.push_back({ x,y });
	if (arr[x][y] == 0) {
		tmp_muzigae_num++;
	}

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < n && (!visited[nx][ny] && (arr[nx][ny] == 0 || arr[nx][ny] == color))) {
				//방문을 안 하고, 검은색 블록이 아니라면
				q.push({ nx,ny });
				visited[nx][ny] = true;
				tmp.push_back({ nx,ny });
				num++;

				if (arr[nx][ny] == 0) {
					tmp_muzigae_num++;
				}
			}
		}
	}

	//가장 큰 블록 개수라면, 2이상 이라면
	if (num > max_block_group.size() && num >= 2) {
		max_block_group = tmp; //갱신
		max_block_muzigae_num = tmp_muzigae_num;
	}
	else if (num == max_block_group.size() && num >= 2) { //블록 그룹이 여러 개라면
		if (tmp_muzigae_num > max_block_muzigae_num) { //무지개 블록이 더 여러 개라면
			max_block_group = tmp;
			max_block_muzigae_num = tmp_muzigae_num;
		}
		else if (tmp_muzigae_num == max_block_muzigae_num) { //무지개 블록 개수가 같다면
			//무지개 블록의 수도 같다면
			pair<int, int> original = find_gizun_block(max_block_group);
			pair<int, int> now = find_gizun_block(tmp);

			//기준 블록의 행이 더 크다면
			if (now > original) {
				max_block_group = tmp;
			}
		}
	}
}
void find_biggest_block_group() {

	memset(visited, false, sizeof(visited));

	max_block_muzigae_num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (1 <= arr[i][j] && arr[i][j] <= 5 && !visited[i][j]) {
				bfs(i, j);
			}
		}
	}

	//더 이상 기준 블록이 없다면
	if (max_block_group.size() == 0) {
		cout << score;
		exit(0);
	}
}

void one_block_gravity(int x, int y) { //중력 작용

	pair<int, int> p = { -100,-100 };

	for (int i = x + 1; i < n; i++) {
		if (arr[i][y] == -2) { //빈칸이면
			p = { i, y };
		}
		else {
			break;
		}
	}

	if (p.first != -100 && arr[x][y] != -1) { //-1 블록이 아니면
		int num = arr[x][y];
		arr[x][y] = -2; //빈칸으로 만들기
		arr[p.first][p.second] = num; //숫자로 채우기
	}
}

void rotate() {
	int arr2[100][100];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr2[i][j] = arr[j][abs(n - 1 - i)];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = arr2[i][j];
		}
	}
}
void gravity() { //중력 작용

	for (int j = 0; j < n; j++) { //행
		for (int i = n - 1; i >= 0; i--) {
			one_block_gravity(i, j);
		}
	}
}

void erase() {
	for (int i = 0; i < max_block_group.size(); i++) {
		arr[max_block_group[i].first][max_block_group[i].second] = -2; //제거
	}

	score += max_block_group.size() * max_block_group.size();

}
void solution() {
	//블록 그룹(연결된 블록의 집합 - 일반 블록 1개 이상, 
	//검은색 블록은 포함하면 안 되고, 
	//무지개 블록은 얼마 들어 있든 상관 없음
	//그룹에 속한 블록의 개수는 2보다 크거나 같아야 하며, 
	//기준 블록은 무지개 블록이 아닌 블록에서 행의 번호가 가장 작은 블록, 열의 번호가 가장 작은 블록

	while (true) {
		max_block_group.clear();
		find_biggest_block_group();
		erase();
		gravity();
		rotate();
		gravity();
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}
