#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		unordered_map<string, int> m;
		int n;
		cin >> n;

		while (n--) {
			string name, kind;
			cin >> name >> kind;
			m[kind]++;
		}

		int ans = 1;
		for (const auto& x : m) {
			ans *= x.second + 1;
		}
		cout << ans - 1 << "\n";
	}
}