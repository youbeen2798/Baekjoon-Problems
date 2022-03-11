#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); //����� �ӵ� ������ �ϱ� ����
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, less<int>> max_heap; //�������� �ִ� �� ����
    priority_queue<int, vector<int>, greater<int>> min_heap; //�������� �ּ� �� ����

    while (n--) {
        int input;
        cin >> input; //�Է� �ޱ�
        if (max_heap.size() == min_heap.size()) { //�ִ� ���� �ּ��� �����ư��� ���� ����
            max_heap.push(input);
        }
        else {
            min_heap.push(input);
        }

        if (!max_heap.empty() && !min_heap.empty()) { //�ִ� ���� �ּ� �� �� �� ������� �ʴٸ�
            if (max_heap.top() > min_heap.top()) { //�ִ����� ù��° ���Ұ� �ּ����� ù��° ���Һ��� ũ�ٸ�
                max_heap.push(min_heap.top()); //�ּ����� ù��° ���Ҹ� �ִ����� ����
                min_heap.pop(); //�ּ����� ù��° ���� ����
                min_heap.push(max_heap.top()); //�ִ����� ù��° ���Ҹ� �ּ����� ����
                max_heap.pop(); //�ִ����� ù���� ���� ����
            } //�ᱹ �� �ּ����� �ִ����� ù��° ���Ҹ� �ٲ���
        }
        cout << max_heap.top() << "\n"; // �ִ����� ù��° ���� ���
    }
    return 0;

}