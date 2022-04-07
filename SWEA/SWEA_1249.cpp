#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int MAP[100][100];
int used[100][100];
int deep[100][100];

struct Node {
	int y;
	int x;
	int time;
};

struct cmp {
	bool operator()(Node right, Node left) {
		return left.time < right.time;
	}
};

void init(int n) {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			MAP[i][j] = 0;
			used[i][j] = 0;
			deep[i][j] = 9999;
		}
	}
}

int bfs(int n) {
	priority_queue<Node, vector<Node>, cmp> pq;
	int dy[] = { -1, 0, 0, 1 };
	int dx[] = { 0, 1 ,-1, 0 };

	pq.push({ 0,0 });
	used[0][0] = 1;
	deep[0][0] = 0;

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (deep[ny][nx] < deep[now.y][now.x] + MAP[ny][nx]) continue;
			if (used[ny][nx] == 1) continue;
			deep[ny][nx] = deep[now.y][now.x] + MAP[ny][nx];
			used[ny][nx] = 1;
			pq.push({ ny,nx,deep[ny][nx]});
		}
	}
	return deep[n - 1][n - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int Tc = 1; Tc <= tc; Tc++) {
		int n;
		cin >> n;
		init(n);
		string str[100];
		for (int i = 0; i < n; i++) {
			cin >> str[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				MAP[i][j] = (int)str[i][j] - 48;
			}
		}

		int ans = bfs(n);
		cout << "#" << Tc << " " << ans << "\n";
	}

	return 0;
}
