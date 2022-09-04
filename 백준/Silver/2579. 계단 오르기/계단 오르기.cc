#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;
vector<int> dp;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    dp = vector<int>(N + 1);
    v = vector<int>(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    dp[0] = 0;
    dp[1] = v[1];
    dp[2] = v[1] + v[2];
    dp[3] = max(v[1] + v[3], v[2] + v[3]);

    for (int i = 4; i <= N; i++) {
        dp[i] = max(dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i]);
    }

    cout << dp[N];

    return 0;
}