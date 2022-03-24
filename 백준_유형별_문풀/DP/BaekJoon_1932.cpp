#include<iostream>
#include<vector>
using namespace std;

int v[501][501] = { 0 };
int dp[501][501] = { 0 };


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> v[i][j];
		}
	}

	dp[0][0] = v[0][0];
	int dy[] = { 1, 1 };
	int dx[] = { 0, 1 };
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j <= i; j++) {
			for (int t = 0; t < 2; t++) {
				int ny = i + dy[t];
				int nx = j + dx[t];
				int compare = dp[i][j] + v[ny][nx];
				if (dp[ny][nx] < compare) dp[ny][nx] = compare;
			}
		}
	}

	int max = -99;
	for (int x = 0; x <= n - 1; x++) {
		if (dp[n - 1][x] > max) max = dp[n - 1][x];
	}

	cout << max;

	return 0;
}
