#include<iostream>
#include<vector>
using namespace std;

long long dp[1001] = { 0 };

long long tile(int x) {
	if (x == 1) return 1;
	if (x == 2) return 2;
	if (dp[x] != 0) return dp[x];

	int a = tile(x - 1) % 10007;
	int b = tile(x - 2) % 10007;
	dp[x] = (a + b) % 10007;
	return dp[x];
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	cout << tile(n);

	return 0;
}
