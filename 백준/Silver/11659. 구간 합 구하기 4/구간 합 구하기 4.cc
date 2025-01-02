#include <iostream>
using namespace std;

int arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;

	arr[0] = 0;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		arr[i] = arr[i - 1] + a;
	}

	while (M--) {
		int i, j;
		cin >> i >> j;
		cout << arr[j] - arr[i - 1] << "\n";
	}
}