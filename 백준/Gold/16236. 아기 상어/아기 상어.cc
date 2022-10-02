#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
    int dist;
    int r;
    int c;
};

struct cmp {
    bool operator()(Node right, Node left) {
        if (left.dist < right.dist) return true;
        else if (left.dist > right.dist) return false;
        else {
            if (left.r < right.r) return true;
            else if (left.r > right.r) return false;
            else {
                return left.c < right.c;
            }
        }
    }
};

int N;
int map[20][20];
int dr[] = { 0, -1, 1, 0 };
int dc[] = { 1, 0, 0, -1 };
pair<int, int> shark;
int shark_size = 2;
int eat = 0;
int eating_time = 0;

void bfs() {
    queue<Node> q;
    q.push({ 0, shark.first, shark.second });

    while (1) {
        priority_queue<Node, vector<Node>, cmp> pq;
        vector<vector<bool>> visited(N, vector<bool>(N));

        while (!q.empty())
        {
            Node curr = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nr = curr.r + dr[i];
                int nc = curr.c + dc[i];
                if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
                if (visited[nr][nc] || map[nr][nc] > shark_size) continue;
                visited[nr][nc] = true;
                q.push({ curr.dist + 1, nr, nc });
                if (map[nr][nc] < shark_size && map[nr][nc] != 0)
                    pq.push({ curr.dist + 1, nr, nc});
            }
        }

        if (!pq.empty()) {
            Node move = pq.top();
            map[move.r][move.c] = 0;
            eat++;
            if (eat == shark_size) {
                shark_size++;
                eat = 0;
            }
            eating_time += move.dist;
            q.push({ 0, move.r, move.c });
        }
        else break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                shark = { i, j };
                map[i][j] = 0;
            }
        }
    }

    bfs();

    cout << eating_time;

    return 0;
}