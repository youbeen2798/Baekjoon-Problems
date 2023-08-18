#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n; //구역 수
int people[11]; //인구 수
bool connected[11][11];
bool selected[11];
bool visited[11];

vector<int> population;
int ans = 99999999;

void bfs(int num) {
	//만약 1개 도시라면 true 리턴

	int people_sum = 0;

	queue<int> q;

	q.push(num);
	visited[num] = true;


	while (!q.empty()) {
		int a = q.front();
		people_sum += people[a];
		
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (!visited[i] && connected[a][i] && selected[i] == selected[a]) {
				visited[i] = true;
				q.push(i);
			}
		}
	}

	population.push_back(people_sum); 
}
void check() {

	population.clear();
	memset(visited, false, sizeof(visited));

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			bfs(i);
		}
	}
	
	if (population.size() == 2) {
		int tmp_ans = abs(population[0] - population[1]);
		ans = min(ans, tmp_ans);
	}
}
void makesubset(int cnt) {

	if (cnt == n) {
		check();
		return;
	}

	selected[cnt] = true;
	makesubset(cnt + 1);

	selected[cnt] = false;
	makesubset(cnt + 1);
}
void solution() {

	makesubset(0);

	if (ans == 99999999) {
		cout << -1;
	}
	else {
		cout << ans;
	}
}

void input() {

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> people[i];
	}

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;

		for (int j = 0; j < num; j++) {
			int num2;
			cin >> num2;
			connected[i][num2] = true;
			connected[num2][i] = true;
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