#include<iostream>
#include<string.h>
#include<queue>
#include<string>
using namespace std;

struct Node {
    string num_str;
    int num;
};

struct cmp {
    bool operator()(Node right, Node left) {
        return left.num_str < right.num_str;
    }
};

int M, N;
priority_queue<Node, vector<Node>, cmp> pq;
string eng[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

void input() {
    for (int i = M; i <= N; i++) {
        if (i < 10) {
            pq.push({eng[i], i});
        }
        else {
            string str = eng[i / 10];
            str += eng[i % 10];
            pq.push({str,i});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

    input();
    
    int cnt = 1;
    while (!pq.empty()) {
        Node now = pq.top();
        pq.pop();
        
        if (cnt > 10) {
            cout << "\n";
            cout << now.num << " ";
            cnt = 1;
            cnt++;
        }
        else
        {
            cout << now.num << " ";
            cnt++;
        }
    }

    return 0;
}
