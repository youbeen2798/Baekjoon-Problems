#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	double* arr = new double[n];
	double score = 0;
	double average;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int max_score = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] >= max_score) {
			max_score = arr[i];
		}
	}
	// cout << max_score << endl;

	for (int i = 0; i < n; i++) {
		arr[i] = (arr[i] / max_score) * 100;
	//	cout << arr[i] << endl;
		score += arr[i];
	}

	average = score / n;

	cout << average;

	return 0;
}