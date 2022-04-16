#include<iostream>
#include<queue>
#include<math.h>
#include<vector>
#include<cstring>
using namespace std;

struct Node {
    int r;
    int c;
};

int map[50][50];
int temp[50][50];
int used[50][50] = {0};
int N, L, R;
int dr[] = { -1, 0, 0, 1 };
int dc[] = { 0, -1, 1, 0 };
int day = 0;
int sr, sc;

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            used[i][j] = 0;
        }
    }
}

bool check(int r, int c) {
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
        int sub = abs(map[r][c] - map[nr][nc]);
        if (sub >= L && sub <= R) return true;
    }
    return false;
}

void bfs(int sr, int sc) {
    queue<Node> q;
    vector<Node> v;
    int country_cnt = 0;
    q.push({ sr,sc });
    used[sr][sc] = 1;
    country_cnt = 1;
    v.push_back({ sr, sc });
    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
            if (used[nr][nc] != 0) continue;
            int sub = abs(map[now.r][now.c] - map[nr][nc]);
            if (sub >= L && sub <= R) {
                q.push({ nr, nc });
                country_cnt++;
                used[nr][nc] = 1;
                v.push_back({ nr,nc });
            }
        }
    }
    int population = 0;

    for (int i = 0; i < v.size(); i++) {
        population += map[v[i].r][v[i].c];
    }
    population = population / country_cnt;

    for (int i = 0; i < v.size(); i++) {
        temp[v[i].r][v[i].c] = population;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    int flag = 1;
    while (flag) {
        int cnt = 0;
        memcpy(temp, map, sizeof(map));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (check(i, j)) {
                    bfs(i, j);
                    init();
                    cnt++;
                }
            }
        }
        memcpy(map, temp, sizeof(map));
        if (cnt == 0) flag = 0;
        else day++;
    }

    cout << day;

    return 0;
}
