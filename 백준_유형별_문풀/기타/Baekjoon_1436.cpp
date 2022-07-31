#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int num = 666;
    int i = 1;
    while (1) {
        string str = to_string(num);
        int flag = 0;
        for (int i = 0; i < str.size() - 2; i++) {
            if (str[i] == '6' && str[i + 1] == '6' && str[i + 2] == '6') {
                flag = 1;
            }
        }
        if (flag && i == n) {
            cout << num << "\n";
            break;
        }
        else if (flag) i++;
        num++;
    }

    return 0;
}
