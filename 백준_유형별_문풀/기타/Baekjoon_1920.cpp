#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<long long> v;

int BS(int s, int e, int target) {
    while (s <= e) {
        int mid = (s + e) / 2;
        if (v[mid] == target) return 1;
        else if (v[mid] > target) e = mid - 1;
        else if (v[mid] < target) s = mid + 1;
    }
    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        long long num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    cin >> M;
    for (int i = 0; i < M; i++) {
        long long num;
        cin >> num;
        
        cout << BS(0, N - 1, num) << "\n";
    }

    return 0;
} 
