#include <iostream>
#include <math.h>
using namespace std;

int n, m;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int max_num = max(n, m);
    int ans1 = 0;
    int ans2 = 0;

    for (int i = 1; i <= max_num; i++) {
        if (n % i == 0 && m % i == 0) ans1 = max(ans1, i);
    }

    int temp = ans1;

    while (1) {
        if (temp % n == 0 && temp % m == 0) {
            ans2 = temp;
            break;
        }
        temp += ans1;
    }

    cout << ans1 << "\n";
    cout << ans2;

    return 0;
}