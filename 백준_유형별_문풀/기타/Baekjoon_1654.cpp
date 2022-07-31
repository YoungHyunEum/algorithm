#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int k, n;
vector<long long> v;
long long max_len = 0;
long long ans = 0;
int s_mid = 0;

bool cutting(long long s) {
    long long sum = 0;
    for (long long i = 0; i < v.size(); i++) {
        sum += v[i] / s;
    }

    if (sum >= n) return true;
    else return false;
}

void BS(long long s, long long e) {
    while (s <= e) {
        long long mid = (s + e) / 2;
        if (cutting(mid)) {
            s = mid + 1;
            ans = max(ans, mid);
        }
        else e = mid - 1;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        long long len;
        cin >> len;
        v.push_back(len);
        max_len = max(max_len, len);
    }
    
    BS(1, max_len);
    
    cout << ans;

    return 0;
}
