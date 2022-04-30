#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int team1_win = 0;
int team2_win = 0;
vector <int> win;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int* team1 = new int[n];
	int* team2 = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> team1[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> team2[i];
	}

	for (int i = 0; i < n; i++) {
		if ((team1[i] == 2 && team2[i] == 1) || (team1[i] == 3 && team2[i] == 2) || (team1[i] == 1 && team2[i] == 3)) { //team1이 이길경우
			team1_win++;
			win.push_back(team2_win);
			team2_win = 0;
		}

		else if ((team1[i] == 1 && team2[i] == 2) || (team1[i] == 2 && team2[i] == 3) || (team1[i] == 3 && team2[i] == 1)) { //team2이 이길경우
			team2_win++;
			win.push_back(team1_win);
			team1_win = 0;
		}

		else if (team1[i] == team2[i]) {
			if (team1_win == 0) {
				team1_win++;
				win.push_back(team2_win);
				team2_win = 0;
			}
			else {
				team2_win++;
				win.push_back(team1_win);
				team1_win = 0;
			}
		}
	}

	win.push_back(team1_win); //한쪽 팀이 계속 이기다 게임이 끝날 경우 대비
	win.push_back(team2_win); //한쪽 팀이 계속 이기다 게임이 끝날 경우 대비

	sort(win.begin(), win.end());

	cout << win[n + 1];

}