#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m, k;

int arr[21][21];
int dir = 0; //0 = 동, 1 = 남, 2 = 서, 3 = 북
bool clocks = true; // true면 시계방향, false면 반시계방향
int x = 0;
int y = 0;
int nx;
int ny;
int jusawi[6] = { 1, 2, 5, 3, 4, 6 };
int ans = 0;

bool stop = false;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visited[21][21];

int bfs(int x, int y) {

	int k = arr[x][y];
	memset(visited, false, sizeof(visited));
	int ans = 0;
	ans++;

	queue <pair<int, int>> q;

	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m && visited[nx][ny] == false && arr[nx][ny] == k ) {
				q.push({ nx, ny });
				visited[nx][ny] = true;
				ans++;
			}
		}
	}

	return ans;
}
bool move(int x, int y) { //현재 x, y
	
	dir += 4;
	dir %= 4; //나머지로 구함

	nx = x;
	ny = y;

	if (dir == 0) { //동
		ny++;
	}

	else if (dir == 1) { //남
		nx++;
	}

	else if (dir == 2) { //서
		ny--;
	}

	else{ //북
		nx--;
	}

	if (0 <= nx && nx < n && 0 <= ny && ny < m) {
		return true;
	}

	return false;

}
vector<int> rotation(int jusawi[6]) { //주사위 회전

	//빼야할지도 모르는 코드1
	dir += 4; 
	dir %= 4;

	vector<int> tmp;

	if (dir == 0) { //동쪽으로 회전할 때	
		tmp.push_back(jusawi[4]);
		tmp.push_back(jusawi[1]);
		tmp.push_back(jusawi[2]);
		tmp.push_back(jusawi[0]);
		tmp.push_back(jusawi[5]);
		tmp.push_back(jusawi[3]);
	}
	else if (dir == 1) { //남
		tmp.push_back(jusawi[1]);
		tmp.push_back(jusawi[5]);
		tmp.push_back(jusawi[0]);
		tmp.push_back(jusawi[3]);
		tmp.push_back(jusawi[4]);
		tmp.push_back(jusawi[2]);
	}
	
	else if (dir == 2) { //서
		tmp.push_back(jusawi[3]);
		tmp.push_back(jusawi[1]);
		tmp.push_back(jusawi[2]);
		tmp.push_back(jusawi[5]);
		tmp.push_back(jusawi[0]);
		tmp.push_back(jusawi[4]);
	}

	else if (dir == 3) { //북
		tmp.push_back(jusawi[2]);
		tmp.push_back(jusawi[0]);
		tmp.push_back(jusawi[5]);
		tmp.push_back(jusawi[3]);
		tmp.push_back(jusawi[4]);
		tmp.push_back(jusawi[1]);
	}

	return tmp;
}

void input() {
	cin >> n >> m >> k; //세로 크기 >> 가로 크기

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
}


void solution() {

//	cout << "---------------------------------" << "\n";
//	cout << "이동할 방향: " << dir << "\n";
	if (move(x, y)) { //이동방향으로 한 칸 굴러감
		x = nx;
		y = ny;
	}
	else {
		dir += 2;
		move(x, y); //반대방향으로 한칸 굴러가기
		x = nx;
		y = ny;
	}

//	cout << "이동 후 주사위 위치: ";
//	cout << "x: " << x << " " << "y: " << y << "\n";

	int 지도값 = arr[x][y];
//	cout << "지도값: " << 지도값 << "\n";
	
	vector <int> tmp = rotation(jusawi); //주사위 회전

//	cout << "바뀐 주사위 모양: ";
	for (int i = 0; i < tmp.size(); i++) {
		jusawi[i] = tmp[i];
//		cout << jusawi[i] << " "; // 4 2 5 1 6 3 ( 바뀐 주사위 모양 )
	}
//	cout << "\n";

	int 주사위값 = jusawi[5];
//	cout << "주사위 아랫면: " << 주사위값 << "\n";

	if (지도값 > 주사위값) {
		dir -= 1;
		ans += bfs(x, y) * arr[x][y];
//		cout << "bfs: " << bfs(x, y) << "\n";
//		cout << "방향: " << dir << "\n";
	}
	else if (지도값 < 주사위값) {
		dir += 1;
		ans += bfs(x, y) * arr[x][y];
//		cout << "bfs: " << bfs(x, y) << "\n";
//		cout << "방향: " << dir << "\n";
	}
	else {
		ans += bfs(x, y) * arr[x][y];
//		cout << "게임 종료";
	}
}


	/*
	vector <int> tmp = rotation(jusawi); //주사위 회전

	for (int i = 0; i < tmp.size(); i++) {
		jusawi[i] = tmp[i];
		cout << jusawi[i]; // 4 2 5 1 6 3 ( 바뀐 주사위 모양 )
	}

	int bottom = jusawi[5]; //주사위 아랫면

	if (bottom > arr[x][y]) { //만약 주사위 아랫면이 지도보다 더 크다면
		//시계방향으로 이동
		dir += 1; //dir = 1
		
		int nxt = move(dir, x, y).first;
		int 

		int ny = mo
	}
	*/
	
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	for (int i = 0; i < k; i++) {
		solution();
		if (stop) {
			cout <<  ans << "\n";
			break;
		}
	}
	if (!stop) {
		cout << ans << "\n";
	}

	/*
	solution();
	solution();
	solution();
	*/


}