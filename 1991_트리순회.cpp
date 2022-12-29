#include <iostream>
#include <queue>
using namespace std;

int n;
pair<char, char> node[200];
char parent_node[200];
queue<char> q;
bool visited[200];

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		char mid, left, right;
		cin >> mid >> left >> right;
		node[mid].first = left;
		node[mid].second = right;
		parent_node[left] = mid;
		parent_node[right] = mid;
	}
}

void pre_bfs(char start) {

	q.push(start);
	
	while (!q.empty()) {
		int a = q.front();
		char c = q.front();
		q.pop();
		
		//�ڱ� �ڽ��� ���� ��µ��� �ʾ�����
		if (!visited[c]) {
			visited[c] = true;
			cout << c;
		}

		if (node[a].first != '.' && !visited[node[a].first]) {
			q.push(node[a].first);
			continue;
		}
		if (node[a].second != '.' && !visited[node[a].second]) {
			q.push(node[a].second);
			continue;
		}

		if (c != 'A') {
			q.push(parent_node[c]);
		}
	}
	cout << "\n";
}

char most_left(char start) {
	char ans = start;
	q.push(start);
	
	while (!q.empty()) {
		int a = q.front();
		ans = q.front();
		q.pop();

		//���� �ڽ��� ������
		if (node[a].first != '.') {
			q.push(node[a].first);
		}
	}

	return ans; 

}
void mid_bfs(char start) {
	memset(visited, false, sizeof(visited));

	q.push(start);

	while (!q.empty()) {
		int a = q.front();
		char c = q.front();
		q.pop();

		if (node[c].first != '.' && !visited[node[c].first]) {
			//���� ��尡 ������
			q.push(node[c].first);
			continue;
		}
		else {
			//���� ��尡 ������
			if (!visited[c]) {
				cout << c;
				visited[c] = true;
			}
		}

		//������ ��� Ȯ��
		if (node[c].second != '.' && !visited[node[c].second]) {
			q.push(node[c].second);
			continue;
		}
		if (c != 'A') {
			q.push(parent_node[c]);
		}
	}
	cout << "\n";
}
	
void post_bfs(char start) {
	memset(visited, false, sizeof(visited));

	q.push(start);

	while (!q.empty()) {
		int a = q.front();
		char c = q.front();
		q.pop();

		//���� ��尡 ������
		if (node[a].first != '.' && !visited[node[a].first]) {
			q.push(node[a].first);
			continue;
		}
		//������ ��尡 ������
		if (node[a].second != '.' && !visited[node[a].second]) {
			q.push(node[a].second);
			continue;
		}

		//�ڱ� �ڽ� ���
		cout << c;
		visited[c] = true;

		//�θ� ��尡 ������
		if (c != 'A' && !visited[parent_node[c]]) {
			q.push(parent_node[c]);
		}
	}
}
void solution() {

	pre_bfs('A');
//	cout << most_left('A');
	mid_bfs(most_left('A'));
	post_bfs(most_left('A'));
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}

/*
10
A B C
B D E
C F G
D . .
E . .
F H I
G J .
H . .
I . .
J . .
*/