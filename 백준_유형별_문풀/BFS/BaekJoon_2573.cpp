#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;

struct Node {
    int r;
    int c;
};

int pola[300][300];
int temp[300][300];
int N, M;
int visited[300][300] = { 0 };
int year = 0;
int dr[] = { -1, 0, 0 ,1 };
int dc[] = { 0, -1, 1, 0 };
vector<Node> v;

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = 0;
        }
    }
}

void melt() {
    for (int z = 0; z < v.size(); z++) {
        int cnt = 0;
        int r = v[z].r;
        int c = v[z].c;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if (pola[nr][nc] == 0) cnt++;
        }
        if ((pola[r][c] - cnt) <= 0) {
            temp[r][c] = 0;
        }
        else {
            temp[r][c] -= cnt;
        }
    }

}

bool upto_twoPiece(int r, int c) {
    queue<Node> q;
    int count = 1;
    q.push({ r,c });
    visited[r][c] = 1;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];
            if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
            if (visited[nr][nc] != 0) continue;
            if (pola[nr][nc] == 0) continue;
            q.push({ nr,nc });
            visited[nr][nc] = 1;
            count++;
        }
    }
    if (count == v.size()) return false;
    else return true;
}

void chk_nz() {
    v.clear();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (pola[i][j] != 0) v.push_back({ i,j });
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> pola[i][j];
        }
    }
    int flag = 0;
    while (1) {
        chk_nz();
        if (v.empty()) {
            break;
        }
        memcpy(temp, pola, sizeof(pola));
        melt();
        memcpy(pola, temp, sizeof(temp));
        chk_nz();
        if (v.empty()) {
            break;
        }
        year++;
        int cnt = 0;
        if (upto_twoPiece(v[0].r, v[0].c)) {
            flag = 1;
            break;
        }
        init();
    }

    if (flag) cout << year;
    else cout << 0;

    return 0;
}
