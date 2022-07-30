#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y, w, h;
    int ans = 999;
    
    cin >> x >> y >> w >> h;
    
    ans = min(ans, abs(x - 0));
    ans = min(ans, abs(x - w));
    ans = min(ans, abs(y - 0));
    ans = min(ans, abs(y - h));

    cout << ans;

    return 0;
}
