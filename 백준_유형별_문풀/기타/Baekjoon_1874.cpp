#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;
stack<int> s;
vector<int> v1;
vector<int> v2;
vector<char> ans;

void sequence() {
    int j = 0;
    for (int i = 1; i <= n; i++) {
        s.push(i);
        ans.push_back('+');
        if (s.top() == v1[j]) {
            while (!s.empty()) {
                if (s.top() != v1[j]) break;
                v2.push_back(s.top());
                ans.push_back('-');
                s.pop();
                j++;
            }
        }
    }

}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        v1.push_back(num);
    }
    
    sequence();

    if (!s.empty()) cout << "NO";
    else {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << "\n";
        }
    }

    return 0;
} 
