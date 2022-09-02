#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int N;
int map[2200][2200];
int ans[3];

void check_paper(int sr, int sc, int size) {
    int temp = map[sr][sc];
    int flag = 0;

    for (int i = sr; i < sr + size; i++) {
        for (int j = sc; j < sc + size; j++) {
            if (temp != map[i][j]) {
                flag = 1;
                break;
            }
        }
    }

    if (!flag) {
        if (temp == -1) ans[0]++;
        else if (temp == 0) ans[1]++;
        else if (temp == 1) ans[2]++;
    }
    else {
        check_paper(sr, sc, size / 3);
        check_paper(sr, sc + size / 3, size / 3);
        check_paper(sr, sc + size / 3 + size / 3, size / 3);
        check_paper(sr + size / 3, sc, size / 3);
        check_paper(sr + size / 3, sc + size / 3, size / 3);
        check_paper(sr + size / 3, sc + size / 3 + size / 3, size / 3);
        check_paper(sr + size / 3 + size / 3, sc, size / 3);
        check_paper(sr + size / 3 + size / 3, sc + size / 3, size / 3);
        check_paper(sr + size / 3 + size / 3, sc + size / 3 + size / 3, size / 3);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }

    check_paper(1, 1, N);

    for (int i = 0; i < 3; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}
