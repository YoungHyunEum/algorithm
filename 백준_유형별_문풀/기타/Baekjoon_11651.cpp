#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int x;
	int y;
};

bool cmp(Node left, Node right) {
	if (left.y < right.y) return true;
	else if (left.y > right.y) return false;
	else return left.x <= right.x;
}

int n;
vector<Node> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int xx, yy;
		cin >> xx >> yy;
		v.push_back({ xx, yy });
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << v[i].x << " " << v[i].y << "\n";
	}

	return 0;
}
