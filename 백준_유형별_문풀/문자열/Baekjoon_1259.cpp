#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    while (1) {
        cin >> str;
        if (str == "0") break;
        int flag = 0;
        for (int i = 0, j = str.size() - 1; i < str.size(), j >= 0; i++, j--) {
            if (str[i] != str[j]) {
                flag = 1;
                break;
            }
        }
        if (flag) cout << "no" << "\n";
        else cout << "yes" << "\n";
    }

    return 0;
}
