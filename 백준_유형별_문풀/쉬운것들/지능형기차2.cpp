#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int max_people = 0;
	int people = 0;

	for (int i = 0; i < 10; i++) {
		int in, out;
		cin >> out >> in;

		people += in - out;
		max_people = max(people, max_people);
	}

	cout << max_people;

	return 0;
}
