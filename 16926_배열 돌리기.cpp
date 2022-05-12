#include <iostream>

using namespace std;

int d[301][301];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, r;
    cin >> n >> m >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> d[i][j];
        }
    }

    while (r--) {
        int x1 = 0;
        int y1 = 0;

        int x2 = n - 1;
        int y2 = 0;

        int x3 = n - 1;
        int y3 = m - 1;

        int x4 = 0;
        int y4 = m - 1;

        while ((x1 < x2) && (y1 < y4)) {
            int tmp = d[x2][y2];

            for (int i = x2; i > x1; i--) { // 직사각형 왼쪽
                d[i][y2] = d[i - 1][y2];
            }

            for (int j = y1; j < y4; j++) { //직사각형 위쪽
                d[x1][j] = d[x1][j + 1];
            }

            for (int i = x4; i < x3; i++) { //직사각형 오른쪽
                d[i][y4] = d[i + 1][y4];
            }

            for (int j = y3; j > y2; j--) { //직사각형 아래쪽
                d[x2][j] = d[x2][j - 1];
            }

            d[x2][y2 + 1] = tmp;

            x1 += 1;
            y1 += 1;

            x2 -= 1;
            y2 += 1;

            x3 -= 1;
            y3 -= 1;

            x4 += 1;
            y4 -= 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << d[i][j] << ' ';
        }
        cout << "\n";
    }

}