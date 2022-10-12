#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

int arr[10];
int num[10];
int check[10];

void dfs(int len) {
    if (len == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (check[i] == 0) {
            arr[len] = num[i];
            check[i] = 1;
            dfs(len + 1);
            check[i] = 0;
        }
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    sort(num, num + n);

    dfs(0);

    return 0;
}