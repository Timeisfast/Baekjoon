#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, start, end, ans{ 0 };
	cin >> N;

	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		v.push_back({ end, start });
	}
	
	sort(v.begin(), v.end());

	int last = 0;
	for (int i = 0; i < N; i++) {
		if (v[i].second >= last) {
			last = v[i].first;
			ans++;
		}
	}

	cout << ans;
}