#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int idx;
    int priority;
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    
    for (int tc = 0; tc < t; tc++) {
        int n, m;
        queue<Node> q;
        priority_queue<int> pq;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            int p;
            cin >> p;
            q.push({ i, p });
            pq.push(p);
        }

        int order = 1;
        while (!pq.empty()) {
            if (pq.top() == q.front().priority && m == q.front().idx) {
                cout << order << "\n";
                break;
            }  
            else if (pq.top() == q.front().priority) {
                pq.pop();
                q.pop();
                order++;
            }
            else {
                Node temp = q.front();
                q.pop();
                q.push(temp);
            }
        }
    }

    return 0;
} 
