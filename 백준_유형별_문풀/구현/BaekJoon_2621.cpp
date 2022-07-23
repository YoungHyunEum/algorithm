#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

char color[5];
int num[5];
int arr[100] = { 0 };
int max_num = 0;
int min_num = 10;
int check_700[2] = { 0 };
vector<int> check_300;

int get_score() {
    if (arr[66] == 5 || arr[71] == 5 || arr[82] == 5 || arr[89] == 5) {
        int cnt = 0;
        for (int i = 1; i < 10; i++) {
            if (cnt == 5) break;
            if (arr[i] == 0 || arr[i] > 1) cnt = 0;
            else if (arr[i] == 1) cnt++;
        } 
        if (cnt == 5) return 900 + max_num;
    }
    for (int i = 1; i < 10; i++) {
        if (arr[i] == 4) return 800 + i;
        else if (arr[i] == 3) check_700[0] = i;
        else if (arr[i] == 2) check_700[1] = i;
    }
    if (check_700[0] != 0 && check_700[1] != 0) {
        return (check_700[0] * 10) + check_700[1] + 700;
    }
    if (arr[66] == 5 || arr[71] == 5 || arr[82] == 5 || arr[89] == 5) {
        return 600 + max_num;
    }
    int cnt = 0;
    for (int i = 1; i < 10; i++) {
        if (cnt == 5) break;
        if (arr[i] == 0 || arr[i] > 1) cnt = 0;
        else if (arr[i] == 1) cnt++;
        if (arr[i] == 3) return 400 + i;
        if (arr[i] == 2) check_300.push_back(i);
    }
    if (cnt == 5) return 500 + max_num;
    if (check_300.size() == 2) {
        sort(check_300.begin(), check_300.end());
        return (check_300[1] * 10) + check_300[0] + 300;
    }
    else if (check_300.size() == 1) {
        return 200 + check_300[0];
    }
    return 100 + max_num;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 5; i++) {
        cin >> color[i] >> num[i];
        arr[color[i]]++;
        arr[num[i]] ++;
        max_num = max(max_num, num[i]);
        min_num = min(min_num, num[i]);
    }

    int score = get_score();

    cout << score;

    return 0;
}
