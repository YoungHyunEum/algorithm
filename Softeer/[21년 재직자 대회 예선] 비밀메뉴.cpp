#include<iostream>
#include<vector>
#include<string>
using namespace std;

int M, N, K;
string pwd;
string btn_input;

void input() {
    cin >> M >> N >> K;
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        pwd += a + 48;
    }
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        btn_input += a + 48;
    }
}

bool isExist() {
    if (btn_input.find(pwd) == -1) return false;
    else return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    if (M > N) cout << "normal";
    else {
        if (!isExist()) cout << "normal";
        else cout << "secret";
    }

    return 0;
}
