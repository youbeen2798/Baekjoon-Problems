#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <set>
using namespace std;

int n, m, start_fuel;
int arr[21][21];
int taxi_row; //�ý� ��
int taxi_col; //�ý� ��
vector<pair<int,int>> customers[21][21];
int visited[21][21];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

//���� ��ġ�� ���� ��ġ
void print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
}

pair<int,pair<int,int>> bfs() {
	//���� �� : ���� ����� �մ��� �Ÿ��� ��ġ

	memset(visited, 0, sizeof(visited));
	queue <pair<int,pair<int, int>>> q;
	//�Ÿ��� �°� ��ġ

	vector<pair<int, int>> tmp_customers[1000];
	//�Ÿ��� ��ġ

	q.push({ 0,{ taxi_row, taxi_col } });
	visited[taxi_row][taxi_col] = 1;

	while (!q.empty()) {
		int dist = q.front().first; //�Ÿ�
		int x = q.front().second.first;
		int y = q.front().second.second;

		if (customers[x][y].size() > 0) {
			tmp_customers[dist].push_back({ x,y });
		}
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (1 <= nx && nx <= n && 1 <= ny && ny <= n && visited[nx][ny] == 0 && arr[nx][ny] == 0) {
				q.push({ dist + 1,{ nx,ny } });
				visited[nx][ny] = dist + 1;
			}
		}
	}
	
	for (int i = 0; i < 1000; i++) {
		if (tmp_customers[i].size() > 0) {
			sort(tmp_customers[i].begin(), tmp_customers[i].end(), greater<>());
			int size = tmp_customers[i].size();
			return { i, {tmp_customers[i][size - 1].first, tmp_customers[i][size - 1].second }};
		}
	}

	cout << -1;
	exit(0);
}

int bfs2(int end_x, int end_y) {

	memset(visited, 0, sizeof(visited));

	queue<pair<int, int>> q;
	visited[taxi_row][taxi_col] = 1;
	q.push({ taxi_row, taxi_col });

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		int dist = visited[a][b];

		if (a == end_x && b == end_y) {
			return dist; 
		}
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (1 <= nx && nx <= n && 1 <= ny && ny <= n && visited[nx][ny] == 0 && arr[nx][ny] == 0) {
				q.push({ nx,ny });
				visited[nx][ny] = dist + 1;
			}
		}
	}

	//�������� �� �� ���ٸ�
	cout << -1;
	exit(0);
}
void find_closet_customer() {

	pair<int,pair<int,int>> p = bfs();
	int dist = p.first;
	int customer_x = p.second.first;
	int customer_y = p.second.second;

	if (start_fuel >= dist) {
		start_fuel -= dist; //���� ����
	}
	else {
		cout << -1;
		exit(0);
	}

	//�մ� ������ ��ġ���� ����
	int end_x = customers[customer_x][customer_y].back().first;
	int end_y = customers[customer_x][customer_y].back().second;

	customers[customer_x][customer_y].pop_back();

	//�ý� ��ġ ������
	taxi_row = customer_x;
	taxi_col = customer_y;

	//�մ� ���������� ������ �ֱ�
	int to_end_dist = bfs2(end_x, end_y) - 1;

	if (start_fuel >= to_end_dist) {
		start_fuel -= to_end_dist;
	}
	else {
		cout << -1;
		exit(0); 
	}

	start_fuel += 2 * to_end_dist; //���������� �� �Ÿ� * 2

	//�ý� ��ġ ������
	taxi_row = end_x;
	taxi_col = end_y;
}
void solution() {

	for (int i = 0; i < m; i++) {
		//�ִܰŸ��� ���� ª�� �°��� ���� �̵��Ѵ�.
		find_closet_customer();
	}
	
	cout << start_fuel;
}

void input() {
	cin >> n >> m >> start_fuel;

	//0�� ��ĭ 1�� ��
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> taxi_row >> taxi_col;

	for (int i = 0; i < m; i++) {
		int start_x, start_y, end_x, end_y;
		cin >> start_x >> start_y >> end_x >> end_y;
		customers[start_x][start_y].push_back({ end_x, end_y });
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}