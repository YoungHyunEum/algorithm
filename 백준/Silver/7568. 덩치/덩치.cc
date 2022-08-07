#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int w;
    int h;
    int rank;
};

int n;
vector<Node> v;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({ x, y, 0 });
    }

    for (int i = 0; i < n; i++) {
        int win = 0;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                if (v[i].w < v[j].w && v[i].h < v[j].h) win++;
            }
        }
        v[i].rank = win + 1;
    }

    for (int i = 0; i < n; i++) {
        cout << v[i].rank << "\n";
    }

    return 0;
}