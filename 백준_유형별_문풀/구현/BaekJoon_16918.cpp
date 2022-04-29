#include<iostream>
#include<cstring>
using namespace std;

int R, C, N;
char map[200][201];
char temp[200][201];
int dr[] = { -1, 0, 0, 1 };
int dc[] = { 0, -1, 1, 0 };

void bomb() {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (temp[r][c] == 'O') {
                map[r][c] = '.';
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
                    map[nr][nc] = '.';
                }
            }
        }
    }
}

void C4() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] == '.') map[i][j] = 'O';
        }
    }
}

void output() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << map[i][j];
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> N;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }

    if (N == 1) {
        output();
    }
    else {
        for (int i = 2; i <= N; i++) {
            if (i % 2 == 0) {
                memcpy(temp, map, sizeof(map));
                C4();
            }
            else {
                bomb();
            }
        }
        output();
    }

    return 0;
}
