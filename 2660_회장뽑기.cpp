#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <algorithm>

using namespace std;

int n;

vector <int> v[51];
queue <pair<int,int>> q;
bool visited[51];
int min_output = 1000;

void input() {
	cin >> n;
	
	while (true) {
		int a, b;
		cin >> a >> b;

		if (a == -1 && b == -1) {
			break;
		}
		v[a].push_back(b);
		v[b].push_back(a);
	}
}

int bfs(int start) {

	visited[start] = true;
	q.push({ start, 0 });
	int output = 0;

	while (!q.empty()) {
		int a = q.front().first;
		int dist = q.front().second;

		q.pop();

		for (int i = 0; i < v[a].size(); i++) {
			if (!visited[v[a][i]]) {
				q.push({ v[a][i], dist + 1 });
				visited[v[a][i]] = true;
				output = max(output, dist + 1);
			}
		}
	}
	return output;
}
void solution() {

	vector <int> answers;

	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		int output = bfs(i);
//		cout << "i: " << i << " output: " << output << "\n";
		if (output < min_output) {
			min_output = output;
			answers.clear();
			answers.push_back(i);
		}
		else if (output == min_output) {
			answers.push_back(i);
		}
	}
	cout << min_output << " " << answers.size() << "\n";

	sort(answers.begin(), answers.end());

	for (int i = 0; i < answers.size(); i++) {
		cout << answers[i] << " ";
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}