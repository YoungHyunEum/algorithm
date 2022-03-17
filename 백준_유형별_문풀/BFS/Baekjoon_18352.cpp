#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> v[300001];
int cost[300001] = {0,};
int n, m, k, x;
vector<int> ans;

void input() {
    cin >> n >> m >> k >> x;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    
}

void bfs(int start) {
    queue<int> q;
    cost[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        
        for (int to = 0; to < v[now].size(); to++)
        {
            if (cost[v[now][to]] == 0 && v[now][to] != start) {
                cost[v[now][to]] = cost[now] + 1;
                q.push(v[now][to]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    bfs(x);

    int flag = 0;
    for (int i = 0; i <= n; i++)
    {
        if (cost[i] == k) {
            cout << i << "\n";
            flag = 1;
        }
    }
    if (!flag) cout << -1;
    
    return 0;
}
