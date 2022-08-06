#include <iostream>
#include <string>
using namespace std;

int N;
int ans;

bool check(int x) {
    string num = to_string(x);
    int sum = 0;
    for (int i = 0; i < num.size(); i++) {
        sum += (int)num[i] - 48;
    }
    if (x + sum == N) return true;
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        if (check(i)) {
            ans = i;
            break;
        }
    }

    cout << ans;

    return 0;
}