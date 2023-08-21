#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n; //LED�� ǥ���� ��
int t; //��ư�� ���� �� �ִ� �ִ� Ƚ��
int g; //Ż���� ���� �Ȱ��� ������ �ϴ� ��
int cnt = 0;
int ans = 9999999;
int dp[99999];

void bfs() {

	queue<pair<int, int>> q;
	q.push({ n, 0 });


	int cnt = 0;
	while (!q.empty()) {

		int num = q.front().first;
		int times = q.front().second;

		q.pop();

		if (num == g) {
			cout << times;
			exit(0);
		}
		else if (times == t) { //���� ��ư�� ���� �� �ִ� �ִ� Ƚ���� �Ѵ´ٸ�
			continue;
		}

		//1�� �����Ѵ�.
		if (num + 1 <= 99999 && times + 1 < dp[num + 1]) {
			dp[num + 1] = times + 1;
			q.push({ num + 1, times + 1 });
		}

		//2�� ������ �� 0�� �ƴ� �ڸ����� ���ڰ� 1 �پ���.
		num *= 2;

		if (num > 99999) {
			continue;
		}
		string tmp_st = to_string(num);

		for (int i = 0; i < tmp_st.size(); i++) {
			if (tmp_st[i] != '0') { //0�� �ƴϸ�
				int tmp_no = tmp_st[i] - '0';

				tmp_no -= 1;
				tmp_st[i] = tmp_no + '0';

				tmp_no = stoi(tmp_st);

				if (tmp_no <= 99999 && times + 1 < dp[tmp_no]) {
					dp[tmp_no] = times + 1;
					q.push({ tmp_no, times + 1 });
				}
				break;
			}
		}
	}
}
void solution() {


	for (int i = 1; i <= 99999; i++) {
		dp[i] = 9999999;
	}

	bfs();

	cout << "ANG";
}

void input() {

	cin >> n >> t >> g;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}