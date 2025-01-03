#include <iostream>
using namespace std;

int arr[50][50];

void resetArr() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			arr[i][j] = 0;
		}
	}
}

void dfs(int N, int M, int x, int y) {
	arr[x][y] = 2;
	if (x > 0 && arr[x - 1][y] == 1) {
		dfs(N, M, x - 1, y);
	}
	if (y > 0 && arr[x][y - 1] == 1) {
		dfs(N, M, x, y - 1);
	}
	if (x < N - 1 && arr[x + 1][y] == 1) {
		dfs(N, M, x + 1, y);
	}
	if (y < M - 1 && arr[x][y + 1] == 1) {
		dfs(N, M, x, y + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int N, M, K, ans = 0;
		cin >> N >> M >> K;

		while (K--) {
			int x, y;
			cin >> x >> y;
			arr[x][y] = 1;
		}

		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				if (arr[i][j] == 1) {
					dfs(N, M, i, j);
					ans++;
				}
			}
		}

		cout << ans << "\n";
		resetArr();
	}
}