#include <iostream>
#include <list>
#include <string>
using namespace std;

int n;
list<int> li;

void deck() {
	for (int i = 0; i < n; i++) {
		string cmd;
		cin >> cmd;
		if (cmd == "push_front") {
			int num;
			cin >> num;
			li.push_front(num);
		}
		else if (cmd == "push_back") {
			int num;
			cin >> num;
			li.push_back(num);
		}
		else if (cmd == "pop_front") {
			if (li.empty()) cout << -1 << "\n";
			else {
				cout << li.front() << "\n";
				li.pop_front();
			}
		}
		else if (cmd == "pop_back") {
			if (li.empty()) cout << -1 << "\n";
			else {
				cout << li.back() << "\n";
				li.pop_back();
			}
		}
		else if (cmd == "size") {
			cout << li.size() << "\n";
		}
		else if (cmd == "empty") {
			if (li.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (cmd == "front") {
			if (li.empty()) cout << -1 << "\n";
			else cout << li.front() << "\n";
		}
		else if (cmd == "back") {
			if (li.empty()) cout << -1 << "\n";
			else cout << li.back() << "\n";
		}

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	deck();
	
	return 0;
}
