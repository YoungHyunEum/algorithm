#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
//baekjoon 2468
struct Node {
	int r;
	int c;
};

int N;
int map[100][100];
int max_water;
int used[100][100];
int dr[] = { -1 ,0, 0, 1 };
int dc[] = { 0, -1, 1, 0 };

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			used[i][j] = 0;
		}
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			max_water = max(max_water, map[i][j]);
		}
	}
}

void bfs(int sr, int sc, int wh) {
	queue<Node> q;
	q.push({ sr,sc });
	used[sr][sc] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = now.r + dr[i];
			int nc = now.c + dc[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
			if (used[nr][nc] != 0 || map[nr][nc] <= wh) continue;
			used[nr][nc] = 1;
			q.push({ nr, nc });
		}
	}
}

int main() {

	int ans = 0;
	int water_height = 0;
	int cnt = 0;
	input();

	while (water_height <= max_water) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (used[i][j] != 0 || map[i][j] <= water_height) continue;
				bfs(i, j, water_height);
				cnt++;
			}
		}
		water_height++;
		init();
		ans = max(ans, cnt);
		cnt = 0;
	}

	cout << ans;

	return 0;
}
