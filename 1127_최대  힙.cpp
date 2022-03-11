#include <iostream>
#include <queue>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false); //����� ������
	cin.tie(0);
	cout.tie(0);

	priority_queue<int, vector<int>> q; //�켱���� ť ����

	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		long long input;
		cin >> input;

		if (input > 0) {
			q.push(input); //���� ����
		}
		else if(input ==0) {
			if (q.empty()) { //ť�� ���������
				cout << "0" << "\n";
			}
			else {
				cout << q.top() << "\n"; //�� �� ���� ��ȯ
				q.pop(); //�� �� ���� ���� 
			}
		}
	}

}