#include <iostream>
#include <stack>
#include <string>
using namespace std;

int n, k;

int factorial(int x) {
    int gop = 1;

    for (int i = x; i >= 1; i--) {
        gop *= i;
    }
    return gop;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    int ans = factorial(n) / (factorial(k) * factorial(n - k));
    cout << ans;

    return 0;
}