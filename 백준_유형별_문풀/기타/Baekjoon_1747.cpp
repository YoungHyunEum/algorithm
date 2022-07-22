#include <iostream>
#include <math.h>
#include <string>
using namespace std;

bool isPrime(int n) {
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

bool palindrom(int n) {
	string str = to_string(n);
	for (int i = 0, j = str.size() - 1; i < str.size(); i++, j--) {
		if (str[i] != str[j]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	while (1) {
		if (isPrime(N) && palindrom(N)) {
			cout << N;
			break;
		}
		N++;
	}
	
	return 0;
}
