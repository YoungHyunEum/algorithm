#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
vector<int> rail;
int min_ans = 99999;
vector<int> v;

int weight() {
    int cur = 0, sum = 0;
    for (int i = 0; i < K; i++) {
        int r = M;
        while (1) {
            r -= v[cur];
            if (r < 0) break;
            sum += v[cur++];
            cur %= N;
        }
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        rail.push_back(a);
    }

    sort(rail.begin(), rail.end());

    do {
        for (int i = 0; i < N; i++) {
            v.push_back(rail[i]);
        }
        min_ans = min(weight(), min_ans);
        v.clear();
    } while (next_permutation(rail.begin(), rail.end()));

    cout << min_ans;

    return 0;
}
