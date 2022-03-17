#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> v[101];
int n, m;
int cnt = 0;

void input() {
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
}

void bfs(int start) {
    queue<int> q;
    int used[101] = { 0, };
    q.push(start);
    used[start] = 1;
    int ans = 0;

    while (!q.empty())
    {
        int now = q.front(); q.pop();
        int de = -1;
        for (int to = 0; to < v[now].size(); to++)
        {       
            if (used[v[now][to]] == 1) continue;
            used[v[now][to]] = 1;
            q.push(v[now][to]);
            cnt++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    bfs(1);

    cout << cnt;

    return 0;
}
