#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int weight;
    int price;
};

struct cmp {
    bool operator()(Node right, Node left) {
        return left.price > right.price;
    }
};

int W, N;
priority_queue<Node, vector<Node>, cmp> pq;

int packing() {
    int max_price = 0;
    while (W > 0) {
        Node now = pq.top();
        pq.pop();

        if (now.weight > W) {
            max_price += now.price * W;
            W = 0;
        }
        else {
            max_price += now.weight * now.price;
            W -= now.weight;
        }
    }
    return max_price;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> W >> N;
    for (int i = 0; i < N; i++) {
        int w, p;
        cin >> w >> p;
        pq.push({ w, p });
    }

    cout << packing();

    return 0;
}
