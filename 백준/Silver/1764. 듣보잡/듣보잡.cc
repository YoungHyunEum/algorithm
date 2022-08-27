#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int N, M;
map<string, int> m;
vector<string> ans;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        m[s] = 1;
    }

    for (int i = 0; i < M; i++)
    {
        string s2;
        cin >> s2;
        if (m[s2] == 1) {
            ans.push_back(s2);
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}