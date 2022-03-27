#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node {
	int to;
	int distance;
};

struct cmp {
	bool operator()(Node right, Node left) {
		if (left.distance < right.distance) return true;
		if (left.distance > right.distance) return false;
		return left.to < right.to;
	}
};

int n, m, x;
vector<Node> v[1001];

int dijkstra_go(int s) {
	priority_queue<Node, vector<Node>, cmp> pq;
	vector<int> dist(n + 1, 213456789);
	vector<int> used(n + 1, 0);

	dist[s] = 0;
	pq.push({ s, 0 });

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		if (used[now.to] == 1) continue;
		used[now.to] = 1;
		for (int i = 0; i < v[now.to].size(); i++) {
			Node node = v[now.to][i];
			int t = node.to;
			int d = node.distance;

			if (dist[t] <= dist[now.to] + d) continue;
			dist[t] = dist[now.to] + d;
			pq.push({ t, dist[t] });
		}
	}

	return dist[x];
}

int dijkstra_back() {
	priority_queue<Node, vector<Node>, cmp> pq;
	vector<int> dist(n+1, 213456789);
	vector<int> used(n + 1, 0);

	dist[x] = 0;
	pq.push({ x, 0 });

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		if (used[now.to] == 1) continue;
		used[now.to] = 1;
		for (int i = 0; i < v[now.to].size(); i++) {
			Node node = v[now.to][i];
			int t = node.to;
			int d = node.distance;

			if (dist[t] <= dist[now.to] + d) continue;
			dist[t] = dist[now.to] + d;
			pq.push({ t, dist[t] });
		}
	}
	int max_dist = -1;
	for (int i = 1; i <= n; i++)
	{
		int a = dijkstra_go(i);
		dist[i] += a;
		if (max_dist < dist[i]) max_dist = dist[i];
	}
	
	return max_dist;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}

	cout << dijkstra_back();

	return 0;
}
