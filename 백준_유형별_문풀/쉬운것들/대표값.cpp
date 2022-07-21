#include <iostream>
using namespace std;

int arr[1001] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int temp = 0;
	int avg = 0;
	int ans = 0;
	
	for (int i = 0; i < 10; i++) {
		int a;
		cin >> a;
		arr[a]++;
		if (temp < arr[a]) {
			ans = a;
			temp = arr[a];
		}
		avg += a;
	}

	cout << avg / 10 << "\n";
	cout << ans;

	return 0;
}
