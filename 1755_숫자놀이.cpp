#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int m, n;
//0 - zero
//1 - one
//2 - two
//3 - three
//4 - four
//5 - five
//6 - six
//7 - seven
//8 - eight
//9 - nine
// 8 5 4 9 1 6 7 3 2 0

vector<string> v;

string arr[10] = { "zero", "one", "two", "three", "four", "five", "six",
"seven", "eight", "nine" };

void input() {
	cin >> m >> n;

	for (int i = m; i <= n; i++) {
		string s = to_string(i);
		string result;
		for (int i = 0; i < s.size(); i++) {
			int tmp = s[i] - '0';
			result += arr[tmp] + " ";
		}
		result.substr(result.size() - 1);
		v.push_back(result);
	}

	sort(v.begin(), v.end());
	
	//9 8 7 => 8 9 7
	//eight nine seven
	//
	for (int i = 0; i < v.size(); i++) {
		string s = v[i]; //eight nine - 89юс
		stringstream ss(s);
		vector<string> words;
		string word;
		while (getline(ss, word, ' ')) {
			words.push_back(word);
		}
		string result;
	//	cout << "###" << "\n";
		for (auto st : words) {
	//		cout << "st: " << st << "\n";
			auto it = find(begin(arr), end(arr), st);
			int idx = distance(arr, it);
		//	cout << "num: " << num << "\n";
			result += idx + '0';
		}
		if (i % 10 == 9) {
			cout << result << "\n";
			continue;
		}
		cout << result << " ";
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
}
