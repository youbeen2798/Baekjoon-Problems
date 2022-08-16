#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector <int> num; // 5 6
vector <int> operatorr; 
vector <int> results;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		num.push_back(k);
	}

	for (int i = 0; i < 4; i++) {
		int k;
		cin >> k;
		if (i == 0) {
			for (int j = 0; j < k; j++) {
				operatorr.push_back(1);
			}
		}

		else if (i == 1) {
			for (int j = 0; j < k; j++) {
				operatorr.push_back(2);
			}
		}
		
		else if (i == 2) {
			for (int j = 0; j < k; j++) {
				operatorr.push_back(3);
			}
		}

		else {
			for (int j = 0; j < k; j++) {
				operatorr.push_back(4);
			}
		}
	}

	sort(operatorr.begin(), operatorr.end());

	int result;
	int idx = 0;

	do {

		idx = 0;
		for (int i = 0; i < operatorr.size(); i++) {
	
			if (i == 0) {
				if (operatorr[i] == 1) {
					result = num[0] + num[1];
				//	cout << "result :" << result << "\n";
					idx++;
				}

				else if (operatorr[i] == 3) {
					result = num[0] * num[1];
				//	cout << "result :" << result << "\n";
					idx++;
				}

				else if (operatorr[i] == 2) {
					result = num[0] - num[1];
				//	cout << "result :" << result << "\n";
					idx++;
				}

				else if (operatorr[i] == 4) {
					result = num[0] / num[1];
				//	cout << "result :" << result << "\n";
					idx++;
				}
			}

			else {
				if (operatorr[i] == 3) {
					result = result * num[idx + 1];
				//	cout << "result: " << result << "\n";
					idx++;
				}

				else if (operatorr[i] == 1) {
				//	cout << "plus" << "\n";
				//	cout << "idx: " << idx + 1 << "\n";
					result = result + num[idx + 1];
				//	cout << "result: " << result << "\n";
					idx++;
				}

				else if (operatorr[i] == 2) {
					result = result - num[idx + 1];
				//	cout << "result: " << result << "\n";
					idx++;
				}

				else if (operatorr[i] == 4) {
					result = result / num[idx + 1];
				//	cout << "result: " << result << "\n";
					idx++;
				}
			}		
		}

		results.push_back(result);
//		cout << "final result: " << result << "\n";

//		cout << "\n";
	} while (next_permutation(operatorr.begin(), operatorr.end()));
	
	sort(results.begin(), results.end());

	cout << results[results.size() - 1] << "\n";
	cout << results[0] << "\n";


}