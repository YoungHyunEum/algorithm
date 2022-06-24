#include <string>
#include <vector>
#include <bitset>
using namespace std;

string chg(int x, int n) {
    string str;
    for (int i = n - 1; i >= 0; --i) {
        int result = x >> i & 1;
        str += (int)result + 48;
    }
    return str;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i < n; i++){
        string a1 = chg(arr1[i], n);
        string a2 = chg(arr2[i], n);
        
        string temp;
        for(int j = 0; j < n; j++){
            if(a1[j] == '1' || a2[j] == '1') temp += '#';
            else temp += ' ';
        }
        answer.push_back(temp);
    }
    return answer;
}
