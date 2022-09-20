#include <iostream>
#include <queue>
using namespace std;

int N;
int map[100][100];
int ans[100][100];

int bfs(int s, int e) {
    queue<int> q;
    q.push(s);
    int used[100] = {0};

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < N; i++) {
            if (map[now][i] == 0) continue;
            if (used[i] == 1) continue;
            if (i == e) return 1;
            q.push(i);
            used[i] = 1;
        }
    }

    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << bfs(i, j) << " ";
        }
        cout << "\n";
    }

    return 0;
}