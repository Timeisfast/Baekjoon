#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 1: 1 ~ 31, 2: 32 ~ 59, 3: 60 ~ 90, 4: 91 ~ 120, 5: 121 ~ 151, 6: 152 ~ 181
// 7: 182 ~ 212, 8: 213 ~ 243, 9: 244 ~ 273, 10: 274 ~ 304, 11: 305 ~ 334, 12: 335 ~ 365

int N, ans{ 2 }, k{ 0 }, l{ 365 };;
bool srtf{ false }, endf{ false }, one{ false };
vector<vector<int>> flower;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (c < 3 || a == 12) continue;
		if (a == c && b == d) continue;

		switch (a) {
		case 1:
		case 2: b = 60; break;
		case 3: b += 59; break;
		case 4: b += 90; break;
		case 5: b += 120; break;
		case 6: b += 151; break;
		case 7: b += 181; break;
		case 8: b += 212; break;
		case 9: b += 243; break;
		case 10: b += 273; break;
		case 11: b += 304; break;
		}

		switch (c) {
		case 3: d += 59; break;
		case 4: d += 90; break;
		case 5: d += 120; break;
		case 6: d += 151; break;
		case 7: d += 181; break;
		case 8: d += 212; break;
		case 9: d += 243; break;
		case 10: d += 273; break;
		case 11: d += 304; break;
		case 12: d = 335; break;
		}

		if (b == 60 && d == 335) {
			one = true;
			continue;
		}
		if (b == 60) {
			if (d > k) k = d;
			srtf = true;
			continue;
		}
		if (d == 335) {
			if (b < l) l = b;
			endf = true;
			continue;
		}
		flower.push_back({ b, d});
	}

	if (one) {
		cout << 1;
		return 0;
	}

	if (!srtf || !endf) {
		cout << 0;
		return 0;
	}

	if (k >= l) {
		cout << 2;
		return 0;
	}

	sort(flower.begin(), flower.end());

	N -= 2;
	int tmp = 0;
	srtf = endf = false;
	do {
		if (tmp == flower.size() - 1) break;
		int a = k;
		for (int i = tmp; i < flower.size(); i++) {
			if (flower[i][0] > k) break;
			srtf = true;
			if (flower[i][1] > a) {
				a = flower[i][1];
				tmp = i;
			}
		}
		k = a;
		ans++;
		if (k >= l) {
			endf = true;
			break;
		}
	} while (srtf && !endf);

	if (!srtf || !endf) {
		cout << 0;
		return 0;
	}

	cout << ans;
}