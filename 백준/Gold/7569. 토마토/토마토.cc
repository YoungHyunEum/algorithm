#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;

struct Node {
    int z;
    int y;
    int x;
    int day;
};

struct cmp {
    bool operator()(Node right, Node left) {
        return left.day < right.day;
    }
};

int N, M, H;
int box[100][100][100];
int dz[] = { 0, 0, 0, 0, 1, -1 };
int dy[] = { 1, 0, 0, -1, 0, 0 };
int dx[] = { 0, -1, 1, 0, 0, 0 };
int empty_box = 0;
vector<Node> ripe;
int ans = 0;
bool flag = true;

void bfs() {
    priority_queue<Node, vector<Node>, cmp> pq;
    
    for (int i = 0; i < ripe.size(); i++) {
        pq.push(ripe[i]);
    }

    while (!pq.empty()) {
        Node now = pq.top();
        pq.pop();

        ans = max(ans, now.day);

        for (int i = 0; i < 6; i++) {
            int nz = now.z + dz[i];
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (nz < 0 || ny < 0 || nx < 0 || nz >= H || ny >= N || nx >= M) continue;
            if (box[nz][ny][nx] == 0) {
                pq.push({ nz, ny, nx, now.day + 1 });
                ripe.push_back({ nz, ny, nx, now.day + 1 });
                box[nz][ny][nx] = 1;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> M >> N >> H;

    for (int z = 0; z < H; z++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                cin >> box[z][y][x];
                if (box[z][y][x] == -1) {
                    empty_box++;
                }
                else if (box[z][y][x] == 1) {
                    ripe.push_back({ z, y, x, 0 });
                }
            }
        }
    }
    
    bfs();
    
    if (ripe.size() + empty_box != N * M * H) cout << -1;
    else cout << ans;

    return 0;
}