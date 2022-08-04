#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

struct Node {
    int plus;
    int minus;
};

int N;
vector<int> v;
Node arr[4001] = {0};
int sum = 0;
int max_num = -4001;
int min_num = 4001;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        max_num = max(max_num, num);
        min_num = min(min_num, num);
        sum += num;
        if (num < 0) arr[abs(num)].minus++;
        else arr[num].plus++;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    float avg = (float)sum / (float)N;
    avg = floor(avg + 0.5);
    cout << (int)avg << "\n";
    cout << v[N / 2] << "\n";
    int max_cnt = -1;
    vector<int> ans;

    int max_idx = max(abs(max_num), abs(min_num));
    for (int i = 0; i <= max_idx; i++) {
        if (arr[i].plus > max_cnt) {
            ans.clear();
            ans.push_back(i);
            max_cnt = arr[i].plus;
        }
        else if (arr[i].plus == max_cnt) {
            ans.push_back(i);
        }
        if (arr[i].minus > max_cnt) {
            ans.clear();
            ans.push_back(-i);
            max_cnt = arr[i].minus;
        }
        else if (arr[i].minus == max_cnt) {
            ans.push_back(-i);
        }
    }

    sort(ans.begin(), ans.end());

    if (ans.size() >= 2) cout << ans[1] << "\n";
    else cout << ans[0] << "\n";
    cout << abs(max_num - min_num);


    return 0;
}