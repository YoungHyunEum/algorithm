#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct medal {
	int num;
	int gold;
	int silver;
	int bronze;
};

bool cmp(medal left, medal right) {
	if (left.gold > right.gold) return true;
	else if (left.gold < right.gold) return false;
	else if (left.gold == right.gold) {
		if (left.silver > right.silver) return true;
		else if (left.silver < right.silver) return false;
		else if (left.silver == right.silver) {
			return left.bronze > right.bronze;
		}
	}
}

int N, K;
vector<medal> country;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int cn, g, s, b;
		cin >> cn >> g >> s >> b;
		country.push_back({ cn, g, s, b });
	}

	sort(country.begin(), country.end(), cmp);

	int rank = 1;
	int count = 1;
	if (country[0].num == K) cout << rank;
	for (int i = 1; i < N; i++) {
		if (country[i].gold == country[i - 1].gold && country[i].silver == country[i - 1].silver && country[i].bronze == country[i - 1].bronze) {
			count++;
		}
		else {
			rank += count;
			count = 1;
		}

		if (country[i].num == K) cout << rank << "\n";
	}

	return 0;
}
