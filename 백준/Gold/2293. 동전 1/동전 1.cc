#include <iostream>
using namespace std;

int a[100001] = { 0, };

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		a[k]++;
		for (int j = k + 1; j <= K; j++) {
			a[j] += a[j - k];
		}
	}
	cout << a[K];
}