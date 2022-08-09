#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

bool compare(string st1, string st2) {

	return st1.size() < st2.size();

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	vector <string> v;

	for (int i = 0; i < n; i++) {
		string st;
		cin >> st;
		v.push_back(st);
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {

		string st = v[i]; //  st = 'h';
		int size = v[i].size(); //  size = 1;

		for (int j = i + 1; j < v.size(); j++) {
			string st2 = v[j];
			if (st2.substr(0, size) == st) {
				v.erase(v.begin() + i); 
				i--;
				break;
			}
		}
	} 

	cout << v.size();

}