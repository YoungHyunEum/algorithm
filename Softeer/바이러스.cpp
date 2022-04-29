#include<iostream>
using namespace std;

unsigned long long K, P, N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K >> P >> N;

    for (int i = 0; i < N; i++) {
        K = (K * P) % 1000000007;
    }

    cout << K;

    return 0;
}
