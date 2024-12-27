#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	unordered_map<string, int> names;
	string name;
	while (N--) {
		cin >> name;
		names[name]++;
	}

	while (M--) {
		cin >> name;
		names[name]++;
	}

	vector<string> ans;
	for (const pair<string, int>& name : names)
		if (name.second > 1) ans.push_back(name.first);

	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (string name : ans)
		cout << name << "\n";
}