#include <iostream>

using namespace std;

string st;
int arr[26];
char ans[51];

void solution() {

	for (int i = 0; i < st.size(); i++) {
		int num = st[i] - 'A';
		arr[num]++;
	}

	int start = 0;
	int en = st.size() - 1;
	int mid = -1;

	//만약 st.size()가 홀수라면 중간에 하나 더 놓는것이 가능
	if (st.size() % 2 == 1) {
		mid = st.size() / 2;
	}


	for (int i = 0; i < 26; i++) {
		char c = i + 'A';
		if (arr[i] % 2 == 0) {
			int k = arr[i] / 2;
			for (int t = 0; t < k; t++) {
				ans[start++] = c;
				ans[en--] = c;
			}
		}
		else if(mid != -1) {
			int k = arr[i] / 2;
			for (int t = 0; t < k; t++) {
				ans[start++] = c;
				ans[en--] = c;
			}
			ans[mid] = c;
			mid = -1;
		}
		else {
			cout << "I'm Sorry Hansoo";
			exit(0);
		}
//		cout << "i: " << i << " arr[i]: " << arr[i] << "\n";
	}

//	cout << "########" << "\n";
	for (int i = 0; i < st.size(); i++) {
		cout << ans[i];
	}
}

void input() {
	cin >> st;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}