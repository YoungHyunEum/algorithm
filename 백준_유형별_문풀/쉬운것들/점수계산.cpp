#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int idx;
	int score;
};

bool cmp1(Node left, Node right) {
	return left.score > right.score;
}

bool cmp2(Node left, Node right) {
	return left.idx < right.idx;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<Node> v;
	vector<Node> v2;
	int ans = 0;

	for (int i = 1; i <= 8; i++) {
		int sc;
		cin >> sc;

		v.push_back({ i, sc });
	}

	sort(v.begin(), v.end(), cmp1);

	for (int i = 0; i < 5; i++) {
		ans += v[i].score;
		v2.push_back({ v[i].idx, v[i].score });
	}

	sort(v2.begin(), v2.end(), cmp2);

	cout << ans << "\n";
	for (int i = 0; i < 5; i++) {
		cout << v2[i].idx << " ";
	}

	return 0;
}
