#include <iostream>

using namespace std;

int Fibonacci(int num)
{
	if (num == 0) { 
		return 0;
	}
	else if (num == 1) {
		return 1;
	}
	else if (num >= 2) { //�Ǻ���ġ ����
		return Fibonacci(num - 2) + Fibonacci(num - 1);
	}
}

int main() {

	ios_base::sync_with_stdio(0); //����� ������ �ϱ�
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	cout << Fibonacci(n); //����� ���

}