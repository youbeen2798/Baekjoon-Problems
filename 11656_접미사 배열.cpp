#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string st;
string s;

vector <string> v;

//사전순으로 정렬
bool compare(const string& s1, const string& s2) {

	return s1 < s2;

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> st;

	for (int i = 0; i < st.size(); i++) {
		s = st;
		v.push_back(s.substr(i));
	}


	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}