#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int n, m;
vector<int> card;
int path[3];
int used[100];
int ans = 0;

void dfs(int x) {
    if (x == 3) {
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += path[i];
        }
        if (sum <= m) ans = max(ans, sum);

        return;
    }

    for (int i = 0; i < card.size(); i++) {
        if (used[i] == 1) continue;
        path[x] = card[i];
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

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        card.push_back(num);
    }

    dfs(0);

    cout << ans;

    return 0;
}