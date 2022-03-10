#include <iostream>
#include <deque>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false); // cin cout 속도 빠르게
	cin.tie(NULL);
	cout.tie(NULL);

	deque <int> dq;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;

		if (input == "push_front") {
			int n;
			cin >> n;
			dq.push_front(n); // 제일 앞에 원소 추가
		}
		else if (input == "push_back") {
			int n;
			cin >> n;
			dq.push_back(n); //제일 뒤에 원소 추가
		}
		else if (input == "pop_front") {
			if (dq.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << dq.front() << "\n";
				dq.pop_front(); // 제일 앞 원소 삭제
			}
		}
		else if (input == "pop_back") {
			if (dq.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << dq.back() << "\n";
				dq.pop_back(); //제일 뒤 원소 삭제
			}
		}
		else if (input == "size") {
			cout << dq.size() << "\n";
		}
		else if (input == "empty") {
			if (dq.empty()) {
				cout << "1" << "\n";
			}
			else {
				cout << "0" << "\n";
			}
		}
		else if (input == "front") {
			if (dq.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << dq.front() << "\n"; //제일 앞 원소 반환
			}
		}
		else if (input == "back") {
			if (dq.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << dq.back() << "\n"; //제일 뒤 원소 반환
			}
		}



	}
}
