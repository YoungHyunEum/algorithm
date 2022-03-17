#include <iostream>
#include <vector>
#include<string>
using namespace std;

string str, bomb;
vector<char> ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;
	cin >> bomb;

	for (int i = 0; i < str.length(); i++)
	{
		ans.push_back(str[i]);
		if (bomb[bomb.size() - 1] == ans[ans.size()-1]) {
			int cnt = 1;
			for (int j = 1; j < bomb.size(); j++)
			{
				if (bomb[bomb.size() - 1 - j] == ans[ans.size() - 1 - j]) {
					cnt++;
				}
			}
			if (cnt == bomb.size()) {
				for (int j = 0; j < cnt; j++)
				{
					ans.pop_back();
				}
			}
		}
	}

	if (ans.empty()) cout << "FRULA";
	else {
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i];
		}
	}

	return 0;
}
