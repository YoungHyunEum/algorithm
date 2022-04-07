#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

string v[101];
int n;
int used1[101][101];
int used2[101][101];
int ans1 = 0;
int ans2 = 0;

struct Node {
	int y;
	int x;
	char color;
};

int bfs1(int y, int x) {
	queue<Node> q;
	ans1 = 1;
	q.push({ y,x, v[y][x]});
	used1[y][x] = 1;

	int dy[] = { -1, 0, 0, 1 };
	int dx[] = { 0, 1, -1, 0 };

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (used1[ny][nx] == 1) continue;
			if (now.color == v[ny][nx]) {
				q.push({ ny, nx, v[ny][nx] });
				used1[ny][nx] = 1;
				ans1++;
			}
		}
	}

	return ans1;
}

int bfs2(int y, int x) {
	queue<Node> q;
	ans1 = 1;
	q.push({ y,x, v[y][x] });
	used2[y][x] = 1;

	int dy[] = { -1, 0, 0, 1 };
	int dx[] = { 0, 1, -1, 0 };

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (used2[ny][nx] == 1) continue;
			if ((now.color == 'R' || now.color == 'G') && (v[ny][nx] == 'R' || v[ny][nx] == 'G')) {
				q.push({ ny, nx, v[ny][nx] });
				used2[ny][nx] = 1;
				ans2++;
			}
			else if (now.color == v[ny][nx]) {
				q.push({ ny, nx, v[ny][nx] });
				used2[ny][nx] = 1;
				ans2++;
			}
		}
	}
	return ans2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int area1 = 0;
	int area2 = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int cnt1 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (used1[i][j] == 0) {
				cnt1 += bfs1(i, j);
				area1++;
			}
			if (cnt1 == n * n) {
				break;
			}
		}
	}

	int cnt2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (used2[i][j] == 0) {
				cnt2 += bfs2(i, j);
				area2++;
			}
			if (cnt2 == n * n) {
				break;
			}
		}
	}

	cout << area1 << " " << area2;

	return 0;
}
