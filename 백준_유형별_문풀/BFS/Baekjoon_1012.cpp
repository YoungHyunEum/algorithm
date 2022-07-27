#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int r;
    int c;
};

int map[50][50] = { 0 };
int N, M, K;

void input() {
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        map[y][x] = 1;
    }
}

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            map[i][j] = 0;
        }
    }
}

void bfs(int sr, int sc) {
    int dr[] = { -1, 0, 0, 1 };
    int dc[] = { 0, -1, 1, 0 };
    queue<Node> q;
    q.push({ sr,sc });
    map[sr][sc] = 2;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if (map[nr][nc] == 1) {
                q.push({ nr, nc });
                map[nr][nc] = 2;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int ans = 0;
        input();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 1) {
                    bfs(i, j);
                    ans++;
                }
            }
        }

        init();

        cout << ans << "\n";
    }
    return 0;
}
