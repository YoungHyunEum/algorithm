#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int arr[10] = { 0 };

	int a, b, c;
	cin >> a >> b >> c;

	int gop = a * b * c;

	string str = to_string(gop);

	for (int i = 0; i < str.size(); i++) {
		arr[str[i] - 48]++;
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}
