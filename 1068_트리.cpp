#include <iostream>
#include <vector>

using namespace std;

int n;
int root_node;
int erase_node;
vector<int> children_node[51];

int dfs(int node) {

	int size = children_node[node].size(); //�ڽ� ����
	int ret = 0;

	for (int i = size - 1; i >= 0; i--) {
		if (children_node[node][i] == erase_node) {
			//���� �ڽ� ��尡 ������ �� �����
			size--; 
		}
		else {
			ret += dfs(children_node[node][i]);
		}
	}


	if (size == 0) { //�ڽ� ��尡 �ƿ� ���ٸ�
		return 1;
	}
	return ret;
}

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num == -1) {
			root_node = i;
		}
		else {
			children_node[num].push_back(i);
		}
	}

	cin >> erase_node;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	input();

	if (erase_node == root_node) {
		return 0;
	}
	
	cout << dfs(root_node);
	
}