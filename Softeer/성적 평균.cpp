#include <iostream>
#include <vector>   
using namespace std;

int N, K;
vector<int> score;
vector<float> answer;

void solve(int a, int b) {
    float cnt = 0;
    float sum = 0;
    for (int i = a - 1; i <= b - 1; i++) {
        sum += score[i];
        cnt++;
    }
    float avg = (sum / cnt);
    answer.push_back(avg);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int s; 
        cin >> s;
        score.push_back(s);
    }

    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        solve(a, b);
    }

    cout << fixed;
    cout.precision(2);

    for (int i = 0; i < K; i++) {
        cout << answer[i] << "\n";
    }

    return 0;
}
