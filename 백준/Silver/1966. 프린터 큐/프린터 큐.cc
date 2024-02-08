#include <iostream>
using namespace std;

int doc[101];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T, N, M;
	cin >> T;
	while (T--) {
		int imp[10] = { -1, 0, };
		cin >> N >> M;
		int a{ 9 }, ans{ 0 };
		for (int i = 0; i < N; i++) {
			cin >> doc[i];
			imp[doc[i]]++;
		}
		for (int i = 0;; i++) {
			if (i == N) i = 0;
			while (imp[a] == 0) a--;
			if (a == 0) break;
			if (doc[i] == a) {
				ans++;
				if (i == M) break;
				doc[i] = 0;
				imp[a]--;
			}
		}
		cout << ans << "\n";
	}
}