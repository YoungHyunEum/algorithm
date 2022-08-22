#include <iostream>
#include <string>
#include <map>
using namespace std;

int N, M;
map<string, string> site_pwd;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s, p;
		cin >> s >> p;
		site_pwd[s] = p;
	}

	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		cout << site_pwd[s] << "\n";
	}

	return 0;
}
