#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
int btn[10];
int ans = 999999;

bool check(int num) {
    string s = to_string(num);
    for (int i = 0; i < s.size(); i++) {
        int x = (int)s[i] - 48;
        if (btn[x]) return false;
    }
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt = 0;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        btn[num] = 1;
        cnt++;
    }

    ans = abs(N - 100);

    if (N == 100) ans = 0;
    else {
        for (int i = 0; i <= 1000000; i++) {
            if (check(i)) {
                string s = to_string(i);
                int diff = abs(N - i) + s.size();
                ans = min(ans, diff);
            }
        }
    }

    cout << ans;

    return 0;
}