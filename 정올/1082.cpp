#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

struct Node {
    int r;
    int c;
    int time;
};

struct cmp {
    bool operator()(Node right, Node left) {
        return left.time < right.time;
    }
};

int R, C;
char map[50][51];
int visited[50][51] = { 0 };
int sr, sc, desti_r, desti_c;
int dr[] = { -1, 0, 0, 1 };
int dc[] = { 0, -1, 1, 0 };

void input() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'S') {
                sr = i;
                sc = j;
            }
            else if (map[i][j] == 'D') {
                desti_r = i;
                desti_c = j;
            }
        }
    }
}

void fire() {
    char temp[50][51];
    memcpy(temp, map, sizeof(map));
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (map[r][c] == '*' ) {
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
                    if (map[nr][nc] == 'X' || map[nr][nc] == 'D' || map[nr][nc] == 'S') continue;
                    temp[nr][nc] = '*';
                }
            }
        }
    }
    memcpy(map, temp, sizeof(temp));
}

int bfs() {
    priority_queue<Node, vector<Node>, cmp> q;
    q.push({ sr, sc, 0 });
    visited[sr][sc] = 1;

    int t = 0;
    int ans = 9999;
    while (!q.empty()) {
        Node now = q.top();
        q.pop();
        if (now.r == desti_r && now.c == desti_c) {
            if (ans > now.time) ans = now.time;
        }
        if (t != now.time) {
            fire();
            t = now.time;
        }
        if (map[now.r][now.c] == '*') continue;
        for(int i = 0; i < 4; i++){
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];
            if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
            if (map[nr][nc] == '*' || map[nr][nc] == 'X') continue;
            if (visited[nr][nc] == 1) continue;
            visited[nr][nc] = 1;
            q.push({ nr,nc, now.time + 1 });
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    int min_time = bfs();
    if (min_time != 9999) cout << min_time;
    else cout << "impossible";
    
    return 0;
}
