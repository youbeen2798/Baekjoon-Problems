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
			string k = st.substr(i, j); //substr�� ù��° ���ڴ� ���� ��ġ, �ι�° ���ڴ� ����
			uset.insert(k); //unordered_set�� ���� �߰��ϱ�
		}
	}
	cout << uset.size();
}

