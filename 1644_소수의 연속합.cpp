// 정수 하나를 입력 받아 하나 이상의 연속된 소수의 합으로 나타낼 수 있는 경우의 수

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


vector <int> premium(int m) { //2와 m사이의 소수를 반환해주는 함수

	vector <bool> v(m + 1);

	for (int i = 2; i <= sqrt(m); i++) {
		if (v[i] == 1) {
			continue;
		}
		for (int j = 2 * i; j <= m; j += i) {
			v[j] = 1;
		}
	} //소수면 0, 아니면 1

	vector <int> vs;
	for (int i = 2; i <= m; i++) {
		if (v[i] == 0) {  //소수가 아닌 것들만
			vs.push_back(i); //벡터 vs에 저장
		}
	}
	return vs;
}


int count(vector <int> vs, int n) { // 벡터 vs 속 원소들을 이용하여 정수 n을 만드는 경우의 수를 count에 저장

	int sum = 0;
	int ptrA = -1;
	int ptrB = -1;
	int count = 0;

	while (1) {
		if (sum < n) {  //만약 합계가 정수보다 작다면
			if (ptrB + 1 == vs.size()) { //포인터 B가 벡터 vs의 마지막 원소를 가르킨다면
				break;
			}
			ptrB++; // 포인터 오른쪽으로 이동
			sum += vs[ptrB];

			if (sum == n) {
				count++;
			}
			
		}
		else {
			if (ptrA + 1 == vs.size()) { //포인터 A가 벡터 vs의 마지막 원소를 가르킨다면
				break;
			}

			ptrA++; //포인터 오른쪽으로 이동
			sum -= vs[ptrA];

			if (sum == n) {
				count++;
			}
		}
	}
	return count;
}




int main() {
	ios_base::sync_with_stdio(0); //입출력 빠르게
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n; //정수 n 입력받기

	vector <int> vs = premium(n);

	cout << count(vs, n);



}