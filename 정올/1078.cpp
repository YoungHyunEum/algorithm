#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

struct Node {
    int r;
    int c;
    int sec;
};

int m, n, sr, sc;
int map[100][100];
char temp[101][101];
int visited[100][100] = { 0 };
int dr[] = { -1, 0, 0, 1 };
int dc[] = { 0, -1, 1, 0 };

int bfs() {
    queue<Node> q;
    q.push({ sr - 1,sc - 1 , 3});
    visited[sr - 1][sc - 1] = 1;

    int max_sec = 0;
    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        if (max_sec < now.sec) max_sec = now.sec;
        for (int i = 0; i < 4; i++) {
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if (visited[nr][nc]) continue;
            if (map[nr][nc] == 0) continue;
            q.push({ nr, nc, now.sec + 1 });
            visited[nr][nc] = 1;
        }
    }
    return max_sec;
}

int check_alive() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] != visited[i][j]) cnt++;
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> temp[i][j];
            map[i][j] = temp[i][j] - 48;
        }
    }
    cin >> sc >> sr;

    cout << bfs() << "\n";
    cout << check_alive();

    return 0;
}
