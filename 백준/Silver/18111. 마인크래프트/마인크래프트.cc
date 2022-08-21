#include <iostream>
#include <math.h>
using namespace std;

int N, M, B;
int map[501][501];
int max_h = -1;
int min_h = 999;
int ans_time = 0x7f7f7f7f;
int ans_height = 0;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> B;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            max_h = max(max_h, map[i][j]);
            min_h = min(min_h, map[i][j]);
        }
    }

    for (int i = 0; i <= 256; i++) {
        int build = 0;
        int remove = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                int height = map[y][x] - i;
                if (height > 0) remove += height;
                else if (height < 0) build -= height;
            }
        }

        if (remove + B >= build) {
            int t = remove * 2 + build;
            if (ans_time >= t) {
                ans_time = t;
                ans_height = i;
            }
        }
    }

    cout << ans_time << " " << ans_height;

    return 0;
}