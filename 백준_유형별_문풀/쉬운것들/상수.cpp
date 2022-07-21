#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num1, num2;
	cin >> num1 >> num2;

	int temp1, temp2;

	temp1 = ((num1 % 10) * 100) + ((num1 % 100 - num1 % 10)) + (num1 / 100);
	temp2 = ((num2 % 10) * 100) + ((num2 % 100 - num2 % 10)) + (num2 / 100);

	if (temp1 > temp2) cout << temp1;
	else cout << temp2;

	return 0;
}
