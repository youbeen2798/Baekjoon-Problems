#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {

    int num;
    cin >> num;
    vector<int> v;
    int input[10000] = { 0, };

    for (int i = 0; i < num; i++) {
        cin >> input[i];
    }

    for (int i = 0; i < num; i++) {
        int count = floor(sqrt(input[i]));
        int check = 0;
        if (count == 1 && (input[i] != 1)) { //���Ұ� 2 �Ǵ� 3�̸�
            v.push_back(input[i]);
            continue;
        }
        else {
            for (int j = 2; j <= sqrt(input[i]); j++) {
                if (input[i] % j == 0) {
                    break;
                }
                else {
                    check++;
                }
            }
        }
        if (count == check + 1 && input[i] != 1) {
            v.push_back(input[i]);
        }
    }
    //���� �Ҽ� ������ 0�̶�� -1 ��� �� ����
    if (v.size() == 0) {
        cout << "-1";
        return 0;
    }

    //�Ҽ� ���ִ� vector �ߺ� ���� ����
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    // �ߺ� ���� �Ҽ��鸸�� �����̹Ƿ�, �ּҰ������ �� �Ҽ����� ��

    ll result = 1;

    for (int i = 0; i < v.size(); i++) {
        result *= v[i];
    }

    cout << result;

}