#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int N, M;
vector<int> tree;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int h;
        cin >> h;
        tree.push_back(h);
    }

    sort(tree.begin(), tree.end());

    int s = 1;
    int e = tree[tree.size() - 1];
    int ans = 0;

    while (s <= e) {
        int mid = (s + e) / 2;
        long long cut = 0;
        for (int i = 0; i < tree.size(); i++) {
            if(tree[i] > mid) cut += (tree[i] - mid);
        }
        if (cut >= M) {
            s = mid + 1;
            ans = max(ans, mid);
        }
        else if (cut < M) e = mid - 1;
    }

    cout << ans;

    return 0;
}