#include <iostream>
#include <string>
using namespace std;

int H, W, N;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        cin >> H >> W >> N;
        int cnt = 0;
        string room_num;

        for (int x = 1; x <= W; x++) {
            for (int y = 1; y <= H; y++) {
                cnt++;
                if (cnt == N) {
                    if (y < 10) room_num += (char)y + 48;
                    else {
                        room_num += (char)y / 10 + 48;
                        y -= (y / 10) * 10;
                        room_num += (char)y + 48;
                    }
                    room_num += (char)x / 10 + 48;
                    x -= (x / 10) * 10;
                    room_num += (char)x + 48;
                }
            }
        }

        cout << room_num << "\n";
    }

    return 0;
}