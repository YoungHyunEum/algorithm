#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool is_VPS(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (st.empty() && s[i] == ')') return false;
        else if (st.empty()) st.push(s[i]);
        else if (st.top() == '(' && s[i] == ')') st.pop();
        else if (s[i] == '(') st.push(s[i]);
    }

    if (st.empty()) return true;
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    for (int tc = 0; tc < n; tc++) {
        string s;
        cin >> s;

        if (is_VPS(s)) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }

    return 0;
}