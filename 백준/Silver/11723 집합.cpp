#include <iostream>
#include <string>
using namespace std;

int M;
int v[21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M;

	for (int i = 0; i < M; i++) {
		string s;
		int n;
		cin >> s;
		if (s == "add") {
			cin >> n;
			v[n] = 1;
		}
		else if (s == "remove") {
			cin >> n;
			v[n] = 0;
		}
		else if (s == "check") {
			cin >> n;
			cout << v[n] << "\n";
		}
		else if (s == "toggle") {
			cin >> n;
			if (v[n] == 1) v[n] = 0;
			else v[n] = 1;
		}
		else if (s == "all") {
			for (int j = 1; j <= 20; j++) {
				v[j] = 1;
			}
		}
		else if (s == "empty") {
			for (int j = 1; j <= 20; j++) {
				v[j] = 0;
			}
		}
	}

	return 0;
}
