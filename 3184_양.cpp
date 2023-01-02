#include <iostream>
#include <queue>
using namespace std;

int r, c;
char arr[251][251];
bool visited[251][251];
queue <pair<int, int>> q;
vector <pair<int, int>> wolves;
vector<pair<int, int>> sheep;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void input() {
	cin >> r >> c; //행 수, 열 수

	//'.'(점)은 빈 필드, '#'는 울타리, 'O'는 양, 'V'는 늑대
	for (int i = 0; i < r; i++) {
		string st;
		cin >> st;
		
		for (int j = 0; j < c; j++) {
			arr[i][j] = st[j];
		}
	}
}

bool inrange(int x, int y) {
	if (0 <= x && x < r && 0 <= y && y < c) {
		return true;
	}
	return false;
}

void bfs(int x, int y) {
	wolves.clear();
	sheep.clear();

	q.push({ x, y });
	visited[x][y] = true;

	if (arr[x][y] == 'v') {
		wolves.push_back({ x, y });
	}
	else if (arr[x][y] == 'o') {
		sheep.push_back({ x, y });
	}

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			//위치 속에 들어 있으면서 방문하지 않았으면서 늑대라면
			if (inrange(nx,ny) && !visited[nx][ny] && arr[nx][ny] != '#') {
				q.push({ nx, ny });
				visited[nx][ny] = true;

				if (arr[nx][ny] == 'v') {
					wolves.push_back({ nx,ny });
				}
				else if (arr[nx][ny] == 'o') {
					sheep.push_back({ nx,ny });
				}
			} 
		}
	}

//	cout << "sheep.size: " << sheep.size() << "\n";
//	cout << "wolves.size: " << wolves.size() << "\n";

	if (sheep.size() > wolves.size()) { //양의 수가 더 많다면
		for (int i = 0; i < wolves.size(); i++) {
			arr[wolves[i].first][wolves[i].second] = '.';
		}
	}
	else {
		for (int i = 0; i < sheep.size(); i++) { //늑대 수가 더 많다면
			arr[sheep[i].first][sheep[i].second] = '.';
		}
	}
}
void solution() {

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if ((arr[i][j] == 'v' || arr[i][j] == 'o') && !visited[i][j]) {
				//늑대혹은 양이 아직 방문하지 않았다면
				bfs(i, j);
			}
		}
	}

	int result_wolf_num = 0; 
	int result_sheep_num = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'v') {
				result_wolf_num++;
			}
			else if (arr[i][j] == 'o') {
				result_sheep_num++;
			}
		}
	}

	cout << result_sheep_num << " " << result_wolf_num;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}