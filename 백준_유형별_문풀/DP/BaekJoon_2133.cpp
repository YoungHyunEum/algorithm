#include<iostream>
#include<vector>
using namespace std;

int dp[31] = { 0 };
int n;

int tile(int x) {
	if (x == 0) return 1;
	if (x == 1) return 0;
	if (x == 2) return 3;
	if (dp[x] != 0) return dp[x];
	int ans = 3 * tile(x - 2);
	for (int i = 3; i <= x; i++) {
		if (i % 2 == 0) ans += 2 * tile(x - i);
	}
	return dp[x] = ans;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	cout << tile(n);

	return 0;
}
