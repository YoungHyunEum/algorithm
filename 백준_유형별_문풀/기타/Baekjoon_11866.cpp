#include <iostream>
#include <vector>
using namespace std;

int n, k;
int arr[1001] = { 0 };
vector<int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		arr[i] = 1;
	}

	int cnt = 0;
	int idx = 1;

	for (int i = 1; i <= n; i++) {
		if (ans.size() == n) break;
		if (arr[i] != 0) cnt++;
		if (cnt == k) {
			cnt = 0;
			arr[i] = 0;
			ans.push_back(i);
		}
		if (i == n) i = 0;
	}

	cout << "<";
	for (int i = 0; i < ans.size(); i++) {
		if (i == ans.size() - 1) cout << ans[i] << ">";
		else cout << ans[i] << ", ";
	}
	
	return 0;
}
