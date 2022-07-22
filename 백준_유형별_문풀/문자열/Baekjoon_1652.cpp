#include <iostream>
using namespace std;

int N;
char room[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> room[i];
	}
	
	int r = 0;
	int c = 0;
	for (int y = 0; y < N; y++) {
		int cnt = 0;
		for (int x = 0; x < N; x++) {
			if (room[y][x] == '.') cnt++;
			else if(room[y][x] == 'X') {
				if (cnt >= 2) r++;
				cnt = 0;
			}
		}
		if (cnt >= 2)r++;
	}

	for (int x = 0; x < N; x++) {
		int cnt = 0;
		for (int y = 0; y < N; y++) {
			if (room[y][x] == '.') cnt++;
			else if (room[y][x] == 'X') {
				if (cnt >= 2) c++;
				cnt = 0;
			}
		}
		if (cnt >= 2) c++;
	}

	cout << r << " " << c;

	return 0;
}
