#include <iostream>
#include <string>
using namespace std;

string dTob(int n) {
	string temp;
	while (1) {
		if (n == 1 || n == 0) {
			temp += (char)(n + 48);
			break;
		}
		temp += (char)((n % 2) + 48);
		n /= 2;
	}
	return temp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for(int i = 0; i < T; i++){
		int num;
		cin >> num;

		string bin = dTob(num);

		for (int i = 0; i < bin.size(); i++) {
			if (bin[i] == '1') cout << i << " ";
		}
	}

	return 0;
}
