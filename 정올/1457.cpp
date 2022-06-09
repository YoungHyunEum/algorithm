#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int r;
    int c;
};

int map[100][100];
int visited[100][100];
int M, N, K;
int ans;
vector<int> ans_arr;
int dr[] = { -1, 0, 0, 1 };
int dc[] = { 0, -1, 1, 0 };

void rect(int sx, int sy, int ex, int ey) {
    for (int y = sy; y < ey; y++) {
        for (int x = sx; x < ex; x++) {
            map[y][x] = 1;
        }
    }
}

void bfs(int sr, int sc) {
    ans++;
    queue<Node> q;
    q.push({ sr,sc });
    visited[sr][sc] = 1;
    int cnt = 1;
    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];
            if (nr < 0 || nc < 0 || nr >= M || nc >= N) continue;
            if (visited[nr][nc] == 1 || map[nr][nc] == 1) continue;
            q.push({ nr, nc });
            visited[nr][nc] = 1;
            cnt++;
        }
    }

    ans_arr.push_back(cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> K;

    for (int i = 0; i < K; i++) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        rect(sx, sy, ex, ey);
    }
    
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            if (map[y][x] != 1 && visited[y][x] != 1) bfs(y, x);
        }
    }

    sort(ans_arr.begin(), ans_arr.end());
        
    cout << ans << "\n";
    for (int i = 0; i < ans_arr.size(); i++) {
        cout << ans_arr[i] << " ";
    }

    return 0;
}
