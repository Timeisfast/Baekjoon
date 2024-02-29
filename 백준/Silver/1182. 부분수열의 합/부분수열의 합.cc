#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S, ans{ 0 };
vector<int> n;

void f(int k, int sum) {
	if (k == N - 1) return;
	for (int i = k + 1; i < N; i++) {
		int a = sum + n[i];
		if (n[i] > 0 && a > S) break;
		if (a == S) {
			ans++;
		}
		f(i, a);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> S;
	n.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> n[i];
	}

	sort(n.begin(), n.end());
	for (int i = 0; i < N; i++) {
		if (n[i] > 0 && n[i] > S) break;
		if (n[i] == S) {
			ans++;
		}
		f(i, n[i]);
	}

	cout << ans;
}