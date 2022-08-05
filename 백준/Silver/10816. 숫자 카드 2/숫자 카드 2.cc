#include <iostream>
using namespace std;

struct Node {
    int minus;
    int plus;
};

int N, M;
Node arr[10000001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        if (n < 0) arr[-n].minus++;
        else arr[n].plus++;
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int m;
        cin >> m;
        if (m == 0) cout << arr[0].plus << " ";
        else if (m < 0) cout << arr[-m].minus << " ";
        else cout << arr[m].plus << " ";
    }

    return 0;
}