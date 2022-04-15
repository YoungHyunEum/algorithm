#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int point;
	int time;
};

int used[100001] = { 0 };

int bfs(int s, int d) {
	queue<Node> q;
	q.push({ s, 0 });
	used[s] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		if (now.point == d) return now.time;

		if (now.point + 1 <= d && used[now.point + 1] == 0) {
			q.push({ now.point + 1, now.time + 1 });
			used[now.point + 1] = 1;
		}
		if (now.point - 1 >= 0 && used[now.point - 1] == 0) {
			q.push({ now.point - 1, now.time + 1 });
			used[now.point - 1] = 1;
		}
		if (now.point * 2 <= d + 1 && used[now.point * 2] == 0) {
			q.push({ now.point * 2, now.time + 1 });
			used[now.point * 2] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	
	cout << bfs(n, k);

	return 0;
}
