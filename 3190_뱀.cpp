#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

int n, k, l;
int direction = 0;
set <pair< int, int >> apple;
map<int,char> directionChange;

vector <pair<int, int>> snake; 
set <pair<int, int>> snakeposition;

void input() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		apple.insert({ x,y });
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int num;
		char c;
		cin >> num >> c;
		directionChange.insert({ num,c });
	}

	snake.push_back({ 1,1 });
	snakeposition.insert({ 1,1 });
}

void solution() {

	int r = 5;
	for(int time = 1;; time++){
		if (snake.back().first < 1 || snake.back().first > n || snake.back().second < 1 || snake.back().second > n) {
			time--;
			cout << time << "\n";
			break;
		}
//		else if (snakeposition.find({snake.back().first, snake.back().second})!= snakeposition.end()) {
//			time--;
//			cout << time << "\n";
//			break;
//		}
		else {
			//머리 추가
			if (direction == -1) {
				direction = 3;
			}
			else if (direction == 4) {
				direction = 0;
			}

			if (direction == 0) { //오른쪽으로 이동
				int nx = snake.back().first;
				int ny = snake.back().second + 1;
				if (snakeposition.find({nx,ny}) != snakeposition.end()) {
					cout << time << "\n";
					break;
				}
				snake.push_back({nx,ny});
				snakeposition.insert({nx,ny});
			}
			else if (direction == 1) { //아래로 이동
				int nx = snake.back().first + 1;
				int ny = snake.back().second;
				if (snakeposition.find({ nx,ny }) != snakeposition.end()) {
					cout << time << "\n";
					break;
				}
				snake.push_back({nx,ny});
				snakeposition.insert({nx,ny });
			}
			else if (direction == 2) { //왼쪽으로 이동
				int nx = snake.back().first;
				int ny = snake.back().second - 1;

				if (snakeposition.find({ nx,ny }) != snakeposition.end()) {
					cout << time << "\n";
//					cout << "*** 현재 뱀 위치전체" << "\n";

//					for (auto i : snakeposition) {
//						cout << i.first << " " << i.second << "\n";
//					}

//					cout << "nx: " << nx << " ny: " << ny << "\n";
//					cout << time << "\n";
					break;
				}
				snake.push_back({nx,ny});
				snakeposition.insert({nx,ny});
			}
			else if (direction == 3) { //위로 이동
				int nx = snake.back().first - 1;
				int ny = snake.back().second;
				if (snakeposition.find({ nx,ny }) != snakeposition.end()) {
					cout << time << "\n";
					break;
				}
				snake.push_back({nx,ny });
				snakeposition.insert({ nx,ny});
			}

			//꼬리 뺄지 말지 결정(사과가 있으면, 안 빼고, 사과가 없으면 뺌)
			if (apple.find({ snake.back().first, snake.back().second }) == apple.end()) { //사과가 없으면
//				cout << snake[0].first << " " << snake[0].second << "삭제" << "\n";
				snakeposition.erase({ snake[0].first, snake[0].second });
				snake.erase(snake.begin());
			}
			else {
				apple.erase({ snake.back().first, snake.back().second });
			}

			//방향 바꿀지 안바꿀지 결정
			if (directionChange.find(time) != directionChange.end()) {
				if (directionChange[time] == 'D') { //오른쪽으로 이동
					direction++;
				}
				else { //왼쪽으로 이동
					direction--;
				}
			}
//			cout << "***" << "\n";
//			cout << snake.back().first << " " << snake.back().second << "\n";
			cout << "*****" << "\n";
			cout << "time: " << time << "\n";
			cout << "snakeposition 크기: " << snakeposition.size() << "\n";
			cout << "뱀 위치" << "\n";
			for (auto i : snakeposition) {
				cout << i.first << " " << i.second << "\n";
			}
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