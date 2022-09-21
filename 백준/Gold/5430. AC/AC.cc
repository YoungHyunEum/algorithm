#include <iostream>
#include <deque>
#include <string>
using namespace std;

int T;
deque<int> dq;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        string cmd;
        int size;
        cin >> cmd;
        cin >> size;

        string v;
        cin >> v;

        string temp = "";
        if (v != "[]") {
            for (int i = 1; i < v.size(); i++) {
                if (v[i] == ',' || v[i] == ']') {
                    int num = stoi(temp);
                    dq.push_back(num);
                    temp = "";
                }
                else {
                    temp += v[i];
                }
            }
        }

        bool fb = true;
        bool error = false;
        for (int i = 0; i < cmd.size(); i++) {
            if (error) break;
            if (cmd[i] == 'R') {
                if (fb) fb = false;
                else fb = true;
            }
            else if (cmd[i] == 'D') {
                if (dq.empty()) {
                    error = true;
                }
                else {
                    if (fb) dq.pop_front();
                    else dq.pop_back();
                }
            }
        }

        if (error) cout << "error" << "\n";
        else {
            cout << "[";
            if (fb) {
                for (int i = 0; i < dq.size(); i++) {
                    if (i == dq.size() - 1) cout << dq[i];
                    else cout << dq[i] << ",";
                }
            }
            else {
                for (int i = dq.size() - 1; i >= 0; i--) {
                    if (i == 0) cout << dq[i];
                    else cout << dq[i] << ",";
                }
            }
            cout << "]" << "\n";
        }

        dq.clear();
    }

    return 0;
}