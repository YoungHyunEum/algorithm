#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> coin;

int check_coin() {
    int cnt = 0;

    int si = N - 1;
    while (1) {
        if (K <= 0) break;

        for (int i = si; i >= 0; i--) {
            if (K < coin[i]) continue;
            else {
                K -= coin[i];
                si = i;
                cnt++;
                break;
            }
        }
    }

    return cnt;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        coin.push_back(num);
    }

    cout << check_coin();

    return 0;
}