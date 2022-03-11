#include <iostream>
#include <queue>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int, vector<int>, greater<int>> pq; //�ּ� �� ����

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;

		if (input > 0) {
			pq.push(input);
		}
		else if(input == 0){
			if (pq.empty()) { //ť�� �������
				cout << "0" << "\n";
			}
			else {
				cout << pq.top() <<"\n"; //ť�� �� ��(���� ����) ���� ��ȯ
				pq.pop(); // ť �� �� ���� ����
			}
		}
	}


}