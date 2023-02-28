#include <iostream>

using namespace std;

int n;
int arr[40001];
int list[40001];

void binary_search(int start, int end, int target) {

	//target 이상인 것들 중에서 가장 작은 것
	//start : target 이상
	//end : target 이상

	int idx = end;
	//idx = -1
	while (start <= end) {
		int mid = (start + end) / 2;
		if (target <= list[mid]) {
			//중간값이 더 크다면
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	list[start] = target;
}

void solution() {

	list[0] = arr[0];

	int list_pos = 0;

	for (int i = 1; i < n; i++) {
		if (list[list_pos] < arr[i]) {
			//만약
			list[++list_pos] = arr[i];
		}
		else if(list[list_pos] > arr[i]){
			binary_search(0, list_pos, arr[i]);
		}
	}

	cout << list_pos + 1;
}
void input() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}