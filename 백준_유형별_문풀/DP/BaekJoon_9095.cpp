#include<iostream>
#include<vector>
using namespace std;

int dp[12] = { 0 };

int OTT(int x) {
	if (x == 1) return 1;
	if (x == 2) return 2;
	if (x == 3) return 4;
	if (dp[x] != 0) return dp[x];
	int a = OTT(x - 1);
	int b = OTT(x - 2);
	int c = OTT(x - 3);
	dp[x] = a + b + c;
	return dp[x];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int a;
		cin >> a;
		cout << OTT(a) << "\n";
	}

	return 0;
}
