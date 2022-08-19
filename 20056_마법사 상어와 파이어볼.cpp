#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, m, k;

struct animal {
	int x; //x좌표(행)
	int y; //y좌표(열)
	int m; //질량
	int s; //속도
	int d; //방향
};


vector<animal> v[51][51];

pair<int,int> move(int ri, int ci, int si, int di) {

	if (di == 0) { //북
		ri -=  si;
	}
	else if (di == 1) { //동북
		ri -=  si;
		ci +=  si;
	}
	else if (di == 2) { //동
		ci +=   si;
	}
	else if (di == 3) { //남동
		ri += si;
		ci +=  si;
	}
	else if (di == 4) { //남
		ri += si;
	}
	else if (di == 5) { //남서
		ri += si;
		ci -=  si;
	}
	else if (di == 6) { //서
		ci -= si;
	}
	else if (di == 7) { //북서
		ri -= si;
		ci -= si;
	}

	if (ri > n) {
		if (ri % n == 0) {
			ri = n;
		}
		else {
			ri %= n;
		}
	}
	else if (ri == 0) {
		ri = n;
	}
	else if (ri < 0) {
		ri = n - (-1 * ri) % n;
	}

	if (ci > n) {
		if (ci % n == 0) {
			ci = n;
		}
		else {
			ci %= n;
		}
	}
	else if (ci == 0) {
		ci = n;
	}
	else if (ci < 0) {
		ci = n - (-1 * ci) % n;
	}

	return { ri,ci };

}

void combine() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			if (v[i][j].size() >= 2) {
				int mass_sum = 0; //질량 합
				int speed_sum = 0; //속도 합

				bool odd_speed = true; //모두 홀수라면 참
				bool even_speed = true; //모두 짝수라면 참

				for (auto anim : v[i][j]) {

					if (anim.d % 2 == 0) {
						odd_speed = false;
					}
					else if (anim.d % 2 != 0) {
						even_speed = false;
					}

					mass_sum += anim.m;
					speed_sum += anim.s;
				}

				mass_sum /= 5;

				if (mass_sum == 0) {
					v[i][j].clear();
					continue;
				}

				speed_sum /= v[i][j].size();
				v[i][j].clear();

				if (odd_speed || even_speed) {
					for (int k = 0; k <= 3; k++) {
						animal a;
						a.x = i;
						a.y = j;
						a.m = mass_sum;
						a.s = speed_sum;
						a.d = k * 2;
						v[i][j].push_back(a);
					}
				}
				else {
					for (int k = 0; k <= 3; k++) {
						animal a;
						a.x = i;
						a.y = j;
						a.m = mass_sum;
						a.s = speed_sum;
						a.d = k * 2 + 1;
						v[i][j].push_back(a);
					}
				}


			}
		}
	}
}

void movemove() {

	vector<animal> new_v[51][51];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			if (v[i][j].size() > 0) { //이동하기

				for (auto anim : v[i][j]) {

					auto b = move(anim.x, anim.y, anim.s, anim.d); //이동 후 좌표

					animal new_animal;

					new_animal.x = b.first;
					new_animal.y = b.second;
					new_animal.s = anim.s;
					new_animal.d = anim.d;
					new_animal.m = anim.m;

					new_v[b.first][b.second].push_back(new_animal);
				}

				v[i][j].clear();
			}
		}
	}

	//이동시킨 동물 추가하기
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (new_v[i][j].size() > 0) {
				for (animal a : new_v[i][j]) {
					v[i][j].push_back(a);
				}
			}
		}
	}

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	
	int animalSize = 0;

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) { //처음 이동시키기
		int ri, ci, mi, si, di;

		cin >> ri >> ci >> mi >> si >> di; 

		auto a = move(ri, ci, si, di); //이동

		animal ani;

		ani.x = a.first; //이동 후 x 좌표
		ani.y = a.second;//이동 후 y 좌표
		ani.m = mi;
		ani.s = si;
		ani.d = di;

		v[ani.x][ani.y].push_back(ani);
	}

	combine();

	if (k >= 2) {
		for (int i = 0; i < k - 1; i++){
			movemove();
			combine();
		}
	}
	

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (v[i][j].size() > 0) {
				for (auto anim : v[i][j]) {
					answer += anim.m;
				}
			}
		}
	}
	cout <<  answer << "\n";
	


}
