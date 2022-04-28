#include<iostream>
using namespace std;

struct Node {
    int r;
    int c;
};

int n, m;
int map[500][500];
int max_sum = -999;

Node d[19][4] = {
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {-1, 0}, {-2, 0}, {-3, 0} },
    {{0, 0}, {0, 1}, {-1, 0}, {-1, 1}},
    {{0, 0}, {0, 1}, {-1, 0}, {-2, 0}},
    {{0, 0}, {0, 1}, {-1, 1}, {-2, 1}},
    {{0, 0}, {-1, 0}, {-2, 0}, {-2, 1}},
    {{0, 1}, {-1, 1}, {-2, 1}, {-2, 0}},
    {{0, 0}, {0, 1}, {0, 2}, {-1, 0}},
    {{0, 0}, {0, 1}, {0, 2}, {-1, 2}},
    {{0, 0}, {-1, 0}, {-1, 1}, {-1, 2}},
    {{-1, 0}, {-1, 1}, {-1, 2}, {0, 2}},
    {{-1, 1}, {0, 1}, {-1, 0}, {-2, 0}},
    {{0, 0}, {-1, 0}, {-1, 1}, {-2, 1}},
    {{0, 0}, {0, 1}, {-1, 1}, {-1, 2}},
    {{-1, 0}, {0, 1}, {-1, 1}, {0, 2}},
    {{0, 0}, {-1, 0}, {-2, 0}, {-1, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {-1, 1}},
    {{-1, 0}, {0, 1}, {-1, 1}, {-2, 1}},
    {{-1, 0}, {0, 1}, {-1, 1}, {-1, 2}}
};

void game(int sr, int sc) {
    for (int i = 0; i < 19; i++) {
        bool flag = true;
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            int nr = sr + d[i][j].r;
            int nc = sc + d[i][j].c;
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
                flag = false;
                break;
            }
            sum += map[nr][nc];
        }
        if (flag) {
            if (max_sum < sum) max_sum = sum;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            game(i, j);
        }
    }

    cout << max_sum;

    return 0;
}
