#include <iostream>
#include <string>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n, m; string str;
	cin >> n >> m >> str;

	int ans = 0;
	for (int i = 0; i < m; i++) {

		int k = 0; 
		if (str[i] == 'I') {
			while (str[i + 1] == 'O' && str[i + 2] == 'I') {
				k++;

				if (k == n) {
					ans++;
					k--;
				}
				i += 2;
			}
		}
	}

	cout << ans;

    return 0;
}
