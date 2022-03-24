#include<iostream>
#include<vector>
using namespace std;

int dp[1001] = { 0 };
int n;

int tile(int x) {
	if (x == 1) return 1;
	if (x == 2) return 3;
	if (dp[x] != 0) return dp[x];
	return dp[x] = (tile(x - 1) + 2 * tile(x - 2)) % 10007;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	cout << tile(n);

	return 0;
}
