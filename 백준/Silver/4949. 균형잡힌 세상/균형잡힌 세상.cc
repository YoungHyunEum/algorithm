#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        string str;
        stack<char> s;
        getline(cin, str);
        if (str[0] == '.' && str.size() == 1) break;

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(' || str[i] == '[') s.push(str[i]);
            else if (str[i] == ')') {
                if (s.empty()) s.push(str[i]);
                else if (s.top() == '(') s.pop();
                else s.push(str[i]);
            }
            else if (str[i] == ']') {
                if (s.empty()) s.push(str[i]);
                else if (s.top() == '[') s.pop();
                else s.push(str[i]);
            }
            else continue;
        }

        if (s.empty()) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }

    return 0;
}