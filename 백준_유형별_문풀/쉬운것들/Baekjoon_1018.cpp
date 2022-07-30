#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int N, M;
char map[51][51];
char v1[8][8];
char v2[8][8];
int dr[] = { -1, -1, 1, 1 };
int dc[] = { -1, 1, 1, -1 };
int min_chg = 9999;

void check_min(int sr, int sc) {
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (map[sr + i][sc + j] != v1[i][j]) cnt1++;
            if (map[sr + i][sc + j] != v2[i][j]) cnt2++;
        }
    }
    int min_rt = min(cnt1, cnt2);
    min_chg = min(min_chg, min_rt);
}

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> map[i];
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                v1[i][j] = 'W';
                v2[j][i] = 'B';
            }
            else if (i% 2 == 0 && j % 2 ==1) {
                v1[i][j] = 'B';
                v2[j][i] = 'W';
            }
            else if (i % 2 == 1 && j % 2 == 1) {
                v1[i][j] = 'W';
                v2[j][i] = 'B';
            }
            else if (i % 2 == 1 && j % 2 == 0) {
                v1[i][j] = 'B';
                v2[j][i] = 'W';
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            check_min(i, j);
        }
    }

    cout << min_chg;

    return 0;
}
