#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> v;
vector<int> used;
vector<int> path;

void dfs(int x) {
    if (x == M) {
        for (int j = 0; j < M; j++) {
            cout << path[j] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        if (path.empty() || (!path.empty() && path[x - 1] <= v[i])) {
            path.push_back(v[i]);
            dfs(x + 1);
            path.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    v = vector<int>(N);
    used = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    dfs(0);

    return 0;
}