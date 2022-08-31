#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

struct Node {
	int s;
	int cnt;
};


int N, M;
int map[101] = { 0 };
int used[101] = { 0 };

int bfs() {
	int ans = 99999;
	queue<Node> q;
	q.push({ 1,0 });
	used[1] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int nf = now.s + i;
			if (nf >= 100) {
				ans = min(ans, now.cnt + 1);
				break;
			}
			if (used[nf]) continue;
			if (map[nf] == 0) q.push({ nf, now.cnt + 1 });
			else q.push({ map[nf], now.cnt + 1 });
			used[nf] = 1;
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N + M; i++) {
		int from, to;
		cin >> from >> to;
		map[from] = to;
	}

	cout << bfs();

	return 0;
}
