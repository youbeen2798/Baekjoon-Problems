#include <iostream>
#include <algorithm>
using namespace std;

char a;
int b;
int n;
string st;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b;
	pair<char, int> king = make_pair(a, b); //왕 위치
	cin >> a >> b;
	pair<char, int> stone = make_pair(a, b); //돌 위치

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> st;
		if (st == "R") {
			king.first++; //오른쪽으로 한칸 이동
			int cnt = 0;
			if (king.first == stone.first && king.second == stone.second) { //돌과 같은 곳이라면
				stone.first++; //돌도 오른쪽으로 한칸 이동
				cnt++; //돌이 이동했다는 증거
			}

			//혹여 왕이나 돌이 밖으로 나갔다면
			if (king.first > 'H' || king.first < 'A' || king.second < 1 || king.second > 8 || stone.first > 'H' || stone.first < 'A' || stone.second < 1 || stone.second > 8) {
				king.first--; //왕 제자리로 원위치(왼쪽으로 한칸이동)
				if (cnt == 1) { //혹시 돌도 이동했었다면
					stone.first--; //돌도 제자지로 원위치(왼쪽으로 한칸이동)
				}
				continue;
			}

		}
		else if (st == "L") {
			king.first--; //왼쪽으로 한칸 이동
			int cnt = 0;
			if (king.first == stone.first && king.second == stone.second) { //돌과 같은 곳이라면
				stone.first--;
				cnt++; //돌이 이동했다는 증거
			}
			if (king.first > 'H' || king.first < 'A' || king.second < 1 || king.second > 8 || stone.first > 'H' || stone.first < 'A' || stone.second < 1 || stone.second > 8) {
				king.first++; //왕 제자리로 원위치(오른쪽으로 한칸이동)
				if (cnt == 1) { //혹시 돌도 이동했었다면
					stone.first++; //돌도 제자지로 원위치(오른쪽으로 한칸이동)
				}
				continue;
			}
		}
		else if (st == "B") {
			king.second--; //아래로 한칸 이동
			int cnt = 0;
			if (king.first == stone.first && king.second == stone.second) { //돌과 같은 곳이라면
				stone.second--;
				cnt++; //돌이 이동했다는 증거
			}
			if (king.first > 'H' || king.first < 'A' || king.second < 1 || king.second > 8 || stone.first > 'H' || stone.first < 'A' || stone.second < 1 || stone.second > 8) {
				king.second++; //왕 제자리로 원위치(위로 한칸이동)
				if (cnt == 1) { //혹시 돌도 이동했었다면
					stone.second++; //돌도 제자리로 원위치(위로 한칸 이동)
				}
				continue;
			}
		}
		else if (st == "T") {
			king.second++; //위로 한칸 이동
			int cnt = 0;
			if (king.first == stone.first && king.second == stone.second) { //돌과 같은 곳이라면
				stone.second++;
				cnt++; //돌이 이동했다는 증거
			}
			if (king.first > 'H' || king.first < 'A' || king.second < 1 || king.second > 8 || stone.first > 'H' || stone.first < 'A' || stone.second < 1 || stone.second > 8) {
				king.second--; //왕 제자리로 원위치(아래로 한칸 이동)
				if (cnt == 1) { //혹시 돌도 이동했었다면
					stone.second--; //돌도 제자리로 원위치(아래로 한칸 이동)
				}
				continue;
			}
		}
		else if (st == "RT") {
			king.first++; //오른쪽으로 한칸이동
			king.second++; //위로 한칸 이동
			int cnt = 0;
			if (king.first == stone.first && king.second == stone.second) { //돌과 같은 곳이라면
				stone.first++; //돌 오른쪽으로 한칸이동
				stone.second++; //돌 위로 한칸이동
				cnt++; //돌이 이동했다는 증거
			}
			if (king.first > 'H' || king.first < 'A' || king.second < 1 || king.second > 8 || stone.first > 'H' || stone.first < 'A' || stone.second < 1 || stone.second > 8) {
				king.first--;
				king.second--;
				if (cnt == 1) { //혹시 돌도 이동했었다면
					stone.first--;; //돌 제자리로 원위치(왼쪽으로 한칸 이동)
					stone.second--; //돌 제자리로 원위치(아래로 한칸이동)
				}
				continue;
			}
		}
		else if (st == "LT") {
			king.first--;
			king.second++;
			int cnt = 0;
			if (king.first == stone.first && king.second == stone.second) { //돌과 같은 곳이라면
				stone.first--;
				stone.second++;
				cnt++; //돌이 이동했다는 증거
			}
			if (king.first > 'H' || king.first < 'A' || king.second < 1 || king.second > 8 || stone.first > 'H' || stone.first < 'A' || stone.second < 1 || stone.second > 8) {
				king.first++;
				king.second--;
				if (cnt == 1) { //혹시 돌도 이동했었다면
					stone.first++;
					stone.second--;
				}
				continue;
			}
		}
		else if (st == "RB") {
			king.first++;
			king.second--;
			int cnt = 0;
			if (king.first == stone.first && king.second == stone.second) { //돌과 같은 곳이라면
				stone.first++;
				stone.second--;
				cnt++; //돌이 이동했다는 증거
			}
			if (king.first > 'H' || king.first < 'A' || king.second < 1 || king.second > 8 || stone.first > 'H' || stone.first < 'A' || stone.second < 1 || stone.second > 8) {
				king.first--;
				king.second++;
				if (cnt == 1) { //혹시 돌도 이동했었다면
					stone.first--;
					stone.second++;
				}
				continue;
			}
		}
		else if (st == "LB") {
			king.first--;
			king.second--;
			int cnt = 0;
			if (king.first == stone.first && king.second == stone.second) { //돌과 같은 곳이라면
				stone.first--;
				stone.second--;
				cnt++; //돌이 이동했다는 증거
			}
			if (king.first > 'H' || king.first < 'A' || king.second < 1 || king.second > 8 || stone.first > 'H' || stone.first < 'A' || stone.second < 1 || stone.second > 8) {
				king.first++;
				king.second++;
				if (cnt == 1) { //혹시 돌도 이동했었다면
					stone.first++;
					stone.second++;
				}
				continue;
			}
		}
	}


	cout << king.first << king.second << "\n";
	cout << stone.first << stone.second << "\n";

}