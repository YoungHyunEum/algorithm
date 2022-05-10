#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node {
    int y, x;
};
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
int arr[50][50];
bool check[50][50];
int num, m, d, s;
vector<Node> cloud;

void moveCloud() {
    for (int i = 0; i < cloud.size(); i++) {
        int cx = cloud[i].x;
        int cy = cloud[i].y;
        int nx = cx + dx[d] * s;
        int ny = cy + dy[d] * s;
        while (nx < 0) {
            nx += num;
        }
        while (nx >= num) {
            nx -= num;
        }
        while (ny < 0) {
            ny += num;
        }
        while (ny >= num) {
            ny -= num;
        }
        cloud[i].x = nx;
        cloud[i].y = ny;
    }
}

void rain() {
    for (int i = 0; i < cloud.size(); i++) {
        int cx = cloud[i].x;
        int cy = cloud[i].y;
        arr[cy][cx]++;
        check[cy][cx] = true;
    }
}

void addRain() {
    for (int i = 0; i < cloud.size(); i++) {
        int cx = cloud[i].x;
        int cy = cloud[i].y;
        int cnt = 0;
        for (int k = 1; k < 8; k += 2) {
            int nx = cx + dx[k];
            int ny = cy + dy[k];
            if (nx >= 0 && ny >= 0 && nx < num && ny < num && arr[ny][nx]>0)
                cnt++;
        }
        arr[cy][cx] += cnt;
    }
}

void init() {
    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++)
            check[i][j] = false;
}

void makeCloud() {
    cloud.clear();
    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++) {
            if (arr[i][j] > 1 && !check[i][j]) {
                cloud.push_back({ i,j });
                arr[i][j] -= 2;
            }
        }
}

int addTotRain() {
    int result = 0;
    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++)
            result += arr[i][j];
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> num >> m;
    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++)
            cin >> arr[i][j];

    cloud.push_back({ num - 1,0 });
    cloud.push_back({ num - 1,1 });
    cloud.push_back({ num - 2,0 });
    cloud.push_back({ num - 2,1 });

    for (int i = 0; i < m; i++) {
        cin >> d >> s;
        d -= 1;
        init();
        moveCloud();
        rain();
        addRain();
        makeCloud();
    }
    cout << addTotRain();
    return 0;
}
