#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node {
	int to;
	int cost;
};

struct cmp {
	bool operator()(Node right, Node left) {
		if (left.cost < right.cost) return true;
		if (left.cost > right.cost) return false;
		return left.to < right.to;
	}
};

int n, m;
vector<Node> bus[1001];
int s, e;

int bus_stop() {
	priority_queue<Node, vector<Node>, cmp> pq;
	vector<int> cost(n + 1, 213456789);
	vector<int> used(n + 1, 0);

	cost[s] = 0;
	pq.push({ s, 0 });

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		if (used[now.to] == 1) continue;
		used[now.to] = 1;

		for (int i = 0; i < bus[now.to].size(); i++) {
			Node go = bus[now.to][i];
			if (cost[go.to] <= cost[now.to] + go.cost) continue;
			cost[go.to] = cost[now.to] + go.cost;
			pq.push({ go.to, cost[go.to] });
		}
	}
	return cost[e];
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		bus[a].push_back({ b,c });
	}
	cin >> s >> e;

	cout << bus_stop();

	return 0;
}
