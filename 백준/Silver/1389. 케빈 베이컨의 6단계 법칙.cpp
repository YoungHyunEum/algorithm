#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
	int node;
	int cnt;
};

int N, M;
vector<int> v[101];

int bfs(int s) {
	queue<Node> q;
	int used[101] = { 0 };
	int sum = 0;
	q.push({ s, 0 });
	used[s] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < v[now.node].size(); i++) {
			int nn = v[now.node][i];
			if (used[nn] == 1) continue;
			q.push({ nn, now.cnt + 1 });
			used[nn] = 1;
			sum += now.cnt + 1;
		}
	}

	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ans_cnt = 99999;
	int ans_idx = 0;

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		int temp = bfs(i);
		if (ans_cnt > temp) {
			ans_cnt = temp;
			ans_idx = i;
		}
	}

	cout << ans_idx;

	return 0;
}
