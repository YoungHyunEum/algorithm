#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int arr[10];
bool visited[10];

void dfs(int num, int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = num; i <= n; i++)
    {
        visited[i] = true;
        arr[cnt] = i;
        dfs(i, cnt + 1);
        visited[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    dfs(1, 0);

    return 0;
}