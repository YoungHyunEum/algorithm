#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		string str;
		cin >> n >> str;
		
		for (int j = 0; j < str.size(); j++) {
			if (j == n - 1) continue;
			cout << str[j];
		}
		cout << "\n";
	}

	return 0;
}
