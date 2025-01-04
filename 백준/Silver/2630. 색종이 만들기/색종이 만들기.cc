#include <iostream>
using namespace std;

int arr[128][128], blue{ 0 }, white{ 0 };

void recursion(int x, int y, int k) {
	int st = arr[x][y];

	for (int i = x; i < x + k; i++) {
		for (int j = y; j < y + k; j++) {
			if (st != arr[i][j]) st = -1;

			if (st == -1) {
				recursion(x, y, k / 2);
				recursion(x, y + k / 2, k / 2);
				recursion(x + k / 2, y, k / 2);
				recursion(x + k / 2, y + k / 2, k / 2);

				return;
			}
		}
	}

	if (st == 1) blue++;
	else white++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	recursion(0, 0, N);

	cout << white << "\n" << blue;
}