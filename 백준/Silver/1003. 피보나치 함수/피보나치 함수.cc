#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int zero[41] = { 1, 0, };
        int one[41] = { 0, 1, };

        int n;
        cin >> n;
        for (int j = 2; j <= n; j++) {
            zero[j] = zero[j - 2] + zero[j - 1];
            one[j] = one[j - 2] + one[j - 1];
        }

        cout << zero[n] << " " << one[n] << "\n";
    }

    return 0;
}