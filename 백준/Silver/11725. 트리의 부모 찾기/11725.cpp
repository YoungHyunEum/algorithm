#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> v[100001];
int parent_node[100001];
int used[100001];

void bfs() {
    queue<int> q;
    q.push(1);
    parent_node[1] = 1;

    while (!q.empty()) {
        int now_node = q.front();
        q.pop();

        for (int i = 0; i < v[now_node].size(); i++) {
            int next_node = v[now_node][i];
            if (parent_node[next_node] != 0) continue;
            q.push(next_node);
            parent_node[next_node] = now_node;
        }
    }
}

void dfs(int x, int now) {
    if (x == N) return;
    
    for (int i = 0; i < v[now].size(); i++) {
        int next_node = v[now][i];
        if (used[next_node] == 1) continue;
        used[next_node] = 1;
        parent_node[next_node] = now;
        dfs(x + 1, next_node);
        used[next_node] = 0;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    //bfs();
    
    used[1] = 1;
    dfs(0, 1);

    for (int i = 2; i <= N; i++) {
        cout << parent_node[i] << "\n";
    }

    return 0;
}
