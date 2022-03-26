#include<iostream>
using namespace std;

int v[501][501];
int dp[501][501];
int m, n;

void dp_init() {
	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < 501; j++) {
			dp[i][j] = -1;
		}
	}
}

int dfs(int r, int c) {
	if (r == m-1 && c == n-1) return 1;
	if (dp[r][c] != -1) return dp[r][c];

	dp[r][c] = 0;
	int dr[] = { -1, 0, 0, 1 };
	int dc[] = { 0, -1, 1, 0 };
	for (int i = 0; i < 4; i++)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
		if (v[r][c] > v[nr][nc]) {
			dp[r][c] += dfs(nr, nc);
		}
	}
	return dp[r][c];
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> m >> n;
	dp_init();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}

	cout << dfs(0, 0);

	return 0;
}
