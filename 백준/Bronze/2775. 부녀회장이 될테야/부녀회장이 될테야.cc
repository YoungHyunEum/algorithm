#include <iostream>
using namespace std;

int home[15][15];

void init() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            home[i][j] = 0;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        int k, n;
        cin >> k;
        cin >> n;

        for (int y = 0; y <= k; y++) {
            for (int x = 1; x <= n; x++) {
                if (y == 0) home[y][x] = x;
                else {
                    for (int i = 1; i <= x; i++) {
                        home[y][x] += home[y - 1][i];
                    }
                }
            }
        }

        cout << home[k][n] << "\n";
        init();
    }

    return 0;
}