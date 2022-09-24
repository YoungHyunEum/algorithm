#include <iostream>
using namespace std;

int T;
long long dp[101];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    dp[6] = 3;
    dp[7] = 4;
    dp[8] = 5;
    dp[9] = 7;

    for (int i = 6; i <= 100; i++) {
        dp[i] = dp[i - 5] + dp[i - 1];
    }

    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    

    return 0;
}