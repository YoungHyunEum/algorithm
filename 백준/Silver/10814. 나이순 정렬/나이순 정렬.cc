#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
    int age;
    string name;
    int idx;
};

bool cmp(Node left, Node right) {
    if (left.age < right.age) return true;
    else if (left.age > right.age) return false;
    else {
        if (left.idx < right.idx) return true;
        else if (left.idx >= right.idx) return false;
    }
}

int n;
vector<Node> v;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        string str;
        cin >> a >> str;

        v.push_back({ a, str, i });
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << v[i].age << " " << v[i].name << "\n";
    }

    return 0;
}