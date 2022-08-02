#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool is_prime(int num) {
	if (num == 1) return false;
	if (num == 2 || num == 3) return true;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int cnt = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (is_prime(num)) cnt++;
	}

	cout << cnt;

	return 0;
}
