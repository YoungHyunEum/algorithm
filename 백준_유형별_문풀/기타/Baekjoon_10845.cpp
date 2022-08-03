#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n;
queue<int> q;
vector<int> ans;

void qqq() {
    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;
    
        if (cmd == "push") {
            int num;
            cin >> num;
            q.push(num);
        }
        else if (cmd == "pop") {
            if (q.empty()) ans.push_back(-1);
            else {
                int temp = q.front();
                q.pop();
                ans.push_back(temp);
            }
        }
        else if (cmd == "size") {
            ans.push_back(q.size());
        }
        else if (cmd == "empty") {
            if (q.empty()) ans.push_back(1);
            else ans.push_back(0);
        }
        else if (cmd == "front") {
            if (q.empty()) ans.push_back(-1);
            else ans.push_back(q.front());
        }
        else if (cmd == "back") {
            if (q.empty()) ans.push_back(-1);
            else ans.push_back(q.back());
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    
    qqq();

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}
