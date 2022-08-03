#include <iostream>
using namespace std;

int a, b, v;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> v;

    int day = (v - a) / (a - b) + 1;

    if ((v - a) % (a - b) != 0) day++;
    cout << day;

    return 0;
}