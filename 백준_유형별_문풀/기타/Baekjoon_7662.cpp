#include <iostream>
#include <set>
using namespace std;

multiset<int> ms;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int k;
		cin >> k;

		for (int i = 0; i < k; i++) {
			char cmd;
			cin >> cmd;
			if (cmd == 'I') {
				int n;
				cin >> n;
				ms.insert(n);
			}
			else if (cmd == 'D') {
				int n;
				cin >> n;
				if (ms.empty()) continue;
				if (n == -1) {
					ms.erase(ms.begin());
				}
				else if (n == 1) {
					auto iter = ms.end();
					iter--;
					ms.erase(iter);
				}
			}
		}
		
		if (ms.empty()) cout << "EMPTY" << "\n";
		else {
			auto big = ms.end();
			auto small = ms.begin();
			big--;
			cout << *big << " " << *small << "\n";
		}

		ms.clear();
	}


	return 0;
}
