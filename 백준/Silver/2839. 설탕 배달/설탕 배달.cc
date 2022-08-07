#include <iostream>
using namespace std;

int N;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int five = N / 5;
    int three = 0;

    while (1) {
        if (five < 0) {
            if (N == 3) cout << "1";
            else cout << "-1";
            return 0;
        }
        if ((N - (5 * five)) % 3 == 0) {
            three = (N - (5 * five)) / 3;
            break;
        }
        five--;
    }

    cout << five + three;

    return 0;
}