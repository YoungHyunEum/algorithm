#include <string>
#include <vector>
using namespace std;


int solution(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        int a = i;
        while (sum <= n) {
            sum += a;
            a++;
            if (sum == n) ans++;
        }
    }
    return ans;
}
