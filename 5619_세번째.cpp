#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int num;

bool compare(string s1, string s2) {
	if (s1.length() !=  s2.length()) {
		return s1.length() < s2.length();
	}
	else {
		return s1 < s2;
	}


}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;

	priority_queue <int> pq;


	for (int i = 0; i < n; i++) {
		cin >> num;
		if (i < 4) {
			pq.push(num);
		}
		else {
			if (!pq.empty()) {
				if (pq.top() > num) {
					pq.pop();
					pq.push(num);
				}
			}			
		}
	}

	vector <int> v;

	
	while (!pq.empty()) {
		v.push_back(pq.top());
		pq.pop();
	}
	
	
	vector <string> vt;

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (i != j) {
				string s = to_string(v[i]);
				string st = to_string(v[j]);
				vt.push_back(s + st);
			}
		}
	}

	sort(vt.begin(), vt.end(), compare);

	cout << vt[2];
	
}