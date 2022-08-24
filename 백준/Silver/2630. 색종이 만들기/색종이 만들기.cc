#include <iostream>
using namespace std;

int white = 0;
int blue = 0;

int N;
int map[129][129];

void check_paper(int sr, int sc, int size) {
    int color = map[sr][sc];
    int flag = 0;
    for (int i = sr; i < sr + size; i++) {
        for (int j = sc; j < sc + size; j++) {
            if (map[i][j] != color) {
                flag = 1;
            }
        }
    }

    if (flag) {
        check_paper(sr, sc, size / 2);
        check_paper(sr, sc + size / 2, size / 2);
        check_paper(sr + size / 2, sc, size / 2);
        check_paper(sr + size / 2, sc + size / 2, size / 2);
    }
    else if (flag == 0) {
        if (color) blue++;
        else white++;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }
    
    check_paper(1, 1, N);

    cout << white << "\n";
    cout << blue;

    return 0;
}