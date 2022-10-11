#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int R, C, T;
int map[50][50];
int temp[50][50];
int dr[] = { -1, 0, 0, 1 };
int dc[] = { 0, -1, 1, 0 };
vector<pair<int, int>> air;

void diffusion(int sr, int sc){
    int sub = map[sr][sc] / 5;
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        int nr = sr + dr[i];
        int nc = sc + dc[i];
        if (nr >= R || nc >= C || nr < 0 || nc < 0) continue;
        if (map[nr][nc] == -1) continue;
        temp[nr][nc] += sub;
        sum += sub;
    }
    temp[sr][sc] += map[sr][sc] - sum;
}

void dust() {
    memset(temp, 0, sizeof(temp));

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (map[r][c] >= 1) {
                diffusion(r, c);
            }
        }
    }

    memcpy(map, temp, sizeof(temp));
    for (int i = 0; i < 2; i++) {
        map[air[i].first][air[i].second] = -1;
    }
}

void fresh_air() {
    int top_r[] = { 0, -1, 0, 1 };
    int top_c[] = { 1, 0, -1, 0 };
    int bot_r[] = { 0, 1, 0, -1 };
    int bot_c[] = { 1, 0, -1, 0 };
    for (int i = 0; i < 2; i++) {
        int fr = air[i].first;
        int fc = air[i].second + 1;
        int n = map[fr][fc];
        map[fr][fc] = 0;

        int dir = 0;
        while (1) {
            int nr, nc;
            if (i == 0) {
                nr = fr + top_r[dir];
                nc = fc + top_c[dir];
            }
            else {
                nr = fr + bot_r[dir];
                nc = fc + bot_c[dir];
            }

            if (nr >= R || nc >= C || nr < 0 || nc < 0) {
                dir++;
                continue;
            }

            if (map[nr][nc] == -1) break;

            int tmp = map[nr][nc];
            map[nr][nc] = n;
            n = tmp;

            fr = nr;
            fc = nc;
        }
    }
}

int check_dust() {
    int ans = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] >= 1) {
                ans += map[i][j];
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

    cin >> R >> C >> T;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            if (map[i][j] == -1) air.push_back({ i,j });
        }
    }
    
    for (int i = 0; i < T; i++) {
        dust();
        fresh_air();
    }

    cout << check_dust();

    return 0;
}