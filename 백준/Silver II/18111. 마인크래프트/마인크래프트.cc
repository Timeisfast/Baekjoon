#include <iostream>
#include <vector>
using namespace std;

int h[257] = { 0, };

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M, B, maxh{ 0 }, minh{ 257 }, ans{ 0 };
	cin >> N >> M >> B;
	N *= M;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		h[a]++;
		if (maxh < a) maxh = a;
		if (minh > a) minh = a;
	}

	while (maxh - minh > 0) {
		if (B >= h[minh] && h[minh] <= 2 * h[maxh]) {
			ans += h[minh];
			B -= h[minh];
			h[minh + 1] += h[minh];
			h[minh++] = 0;
		}
		else {
			ans += 2 * h[maxh];
			B += h[maxh];
			h[maxh - 1] += h[maxh];
			h[maxh--] = 0;
		}
	}
	cout << ans << " " << maxh;
}