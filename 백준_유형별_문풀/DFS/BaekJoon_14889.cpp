#include<iostream> 
#include<vector>
#include<math.h>
using namespace std;

int N;
int adj[20][20];
int visited[20] = {0};
vector<int> path;
int min_differ = 9999;

void dfs(int level, int cur) {
    if (level == N/2) {
        int team1 = 0;
        int team2 = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (visited[i] && visited[j]) {
                    team1 += adj[i][j];
                    team1 += adj[j][i];
                }
                else if (!visited[i] && !visited[j]) {
                    team2 += adj[i][j];
                    team2 += adj[j][i];
                }
            }
        }
        
        if (abs(team1 - team2) < min_differ) min_differ = abs(team1 - team2);
        return;
    }

    for (int i = cur; i < N; i++) {
        if (visited[i] == 1) continue;
        visited[i] = 1;
        dfs(level + 1, i + 1);
        visited[i] = 0;
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
            cin >> adj[i][j];
        }
    }

    dfs(0, 0);

    cout << min_differ;

    return 0;
}
