#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[50001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 1; i * i < 50000; i++) {
        dp[i * i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        if (dp[i] == 1) continue;
        else {
            dp[i] = 99999;
            for (int j = 1; j * j< i; j++) {
                dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
            }
        }
    }

    cout << dp[n];

    return 0;
}