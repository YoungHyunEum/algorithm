#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string left, string right) {
    if (left.size() < right.size()) return true;
    else if (left.size() > right.size()) return false;
    else {
        for (int i = 0; i < left.size(); i++) {
            if (left[i] < right[i]) return true;
            else if (left[i] > right[i]) return false;
        }
        return false;
    }
}

int n;
vector<string> v;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        v.push_back(str);
    }

    sort(v.begin(), v.end(), cmp);

    string temp = v[0];
    cout << v[0] << "\n";
    for (int i = 1; i < n; i++) {
        if (temp == v[i]) continue;
        temp = v[i];
        cout << v[i] << "\n";
    }

    return 0;
}
