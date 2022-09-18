#include <iostream>
#include <string>
using namespace std;

int N;
int map[65][65];
string ans;

void Quad_Tree(int sr, int sc, int size, int area) {
    int cnt = 0;
    int s_num = map[sr][sc];
    for (int i = sr; i < sr + size; i++) {
        for (int j = sc; j < sc + size; j++) {
            if (s_num == map[i][j]) cnt++;
        }
    }

    if (cnt == size * size) {
        ans += to_string(s_num);
    }
    else {
        ans += "(";
        Quad_Tree(sr, sc, size / 2, 1);
        Quad_Tree(sr, sc + size / 2, size / 2, 2);
        Quad_Tree(sr + size / 2, sc, size / 2, 3);
        Quad_Tree(sr + size / 2, sc + size / 2, size / 2, 4);
        ans += ")";
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            map[i][j+1] = (char)s[j] - 48;
        }
    }

    Quad_Tree(1, 1, N, 0);

    cout << ans;

    return 0;
}