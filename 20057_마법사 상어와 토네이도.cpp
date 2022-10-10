#include <iostream>

using namespace std;

int n;
int arr[500][500];
int before = 0;

void move(int start_x, int start_y, int direction) {
	int amount;
	if (direction == 1) { //왼쪽
		amount = arr[start_x][start_y - 1];
		arr[start_x][start_y - 1] = 0;
	}
	else if (direction == 2) { //아래쪽
		amount = arr[start_x + 1][start_y];
		arr[start_x + 1][start_y] = 0;
	}
	else if (direction == 3) { //오른쪽
		amount = arr[start_x][start_y + 1];
		arr[start_x][start_y + 1] = 0;
	}
	else if (direction == 4) { //위쪽
		amount = arr[start_x - 1][start_y];
		arr[start_x - 1][start_y] = 0;
	}
	int remain_y = amount;
	int onepercent = amount * 0.01;
	int sevenpercent = amount * 0.07;
	int tenpercent = amount * 0.1;
	int twopercent = amount * 0.02;
	int fivepercent = amount * 0.05;
	remain_y -= ((onepercent + sevenpercent + tenpercent + twopercent) * 2 + fivepercent);

	if (direction == 1) { //왼쪽
		if (1 <= start_x - 1 && start_x - 1 <= n && 1 <= start_y && start_y <= n) {
			arr[start_x - 1][start_y] += onepercent;
		}
		if (1 <= start_x + 1 && start_x + 1 <= n && 1 <= start_y && start_y <= n) {
			arr[start_x + 1][start_y] += onepercent;
		}
		if (1 <= start_x - 1 && start_x - 1 <= n && 1 <= start_y - 1 && start_y - 1 <= n) {
			arr[start_x - 1][start_y - 1] += sevenpercent;
		}
		if (1 <= start_x + 1 && start_x + 1 <= n && 1 <= start_y - 1 && start_y - 1 <= n) {
			arr[start_x + 1][start_y - 1] += sevenpercent;
		}
		if (1 <= start_x - 1 && start_x - 1 <= n && 1 <= start_y - 2 && start_y - 2 <= n) {
			arr[start_x - 1][start_y - 2] += tenpercent;
		}
		if (1 <= start_x + 1 && start_x + 1 <= n && 1 <= start_y - 2 && start_y - 2 <= n) {
			arr[start_x + 1][start_y - 2] += tenpercent;
		}
		if (1 <= start_x && start_x <= n && 1 <= start_y - 3 && start_y - 3 <= n) {
			arr[start_x][start_y - 3] += fivepercent;
		}
		if (1 <= start_x - 2 && start_x - 2 <= n && 1 <= start_y - 1 && start_y - 1 <= n) {
			arr[start_x - 2][start_y - 1] += twopercent;
		}
		if (1 <= start_x + 2 && start_x + 2 <= n && 1 <= start_y - 1 && start_y - 1 <= n) {
			arr[start_x + 2][start_y - 1] += twopercent;
		}
		if (1 <= start_x && start_x <= n && 1 <= start_y - 2 && start_y - 2 <= n) {
			arr[start_x][start_y - 2] += remain_y;
		}

	}
	else if (direction == 2) { //아래쪽
		if (1 <= start_x && start_x <= n && 1 <= start_y - 1 && start_y - 1 <= n) {
			arr[start_x][start_y - 1] += onepercent;
		}
		if (1 <= start_x && start_x <= n && 1 <= start_y + 1 && start_y + 1 <= n) {
			arr[start_x][start_y + 1] += onepercent;
		}
		if (1 <= start_x + 1 && start_x + 1 <= n && 1 <= start_y - 1 && start_y - 1 <= n) {
			arr[start_x + 1][start_y - 1] += sevenpercent;
		}
		if (1 <= start_x + 1 && start_x + 1 <= n && 1 <= start_y + 1 && start_y + 1 <= n) {
			arr[start_x + 1][start_y + 1] += sevenpercent;
		}
		if (1 <= start_x + 1 && start_x + 1 <= n && 1 <= start_y - 2 && start_y - 2 <= n) {
			arr[start_x + 1][start_y - 2] += twopercent;
		}
		if (1 <= start_x + 1 && start_x + 1 <= n && 1 <= start_y + 2 && start_y + 2 <= n) {
			arr[start_x + 1][start_y + 2] += twopercent;
		}
		if (1 <= start_x + 2 && start_x + 2 <= n && 1 <= start_y - 1 && start_y - 1 <= n) {
			arr[start_x + 2][start_y - 1] += tenpercent;
		}
		if (1 <= start_x + 2 && start_x + 2 <= n && 1 <= start_y + 1 && start_y + 1 <= n) {
			arr[start_x + 2][start_y + 1] += tenpercent;
		}
		if (1 <= start_x + 3 && start_x + 3 <= n && 1 <= start_y && start_y <= n) {
			arr[start_x + 3][start_y] += fivepercent;
		}
		if (1 <= start_x + 2 && start_x + 2 <= n && 1 <= start_y && start_y <= n) {
			arr[start_x + 2][start_y] += remain_y;
		}
	}
	else if (direction == 3) { //오른쪽
		if (1 <= start_x - 1 && start_x - 1 <= n && 1 <= start_y && start_y <= n) {
			arr[start_x - 1][start_y] += onepercent;
		}
		if (1 <= start_x + 1 && start_x + 1 <= n && 1 <= start_y && start_y <= n) {
			arr[start_x + 1][start_y] += onepercent;
		}
		if (1 <= start_x - 1 && start_x - 1 <= n && 1 <= start_y + 1 && start_y + 1 <= n) {
			arr[start_x - 1][start_y + 1] += sevenpercent;
		}
		if (1 <= start_x + 1 && start_x + 1 <= n && 1 <= start_y + 1 && start_y + 1 <= n) {
			arr[start_x + 1][start_y + 1] += sevenpercent;
		}
		if (1 <= start_x - 1 && start_x - 1 <= n && 1 <= start_y + 2 && start_y + 2 <= n) {
			arr[start_x - 1][start_y + 2] += tenpercent;
		}
		if (1 <= start_x + 1 && start_x + 1 <= n && 1 <= start_y + 2 && start_y + 2 <= n) {
			arr[start_x + 1][start_y + 2] += tenpercent;
		}
		if (1 <= start_x && start_x <= n && 1 <= start_y + 3 && start_y + 3 <= n) {
			arr[start_x][start_y + 3] += fivepercent;
		}
		if (1 <= start_x - 2 && start_x - 2 <= n && 1 <= start_y + 1 && start_y + 1 <= n) {
			arr[start_x - 2][start_y + 1] += twopercent;
		}
		if (1 <= start_x + 2 && start_x + 2 <= n && 1 <= start_y + 1 && start_y + 1 <= n) {
			arr[start_x + 2][start_y + 1] += twopercent;
		}
		if (1 <= start_x && start_x <= n && 1 <= start_y + 2 && start_y + 2 <= n) {
			arr[start_x][start_y + 2] += remain_y;
		}

	}
	else { //위쪽
		if (1 <= start_x && start_x <= n && 1 <= start_y - 1 && start_y - 1 <= n) {
			arr[start_x][start_y - 1] += onepercent;
		}
		if (1 <= start_x && start_x <= n && 1 <= start_y + 1 && start_y + 1 <= n) {
			arr[start_x][start_y + 1] += onepercent;
		}
		if (1 <= start_x - 1 && start_x - 1 <= n && 1 <= start_y - 1 && start_y - 1 <= n) {
			arr[start_x - 1][start_y - 1] += sevenpercent;
		}
		if (1 <= start_x - 1 && start_x - 1 <= n && 1 <= start_y + 1 && start_y + 1 <= n) {
			arr[start_x - 1][start_y + 1] += sevenpercent;
		}
		if (1 <= start_x - 2 && start_x - 2 <= n && 1 <= start_y - 1 && start_y - 1 <= n) {
			arr[start_x - 2][start_y - 1] += tenpercent;
		}
		if (1 <= start_x - 2 && start_x - 2 <= n && 1 <= start_y + 1 && start_y + 1 <= n) {
			arr[start_x - 2][start_y + 1] += tenpercent;
		}
		if (1 <= start_x - 3 && start_x - 3 <= n && 1 <= start_y && start_y <= n) {
			arr[start_x - 3][start_y] += fivepercent;
		}
		if (1 <= start_x - 1 && start_x - 1 <= n && 1 <= start_y + 2 && start_y + 2 <= n) {
			arr[start_x - 1][start_y + 2] += twopercent;
		}
		if (1 <= start_x - 1 && start_x - 1 <= n && 1 <= start_y - 2 && start_y - 2 <= n) {
			arr[start_x - 1][start_y - 2] += twopercent;
		}
		if (1 <= start_x - 2 && start_x - 2 <= n && 1 <= start_y && start_y <= n) {
			arr[start_x - 2][start_y] += remain_y;
		}
	}
}
void input() {
	cin >> n;

	before = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			before += arr[i][j];
		}
	}

}

void solution() {

	int k = n / 2;

	int mid_x = k + 1;
	int mid_y = k + 1;
	int num;
	//n = 1 ~ n = 3
	for (int i = 1; i <= k; i++) {
		num = 2 * i - 1;
		//왼쪽
		for (int j = 1; j <= num; j++) {
			move(mid_x, mid_y--, 1);
		}
		//아래쪽
		for (int j = 1; j <= num; j++) {
			move(mid_x++, mid_y, 2);
		}
		num += 1;
		//오른쪽
		for (int j = 1; j <= num; j++) {
			move(mid_x, mid_y++, 3);
		}
		//위쪽
		for (int j = 1; j <= num; j++) {
			move(mid_x--, mid_y, 4);
		}
	}

	for (int j = 1; j <= num; j++) {
		move(mid_x, mid_y--, 1);
	}

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();

	int after = 0;


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			after += arr[i][j];
		}
	}


	cout << before - after << "\n";
}