#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int a, b;
bool visited[10000];

void bfs()
{
    queue<pair<int, string>> q;
    q.push(make_pair(a, ""));
    visited[a] = true;

    while (!q.empty())
    {
        int cur_num = q.front().first;
        string cur_op = q.front().second;
        q.pop();

        if (cur_num == b)
        {
            cout << cur_op << '\n';
            return;
        }

        int n = 0;

        n = (cur_num * 2) % 10000;
        if (!visited[n])
        {
            visited[n] = true;
            q.push(make_pair(n, cur_op + "D"));
        }

        n = cur_num - 1 < 0 ? 9999 : cur_num - 1;
        if (!visited[n])
        {
            visited[n] = true;
            q.push(make_pair(n, cur_op + "S"));
        }

        n = (cur_num % 1000) * 10 + (cur_num / 1000);
        if (!visited[n])
        {
            visited[n] = true;
            q.push(make_pair(n, cur_op + "L"));
        }

        n = cur_num / 10 + (cur_num % 10) * 1000;
        if (!visited[n])
        {
            visited[n] = true;
            q.push(make_pair(n, cur_op + "R"));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        cin >> a >> b;
        memset(visited, false, sizeof(visited)); 
        bfs();
    }

    return 0;
}