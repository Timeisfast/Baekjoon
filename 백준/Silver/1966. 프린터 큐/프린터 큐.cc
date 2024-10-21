#include <iostream>
using namespace std;

int doc[101];

int main() {
	int T;
	cin >> T;

	while (T--) {
		int imp[10] = { -1, 0, };
		int N, M, k{ 9 }, ans{ 0 };
		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			cin >> doc[i];
			imp[doc[i]]++;
		}

		for (int i = 0;; i++) {
			if (i == N) i = 0;
			while (imp[k] == 0) k--;
			if (k == 0) break;
			if (doc[i] == k) {
				ans++;
				if (i == M) break;
				doc[i] = 0;
				imp[k]--;
			}
		}

		cout << ans << "\n";
	}
}