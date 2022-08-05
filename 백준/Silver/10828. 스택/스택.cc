#include <iostream>
#include <stack>
#include <string>
using namespace std;

int N;
stack<int> s;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    for (int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "push") {
            int n;
            cin >> n;
            s.push(n);
        }
        else if (cmd == "pop") {
            if (s.empty()) cout << -1 << "\n";
            else {
                cout << s.top() << "\n";
                s.pop();
            }
        }
        else if (cmd == "size") cout << s.size() << "\n";
        else if (cmd == "empty") {
            if (s.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if (cmd == "top") {
            if (s.empty()) cout << -1 << "\n";
            else cout << s.top() << "\n";
        }
    }


    return 0;
}