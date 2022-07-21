#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int winner, score = 0;

	for (int i = 0; i < 5; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			int a;
			cin >> a;
			sum += a;
		}
		if (score < sum) {
			winner = i + 1;
			score = sum;
		}
	}

	cout << winner << " " << score;

	return 0;
}
