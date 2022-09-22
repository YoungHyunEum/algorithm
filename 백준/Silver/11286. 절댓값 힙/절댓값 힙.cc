#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp {
    bool operator()(int right, int left) {
        if (abs(left) > abs(right)) return false;
        else if (abs(left) < abs(right)) return true;
        else {
            return left < right;
        }
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    priority_queue<int, vector<int>, cmp> pq;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if (num != 0) {
            pq.push(num);
        }
        else {
            if (pq.empty()) cout << "0" << "\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }

    return 0;
}