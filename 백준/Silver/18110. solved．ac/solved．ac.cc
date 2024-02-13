#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int d[300001];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, a, sum{ 0 };
	cin >> n;
	if (n == 0) cout << 0;
	else {
		for (int i = 0; i < n; i++) cin >> d[i];
		sort(d, d + n);
		a = (int)round(n * 0.15);
		for (int i = a; i < n - a; i++) sum += d[i];
		cout << (int)round((double)sum / (n - 2 * a));
	}
}