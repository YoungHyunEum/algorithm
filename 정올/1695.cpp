#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Node {
    int r;
    int c;
};

int N;
int map[25][25];
int visited[25][25] = { 0 };
vector<int> ans;
int dr[] = { -1, 0, 0, 1 };
int dc[] = { 0, -1, 1, 0 };

void input() {
    char temp[25][25];
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> temp[i][j];
            map[i][j] = temp[i][j] - 48;
        }
    }
}

void bfs(int sr, int sc) {
    queue<Node> q;
    q.push({ sr, sc });
    visited[sr][sc] = 1;

    int cnt = 1;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
            if (map[nr][nc] == 0 || visited[nr][nc] == 1) continue;
            q.push({ nr, nc});
            visited[nr][nc] = 1;
            cnt++;
        }
    }
    ans.push_back(cnt);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 1 && visited[i][j] == 0) {
                bfs(i, j);
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}
