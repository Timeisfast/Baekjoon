#include <iostream>
using namespace std;

long long lan[10001];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	long long k, n, maxl{ 0 };
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> lan[i];
		maxl = maxl < lan[i] ? lan[i] : maxl;
	}
	long long a = 1;
	while (a <= maxl) {
		long long b = (a + maxl) / 2;
		long long sum = 0;

		for (int i = 0; i < k; i++) {
			sum += lan[i] / b;
		}

		if (sum < n) maxl = b - 1;
		else a = b + 1;
	}
	cout << a - 1;
}