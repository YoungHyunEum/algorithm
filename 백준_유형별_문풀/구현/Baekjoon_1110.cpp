#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int i = N;
    int cnt = 0;

    do {
        i = (i % 10) * 10 + (i / 10 + i % 10) % 10;
        cnt++;
    } while (i != N);

    cout << cnt;

    return 0;
}
