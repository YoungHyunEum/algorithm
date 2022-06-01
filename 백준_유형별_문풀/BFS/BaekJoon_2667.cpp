#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

struct Node {
	int r;
	int c;
};

int N;
int map[25][25];
int ans_cnt;
vector<int> ans;
int visited[25][25];
int dr[] = { -1, 0, 0, 1 };
int dc[] = { 0, -1, 1, 0 };

void bfs(int sr, int sc) {
	queue<Node> q;
	q.push({ sr, sc });
	visited[sr][sc] = 1;
	int cnt = 1;
	ans_cnt++;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = now.r + dr[i];
			int nc = now.c + dc[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
			if (map[nr][nc] == 0 || visited[nr][nc] == 1) continue;
			visited[nr][nc] = 1;
			q.push({ nr,nc });
			cnt++;
		}
	}
	ans.push_back(cnt);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string num;
		cin >> num;
		for (int j = 0; j < num.size(); j++) {
			map[i][j] = (int)num[j] - 48;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 1 || map[i][j] == 0) continue;
			bfs(i, j);
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans_cnt << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}
