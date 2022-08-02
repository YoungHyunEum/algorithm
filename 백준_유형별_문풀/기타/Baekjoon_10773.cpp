#include <iostream>
#include <stack>
using namespace std;

int k;
stack<int> s;
int sum = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;

	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;

		if (num == 0) {
			if (!s.empty()) s.pop();
		}
		else s.push(num);
	}

	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}

	cout << sum;

	return 0;
}
