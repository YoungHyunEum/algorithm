#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node {
	int to;
	int cow;
};

struct cmp {
	bool operator()(Node right, Node left) {
		if (left.cow < right.cow) return true;
		if (left.cow > right.cow) return false;
		return left.to < right.to;
	}
};

int n, m;
vector<vector<Node>> v;
int min_cost() {
	priority_queue<Node, vector<Node>, cmp> pq;
	vector<int> cost(n + 1, 213456789);
	vector<int> used(n + 1, 0);

	cost[1] = 0;
	pq.push({ 1, 0 });

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		if (used[now.to] == 1) continue;
		used[now.to] = 1;
		for (int i = 0; i < v[now.to].size(); i++) {
			Node go = v[now.to][i];
			if (cost[go.to] <= cost[now.to] + go.cow) continue;
			cost[go.to] = cost[now.to] + go.cow;
			pq.push({ go.to, cost[go.to] });
		}
	}
	return cost[n];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	v = vector<vector<Node>>(n + 1, vector<Node>());
	for (int i = 0; i < m; i++)
	{
		int f, t, c;
		cin >> f >> t >> c;
		v[f].push_back({ t,c });
		v[t].push_back({ f,c });
	}

	cout << min_cost();

	return 0;
}
