#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

struct Node {
    int r;
    int c;
    int d;
};

int n, m;
int sr, sc, sd;
int map[50][50];
int visited[50][50] = { 0 };
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, -1, 0, 1 };

int bfs() {
    queue<Node> q;
    q.push({ sr, sc, sd });
    visited[sr][sc] = 1;
    int ans = 1;

    while (!q.empty())
    {
        Node now = q.front();
        q.pop();

        int cnt = 0;
        for (int i = 1; i <= 4; i++) {
            int t = (now.d + i) % 4;
            int nr = now.r + dr[t];
            int nc = now.c + dc[t];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
                cnt++;
                continue;
            }
            if (map[nr][nc] == 1 || visited[nr][nc] == 1) {
                cnt++;
                continue;
            }
            q.push({ nr,nc, t });
            visited[nr][nc] = 1;
            ans++;
            break;
        }
        if (cnt == 4) {
            if (now.d == 0) {
                int nr = now.r + dr[2];
                int nc = now.c + dc[2];
                if (map[nr][nc] == 1) break;
                if (map[nr][nc] == 0) q.push({ nr,nc, 0 });
            }
            else if (now.d == 1) {
                int nr = now.r + dr[3];
                int nc = now.c + dc[3];
                if (map[nr][nc] == 1) break;
                if (map[nr][nc] == 0) q.push({ nr,nc, 1 });
            }
            else if (now.d == 2) {
                int nr = now.r + dr[0];
                int nc = now.c + dc[0];
                if (map[nr][nc] == 1) break;
                if (map[nr][nc] == 0) q.push({ nr,nc, 2 });
            }
            else if (now.d == 3) {
                int nr = now.r + dr[1];
                int nc = now.c + dc[1];
                if (map[nr][nc] == 1) break;
                if (map[nr][nc] == 0) q.push({ nr,nc, 3 });
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test = 0;

    cin >> n >> m;
    cin >> sr >> sc >> sd;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) test++;
        }
    }

    if (sd == 1) sd = 3;
    else if (sd == 3) sd = 1;

    cout << bfs();

    return 0;
}
