#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int s, e;
	cin >> s >> e;

	int cnt = 0;
	int ans = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= i; j++) {
			cnt++;
			if (cnt >= s && cnt <= e) ans += i;
		}
	}

	cout << ans;

	return 0;
}
