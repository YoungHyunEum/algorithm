#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

int v[2][100001];
int dp[2][100001];

void init(int x) {
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < x; j++) {
            dp[i][j] = 0;
            v[i][j] = 0;
        }
    }
}

int bottom_up(int n) {
    dp[0][0] = v[0][0];
    dp[1][0] = v[1][0];
    dp[0][1] = v[0][1] + dp[1][0];
    dp[1][1] = v[1][1] + dp[0][0];

    for (int x = 2; x < n; x++) {
        dp[0][x] = v[0][x] + max(dp[1][x - 1], dp[1][x - 2]);
        dp[1][x] = v[1][x] + max(dp[0][x - 1], dp[0][x - 2]);
    }
    int de = -1;

    return max(dp[0][n - 1], dp[1][n - 1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tc;
    cin >> tc;
    
    for (int Tc = 0; Tc < tc; Tc++) {
        int n;
        cin >> n;
        
        init(n);

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }

        cout << bottom_up(n) << "\n";
        
    }

    return 0;
}
