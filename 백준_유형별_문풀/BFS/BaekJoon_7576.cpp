#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node {
	int r;
	int c;
	int day;
};

int m, n;
vector<int> v[1001];

int bfs() {
	queue<Node> q;
	vector<vector<int>> used(n, vector<int>(m));
	int ansDay = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 1) {
				q.push({ i,j,0 });
				used[i][j] = 1;
			}
		}
	}
	
	int dr[] = { -1, 0, 0, 1 };
	int dc[] = { 0, 1, -1, 0 };

	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		if (ansDay < now.day) ansDay = now.day;
		for (int i = 0; i < 4; i++) {
			int nr = now.r + dr[i];
			int nc = now.c + dc[i];

			if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
			if (v[nr][nc] == -1) continue;
			if (used[nr][nc] == 1) continue;
			
			used[nr][nc] = 1;
			q.push({ nr,nc, now.day + 1 });
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (used[i][j] == 0 && v[i][j] == 0) return -1;
		}
	}
	return ansDay;
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> m >> n;

	int flag = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			if (a == 0) flag = 1;
			v[i].push_back(a);
		}
	}

	if (flag) {
		int ans = bfs();
		cout << ans;
	}
	else cout << flag;

	return 0;
}
