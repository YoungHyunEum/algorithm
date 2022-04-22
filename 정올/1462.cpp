#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

struct Node {
    int r;
    int c;
    int dist;
};

int n, m;
char map[50][51];
int visited[50][50];
int ans = -1;
int dr[] = { -1, 0, 0, 1 };
int dc[] = { 0, -1, 1, 0 };

void bfs(int sr, int sc) {
    queue<Node> q;
    q.push({ sr, sc, 0 });
    visited[sr][sc] = 1;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        if (ans < now.dist) ans = now.dist;

        for (int i = 0; i < 4; i++) {
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if (visited[nr][nc] == 1) continue;
            if (map[nr][nc] == 'W') continue;
            q.push({ nr, nc, now.dist + 1 });
            visited[nr][nc] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'L') {
                bfs(i, j);
                memset(visited, 0, sizeof(visited));
            }
        }
    }

    cout << ans;

    return 0;
}
