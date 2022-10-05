#include <iostream>
#include <algorithm>
using namespace std;

int N;
int v[1001][3];
int dp[1001][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> v[i][j];
        }
    }

    dp[0][0] = v[0][0];
    dp[0][1] = v[0][1];
    dp[0][2] = v[0][2];

    for (int i = 1; i < N; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + v[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + v[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + v[i][2];
    }

    int ans = 0;
    ans = min(dp[N - 1][0], dp[N - 1][1]);
    ans = min(ans, dp[N - 1][2]);

    cout << ans;

    return 0;
}