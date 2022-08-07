#include <iostream>
#include <string>
using namespace std;
#define MOD 1234567891

int L;
string s;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L >> s;

    long long result = 0;
    long long temp = 1;

    for (int i = 0; i < L; i++) {
        result += ((s[i] - 'a' + 1) * temp) % MOD;
        temp *= 31;
        temp %= MOD;
    }

    cout << result % MOD;

    return 0;
}