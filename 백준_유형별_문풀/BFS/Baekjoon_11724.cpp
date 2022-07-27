#include <iostream>
#include <queue>
using namespace std;

vector<int> v[1001];
int visited[1001] = { 0 };
int N, M;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < v[now].size(); i++) {
            int n = v[now][i];
            if (visited[n] == 1) continue;
            q.push(n);
            visited[n] = 1;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int t, f;
        cin >> t >> f;
        v[t].push_back(f);
        v[f].push_back(t);
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (visited[i] == 0) {
            bfs(i);
            ans++;
        }
    }

    cout << ans;

    return 0;
}
