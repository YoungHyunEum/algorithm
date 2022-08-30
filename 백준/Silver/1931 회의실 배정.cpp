#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int s;
	int e;
};

bool compare(Node left, Node right) {
	if (left.e < right.e) return true;
	else if (left.e > right.e) return false;
	else return left.s <= right.s;
}

int N;
vector<Node> v;
int ans = 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int s_t, e_t;
		cin >> s_t >> e_t;
		v.push_back({ s_t, e_t });
	}

	sort(v.begin(), v.end(), compare);

	int temp = v[0].e;
	for (int i = 1; i < v.size(); i++) {
		if (v[i].s >= temp) {
			temp = v[i].e;
			ans++;
		}
	}

	cout << ans;

	return 0;
}
