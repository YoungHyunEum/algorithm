#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    v = vector<int>(N + 1);

    v[0] = 0;
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        v[i] = v[i - 1] + num;
    }

    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        int sum = v[e] - v[s - 1];

        cout << sum << "\n";
   }

    return 0;
}