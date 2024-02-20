#include <iostream>
#include <vector>
using namespace std;

int N, M, ans{ 0 }, sum{ 0 };
vector<vector<int>> board;

void tetro1() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M - 3; j++) {
			int tmp = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3];
			if (tmp > ans) ans = tmp;
		}
	}
	for (int i = 0; i < N - 3; i++) {
		for (int j = 0; j < M; j++) {
			int tmp = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 3][j];
			if (tmp > ans) ans = tmp;
		}
	}
}

void tetro2() {
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			int tmp = board[i][j] + board[i + 1][j] + board[i][j + 1] + board[i + 1][j + 1];
			if (tmp > ans) ans = tmp;
		}
	}
}

void tetro3() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M - 2; j++) {
			int a = board[i][j] + board[i][j + 1] + board[i][j + 2];
			int tmp;
			if (i > 0) {
				for (int k = 0; k < 3; k++) {
					tmp = a + board[i - 1][j + k];
					if (tmp > ans) ans = tmp;
				}
				tmp = board[i][j] + board[i][j + 1] + board[i - 1][j + 1] + board[i - 1][j + 2];
				if (tmp > ans) ans = tmp;
			}
			if (i < N - 1) {
				for (int k = 0; k < 3; k++) {
					tmp = a + board[i + 1][j + k];
					if (tmp > ans) ans = tmp;
				}
				tmp = board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 1][j + 2];
				if (tmp > ans) ans = tmp;
			}
		}
	}

	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M; j++) {
			int a = board[i][j] + board[i + 1][j] + board[i + 2][j];
			int tmp;
			if (j > 0) {
				for (int k = 0; k < 3; k++) {
					tmp = a + board[i + k][j - 1];
					if (tmp > ans) ans = tmp;
				}
				tmp = board[i][j] + board[i + 1][j] + board[i + 1][j - 1] + board[i + 2][j - 1];
				if (tmp > ans) ans = tmp;
			}
			if (j < M - 1) {
				for (int k = 0; k < 3; k++) {
					tmp = a + board[i + k][j + 1];
					if (tmp > ans) ans = tmp;
				}
				tmp = board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j + 1];
				if (tmp > ans) ans = tmp;
			}
		}
	}
}

void tetro4() {

}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	board.resize(N);
	for (int i = 0; i < N; i++) {
		board[i].resize(M);
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	tetro1();
	tetro2();
	tetro3();
	cout << ans;
}