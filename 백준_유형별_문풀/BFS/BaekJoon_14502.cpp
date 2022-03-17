#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

struct Node {
    int r;
    int c;
};

int n, m;
int MAP[9][9];
int used[9][9];
int maxAns = -1;

int bfs() {
    queue<Node> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) {
            if (MAP[i][j] == 2) q.push({ i,j });
        }
    }
    int LAB[9][9];
    memcpy(LAB, MAP, sizeof(MAP));
    while (!q.empty()) {
        Node now = q.front(); q.pop();
        
        int dr[] = { -1,0,0,1 };
        int dc[] = { 0, 1, -1, 0 };

        for (int i = 0; i < 4; i++)
        {
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if (LAB[nr][nc] == 1 || LAB[nr][nc] == 2) continue;
            LAB[nr][nc] = 2;
            q.push({ nr,nc });
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) {
            if (LAB[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

void dfs(int level) {
    if (level == 3) {
        int ans = bfs();
        if (maxAns < ans) maxAns = ans;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) {
            if (used[i][j] == 1) continue;
            if (MAP[i][j] == 0) {
                MAP[i][j] = 1;
                dfs(level + 1);
                MAP[i][j] = 0;
            }
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
        for (int j = 0; j < m; j++) {
            cin >> MAP[i][j];
        }
    }

    bfs();
    dfs(0);

    cout << maxAns;

    return 0;
}
