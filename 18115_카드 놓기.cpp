#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int n;
deque <int> dq;
vector <int> v;
void solution() {
	for (int i = v.size() - 1, num = 1; i >= 0; i--, num++) {
		if (v[i] == 1) { //제일 위부터라면
			dq.push_front(num);
		}
		else if (v[i] == 2) {
			int tmp = dq.front();
			dq.pop_front(); //가장 위에 있는 원소 제거
			dq.push_front(num);
			dq.push_front(tmp);
		}
		else{
			dq.push_back(num);
		}
	}
}
void input() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();

	deque<int>::iterator iter;

	for (iter =dq.begin(); iter != dq.end(); iter++) {
		cout << *iter << " ";
	}
}