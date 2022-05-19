#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

struct Node {
    int x;
    int y;
};

vector<Node> v;
Node Start;
Node Rock;
int visited[101];

void init() {
    for (int i = 0; i < 101; i++) {
        visited[i] = 0;
    }
    v.clear();
}

bool dist(Node a, Node b) {
    int manhaeton = abs(a.x - b.x) + abs(a.y - b.y);
    if (manhaeton > 1000) return false;
    return true;
}

bool bfs() {
    queue<Node> q;
    q.push({ Start.x, Start.y });

    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        
        if (dist(now, Rock)) {
            return true;
        }
        else {
            for (int i = 0; i < v.size(); i++) {
                if (dist(now, v[i])) {
                    if (visited[i] == 1) continue;
                    q.push({ v[i].x, v[i].y });
                    visited[i] = 1;
                }
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int tc = 0; tc < t; tc++) {
        init();
        int conv;
        cin >> conv;
        cin >> Start.x >> Start.y;
        for (int i = 0; i < conv; i++) {
            int x, y;
            cin >> x >> y;
            v.push_back({ x,y });
        }
        cin >> Rock.x >> Rock.y;


        if (bfs()) cout << "happy" << "\n";
        else cout << "sad" << "\n";
    }

    return 0;
}
