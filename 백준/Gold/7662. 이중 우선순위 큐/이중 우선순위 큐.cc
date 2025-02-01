#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T, k, n;
	char c;
	cin >> T;

	while (T--) {
		cin >> k;

		multiset<int> ms;
		while (k--) {
			cin >> c >> n;
			if (c == 'I')
				ms.insert(n);
			else {
				if (ms.empty()) continue;
				if (n == 1)
					ms.erase(prev(ms.end()));
				else
					ms.erase(ms.begin());
			}
		}

		if (ms.empty()) cout << "EMPTY\n";
		else cout << *prev(ms.end()) << " " << *ms.begin() << "\n";
	}
}