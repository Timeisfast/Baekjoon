#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, K, ans{ 0 };
	cin >> N >> K;

	int coin[10];
	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		if (K >= coin[i]) {
			ans += K / coin[i];
			K %= coin[i];
		}
	}

	cout << ans;
}