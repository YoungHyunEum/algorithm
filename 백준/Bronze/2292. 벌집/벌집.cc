#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int i = 1;
    int gop = 1;
    while (1) {
        gop += 6 * i;
        if (gop >= n) break;
        i++;
    }

    if (n == 1) cout << 1;
    else cout << i + 1;

    return 0;
}