#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node {
    int r;
    int c;
    int empty_cnt;
    int fr_cnt;
};

struct cmp {
    bool operator()(Node right, Node left) {
        if (left.fr_cnt > right.fr_cnt) return true;
        if (left.fr_cnt < right.fr_cnt) return false;
        if (left.fr_cnt == right.fr_cnt) {
            if (left.empty_cnt > right.empty_cnt) return true;
            if (left.empty_cnt < right.empty_cnt) return false;
            if (left.empty_cnt == right.empty_cnt) {
                if (left.r < right.r) return true;
                if (left.r > right.r) return false;
                if (left.r == right.r) return left.c <= right.c;
            }
        }
    }
};

int N;
vector<int> friends[400];
int map[21][21];
int dr[] = { -1, 0, 0, 1 };
int dc[] = { 0, -1, 1, 0 };
int visited[21][21] = { 0 };

void input() {
    cin >> N;
    for (int i = 0; i < N * N; i++) {
        for (int j = 0; j < 5; j++) {
            int a;
            cin >> a;
            friends[i].push_back(a);
        }
    }
}

int chk_emtpy(int r, int c) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 1 || nc < 1 || nr > N || nc > N) continue;
        if (map[nr][nc] == 0) cnt++;
    }
    return cnt;
}

int chk_friends(int r, int c, int idx) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 1 || nc < 1 || nr > N || nc > N) continue;
        for (int j = 1; j < 5; j++) {
            if (friends[idx][j] == map[nr][nc]) cnt++;
        }
    }
    return cnt;
}

void init() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            visited[i][j] = 0;
        }
    }
}

void sit(int idx) {
    priority_queue<Node, vector<Node>, cmp> pq;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (visited[r][c] == 1) continue;
            if (map[r][c] != 0) continue;
            visited[r][c] = 1;
            pq.push({ r,c, chk_emtpy(r,c), chk_friends(r,c,idx) });
        }
    }

    Node first = pq.top();
    map[first.r][first.c] = friends[idx][0];
}

int score() {
    int sc = 0;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            int cnt = 0;
            for (int idx = 0; idx < N * N; idx++) {
                if (map[r][c] == friends[idx][0]) {
                    for (int i = 0; i < 4; i++) {
                        int nr = r + dr[i];
                        int nc = c + dc[i];
                        if (nr < 1 || nc < 1 || nr > N || nc > N) continue;
                        for (int j = 1; j < 5; j++) {
                            if (map[nr][nc] == friends[idx][j]) {
                                cnt++;
                                break;
                            }
                        }
                    }
                    break;
                }
            }
            if (cnt == 1) sc += 1;
            else if (cnt == 2) sc += 10;
            else if (cnt == 3) sc += 100;
            else if (cnt == 4) sc += 1000;
        }
    }
    return sc;
}

int solve() {
    map[2][2] = friends[0][0];
    for (int i = 1; i < N * N; i++) {
        init();
        sit(i);
    }

    int ans = score();
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    input();
    cout << solve();

    return 0;
}
