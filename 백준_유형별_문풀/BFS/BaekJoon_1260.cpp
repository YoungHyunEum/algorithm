#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, m, s;
vector<int> v[1001];
vector<int> path;
int used_dfs[1001];
int used_bfs[1001];

void dfs(int x, int y) {
	if (x == n) return;

	cout << y << " ";
	for (int i = 0; i < v[y].size(); i++) {
		if (used_dfs[v[y][i]] != 0) continue;
		used_dfs[v[y][i]] = 1;
		dfs(x + 1, v[y][i]);
	}
}

void bfs() {
	queue<int> q;
	q.push(s);
	used_bfs[s] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		cout << now << " ";

		for (int i = 0; i < v[now].size(); i++) {
			if (used_bfs[v[now][i]] != 0) continue;
			used_bfs[v[now][i]] = used_bfs[now] + 1;
			q.push(v[now][i]);
		}
	}
}

int main() {
	cin >> n >> m >> s;
	
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	for (int i = 0; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}

	used_dfs[s] = 1;
	dfs(0, s);
	cout << "\n";
	bfs();

	return 0;
}
