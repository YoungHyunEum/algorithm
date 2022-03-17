#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Node {
    int y;
    int x;
};

int n, m;
vector<int> MAP[101];
int used[101][101];

void bfs(int r, int c) {
    queue<Node> q;
    q.push({ r,c });
    used[r][c] = 1;

    while (!q.empty()) {
        Node now = q.front(); q.pop();

        int dr[] = { -1, 0, 0,1 };
        int dc[] = { 0, -1, 1, 0 };
        for (int i = 0; i < 4; i++)
        {
            int nr = now.y + dr[i];
            int nc = now.x + dc[i];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if (used[nr][nc] != 0) continue;
            if (MAP[nr][nc] == 0) continue;
            used[nr][nc] = used[now.y][now.x] + 1;
            q.push({ nr,nc });
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string num;
        cin >> num;
        for (int j = 0; j < m; j++)
        {
            MAP[i].push_back((int)num[j]-48);
        }
    }
    
    bfs(0, 0);
    
    int de = -1;

    cout << used[n - 1][m - 1];

    return 0;
}
