#include <iostream>
#include <cmath>
using namespace std;

int section(int k, int r, int c) {
	if (r < k && c < k) return 0;
	else if (r < k && c >= k) return 1;
	else if (r >= k && c < k) return 2;
	else return 3;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, r, c, ans{ 0 };
	cin >> N >> r >> c;

	for (int i = pow(2, N - 1); i > 0; i /= 2) {
		int sec = section(i, r, c);
		
		if (sec == 1) c -= i;
		else if (sec == 2) r -= i;
		else if (sec == 3) {
			r -= i;
			c -= i;
		}

		ans += i * i * sec;
	}

	cout << ans;
}