#include <iostream>
using namespace std;

int factorial[11];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, K;
	cin >> N >> K;
	if (K == 0) cout << 1;
	else {
		factorial[0] = 1;
		for (int i = 1; i < 11; i++)
			factorial[i] = factorial[i - 1] * i;
		cout << factorial[N] / (factorial[K] * factorial[N - K]);
	}
}