#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

string st;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> st;

	unordered_set <string> uset;
	for (int i = 0; i < st.size(); i++) {
		for (int j = 1; j <= st.size() - i; j++) {
			string k = st.substr(i, j); //substr의 첫번째 인자는 시작 위치, 두번째 인자는 개수
			uset.insert(k); //unordered_set에 원소 추가하기
		}
	}
	cout << uset.size();
}

