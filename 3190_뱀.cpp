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
			//�Ӹ� �߰�
			if (direction == -1) {
				direction = 3;
			}
			else if (direction == 4) {
				direction = 0;
			}

			if (direction == 0) { //���������� �̵�
				int nx = snake.back().first;
				int ny = snake.back().second + 1;
				if (snakeposition.find({nx,ny}) != snakeposition.end()) {
					cout << time << "\n";
					break;
				}
				snake.push_back({nx,ny});
				snakeposition.insert({nx,ny});
			}
			else if (direction == 1) { //�Ʒ��� �̵�
				int nx = snake.back().first + 1;
				int ny = snake.back().second;
				if (snakeposition.find({ nx,ny }) != snakeposition.end()) {
					cout << time << "\n";
					break;
				}
				snake.push_back({nx,ny});
				snakeposition.insert({nx,ny });
			}
			else if (direction == 2) { //�������� �̵�
				int nx = snake.back().first;
				int ny = snake.back().second - 1;

				if (snakeposition.find({ nx,ny }) != snakeposition.end()) {
					cout << time << "\n";
//					cout << "*** ���� �� ��ġ��ü" << "\n";

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
			else if (direction == 3) { //���� �̵�
				int nx = snake.back().first - 1;
				int ny = snake.back().second;
				if (snakeposition.find({ nx,ny }) != snakeposition.end()) {
					cout << time << "\n";
					break;
				}
				snake.push_back({nx,ny });
				snakeposition.insert({ nx,ny});
			}

			//���� ���� ���� ����(����� ������, �� ����, ����� ������ ��)
			if (apple.find({ snake.back().first, snake.back().second }) == apple.end()) { //����� ������
//				cout << snake[0].first << " " << snake[0].second << "����" << "\n";
				snakeposition.erase({ snake[0].first, snake[0].second });
				snake.erase(snake.begin());
			}
			else {
				apple.erase({ snake.back().first, snake.back().second });
			}

			//���� �ٲ��� �ȹٲ��� ����
			if (directionChange.find(time) != directionChange.end()) {
				if (directionChange[time] == 'D') { //���������� �̵�
					direction++;
				}
				else { //�������� �̵�
					direction--;
				}
			}
//			cout << "***" << "\n";
//			cout << snake.back().first << " " << snake.back().second << "\n";
			cout << "*****" << "\n";
			cout << "time: " << time << "\n";
			cout << "snakeposition ũ��: " << snakeposition.size() << "\n";
			cout << "�� ��ġ" << "\n";
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