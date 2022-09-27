#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int path[10];
int used[10];

bool check() {
    if (M == 1) return true;
    else {
        for (int i = 1; i < M; i++) {
            if (path[i - 1] > path[i]) return false;
        }
    }
    return true;
}

void dfs(int x) {
    if (x == M) {
        if (check()) {
            for (int i = 0; i < M; i++) {
                cout << path[i] << " ";
            }
            cout << "\n";
        }
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (used[i] == 1) continue;
        path[x] = i;
        used[i] = 1;
        dfs(x + 1);
        path[x] = 0;
        used[i] = 0;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    dfs(0);

    return 0;
}