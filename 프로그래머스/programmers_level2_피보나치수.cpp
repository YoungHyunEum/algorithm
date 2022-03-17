#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<long long> v;
    v.push_back(0);
    v.push_back(1);
    
    for(int i = 2; i <= n; i++){
        int a = (v[i-1] + v[i-2]) % 1234567;
        v.push_back(a);
    }
    return v[n];
}
