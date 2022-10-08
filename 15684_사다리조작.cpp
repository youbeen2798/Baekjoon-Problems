#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

int n, m, h;

vector <pair<int, int>> v;
set <pair<int, int>> s1;
set <pair<int, int>> s2;

bool answer = false;

void add(vector<pair<int, int>> comb, int r) { //comb = {1,5}
	
	bool connected[35][15]; //가로선 개수: h // 세로선 개수 : n
	
	memset(connected, false, sizeof(connected));

	for (auto it = s1.begin(); it != s1.end(); it++) {
		int x = (*it).first;
		int y = (*it).second;

		connected[x][y] = true; //연결됨
	}

	for (int i = 0; i < comb.size(); i++) {
		int x = comb[i].first;
		int y = comb[i].second;

		connected[x][y] = true; //연결됨
	}

	int cnt = 0;

	for (int now_col = 1; now_col <= n; now_col++) {

		int now_col2 = now_col;
		int now_row = 1; //1행 1열

		bool check = false;


		while (true) {

			if (now_col2 == 1) { //세로선이 1이면
				for (int i = now_row; i <= h; i++) { //가로선의 개수
					if (connected[i][now_col2]) { //[1][1]
						now_col2++; //열 하나 오른쪽으로 이동

							now_row = i + 1;
						break;
					}
					else {
						now_row++;
					}
				}
			}
			else if (now_col2 == n) { //세로선이 마지막이라면
				for (int i = now_row; i <= h; i++) { // i = 5 ~ 6
					if (connected[i][now_col2 - 1]) { //왼쪽
						now_col2--;
						now_row = i + 1;
						break;
					}
					else {
						now_row++;
					}
				}
			}
			else { //세로선이 중간이면 (now_col = 4, now_row = 3) //세로선이 2

				for (int i = now_row; i <= h; i++) {
					if (connected[i][now_col2 - 1]) { //왼쪽
						now_col2--;
						now_row = i + 1;

						break;
					}
					else if (connected[i][now_col2]) { //오른쪽 [3][2]
						now_col2++; //열추가
						now_row = i + 1;
						break;
					}
					else {
							now_row++;
					}
				}
			}

			if (now_row == h + 1) { //now_row = 6
				if (now_col != now_col2) {
					check = true;
					break;
				}
				else {
					cnt++;

					if (cnt == n) {
						answer = true;
						cout <<  r << "\n";
						return;
					}
					break;
				}	
			}
		}

		//while밖, for문 안
		if (check) { //처음과 마지막이 맞지 않는다면 종료
			break;
		}
	}
}

void Combination(vector<pair<int, int>> arr, vector<pair<int, int>> comb, int r, int index, int depth, int k) {
	
	if (r == 0) {
		if (!answer) {
			add(comb, k);
		}
		else {
			return;
		}
	}
	else if (arr.size() == depth) {
		return;
	}
	else{
		comb[index] = arr[depth];
		Combination(arr, comb, r - 1, index + 1, depth + 1, k); //해당 원소를 선택한 경우

		Combination(arr, comb, r, index, depth + 1, k); //해당 원소를 선택하지 않은 경우
	}
}
void input() {
	cin >> n >> m >> h; 
	//세로선 개수, 가로선 개수, 세로선마다 가로선을 놓을 수 있는 위치의 개수

	for (int i = 0; i < m; i++) {
		int a;
		int b;
		cin >> a >> b; //b번 세로선과 b+1번 세로선을 a번 점선 위치에서 연결
		s1.insert({ a,b }); //이미 존재하는 가로선
	}


	//옆에 가로선(존재하는 가로선 양옆 가로선)
	for (auto it = s1.begin(); it != s1.end(); it++) {

		int x = (*it).first;
		int y = (*it).second;

		if (y == 1) { //왼쪽 끝에 있다면
			s2.insert({ x,2 }); //오른쪽 한개만
		}
		else if (y == n - 1) { //오른쪽 끝에 있다면
			s2.insert({ x, n -  2 }); //왼쪽 한개만
		}
		else { //왼쪽 끝과 오른쪽 끝 둘 다 아니라면
			
			s2.insert({ x, y - 1 });
			s2.insert({ x,y + 1 });
		}
	}


	for (int i = 1; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if ( (s1.find({ i,j }) == s1.end()) && (s2.find({i,j}) == s2.end())) { //이미 존재하는 가로선이 아니라면
				v.push_back({ i,j }); //가로선 추가
			}
		}
	}


	int r0 = 0;

	vector <pair<int, int>> comb0(r0);
	Combination(v, comb0, r0, 0, 0, r0);

	if (!answer) {
		int r1 = 1;
		vector <pair<int, int>> comb1(r1);
		Combination(v, comb1, r1, 0, 0, r1);
	}
	
	if (!answer) {
		int r2 = 2;
		vector<pair<int, int>> comb2(r2);
		Combination(v, comb2, r2, 0, 0, r2);
	}

	if (!answer) {
		int r3 = 3;
		vector<pair<int, int>> comb3(r3);
		Combination(v, comb3, r3, 0, 0, r3);
	}

	if (!answer) {
		cout << "-1";
	}

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();


}