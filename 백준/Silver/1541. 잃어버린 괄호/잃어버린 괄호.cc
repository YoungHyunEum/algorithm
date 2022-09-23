#include <iostream>
#include <string>
using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    string temp = "";
    int result = 0;

    cin >> str;

    bool minus = false;
    for (auto i = 0; i <= str.size(); i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
            if (minus) {
                result -= stoi(temp);
            }
            else {
                result += stoi(temp);
            }
            temp = "";
            if (str[i] == '-') {
                minus = true;
            }
        }
        else {
            temp += str[i];
        }

    }
    cout << result;

    return 0;
}