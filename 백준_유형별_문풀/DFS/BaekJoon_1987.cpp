#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

char map[20][20];
int visit[26];
int Dr[] = { 1, -1, 0, 0 };
int Dc[] = { 0, 0, 1, -1 };

int R, C;
int ans = 0;

void dfs(int r, int c, int cnt) {

	if (ans < cnt) ans = cnt;

	for (int i = 0; i < 4; i++) {
		int next_r = r + Dr[i];
		int next_c = c + Dc[i];

		if (next_r < 0 || next_r >= R || next_c < 0 || next_c >= C) continue;
		if (visit[map[next_r][next_c] - 'A'] == true) continue;

		visit[map[next_r][next_c] - 'A'] = 1;
		dfs(next_r, next_c, cnt + 1);
		visit[map[next_r][next_c] - 'A'] = 0;

	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cin >> map[i][j];
	}


	visit[map[0][0] - 'A'] = 1;
	dfs(0, 0, 1);
	cout << ans;

	return 0;
}
