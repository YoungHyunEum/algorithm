#include <iostream>
#include <queue>
using namespace std;

int n;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (q.size() > 1) {
		q.pop();
		int temp = q.front();
		q.pop();
		q.push(temp);
	}

	cout << q.front();

	return 0;
}
