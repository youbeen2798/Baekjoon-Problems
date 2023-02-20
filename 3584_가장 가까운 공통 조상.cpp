#include <iostream>
#include <vector>

using namespace std;

int t; //테스트 케이스 개수

int v[10001];

int num;

int idx;
int node1;
int node2;

vector<int> parents[2];

void bfs(int num) {

	parents[idx].push_back(num);

	while (true) {
		int parent_node = v[num];
		if (parent_node == 0) {
			break;
		}
		parents[idx].push_back(parent_node);
		num = parent_node; 
	}
}

void reset() {

	parents[0].clear();
	parents[1].clear();
	memset(v, 0, sizeof(v));
}

void find_ans() {
	for (int i = 0; i < parents[0].size(); i++) {
		int num1 = parents[0][i];

		for (int j = 0; j < parents[1].size(); j++) {
			int num2 = parents[1][j];

			if (num1 == num2) {
				cout << num1 << "\n";
				return;
			}
		}
	}
}
void solution() {

	idx = 0;
	int num = node1;
	bfs(num);


	idx++;
	num = node2;
	bfs(num);

	find_ans();
	
	reset();
}
void input() {

	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n;
		cin >> n;
		for (int i = 1; i < n; i++) {
			int parent, child;
			cin >> parent >> child;
			v[child] = parent;
		}
		cin >> node1 >> node2;
		
		solution();
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
}