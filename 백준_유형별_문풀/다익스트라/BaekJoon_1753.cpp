#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
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

vector<Node> MAP[20000];
int V, E, K;

void dijkstra_pq()
{
    vector<int> dist(V + 1, 213456789);
    vector<int> used(V + 1, 0);

    priority_queue<Node, vector<Node>, cmp> pq;

    dist[K] = 0;
    pq.push({ K,0 });

    while (!pq.empty()) {
        Node now = pq.top();
        pq.pop();

        int nowTo = now.to;
        int nowCost = now.cost;
        if (used[nowTo] == 1) continue;
        used[nowTo] = 1;

        for (int i = 0; i < MAP[nowTo].size(); i++)
        {
            Node node = MAP[nowTo][i];
            int t = node.to;
            int c = node.cost;

            if (dist[t] <= dist[nowTo] + c) continue;
            dist[t] = dist[nowTo] + c;
            pq.push({ t, dist[t] });
        }
    }
    for (int i = 1; i <= V; i++)
    {
        if (dist[i] != 213456789) cout << dist[i] << "\n";
        else {
            cout << "INF\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    cin >> K;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        MAP[u].push_back({ v,w });
    }

    dijkstra_pq();

    return 0;
}
