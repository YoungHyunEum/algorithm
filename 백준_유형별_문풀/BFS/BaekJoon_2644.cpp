#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;

int n, m;
int s, e;
vector<int> v[101];
int used[101] = {0};

int bfs() {
	queue<int> q;
	q.push(s);
	used[s] = 1;

	int ans = 9999;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == e) {
			ans = min(ans, used[now]);
		}

		for (int i = 0; i < v[now].size(); i++) {
			if (used[v[now][i]] != 0) continue;
			used[v[now][i]] = used[now] + 1;
			q.push(v[now][i]);
		}
	}
	return ans;
}

int main() {
	
	cin >> n;
	cin >> s >> e;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int ans = bfs();

	if (ans == 9999) cout << "-1";
	else cout << ans - 1;

	return 0;
}
