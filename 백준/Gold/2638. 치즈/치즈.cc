#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> board;
vector<vector<bool>> visited;

void hour() {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	board[0][0] = -1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x > 0 && board[x - 1][y] != -1) {
			if (board[x - 1][y] == 0) {
				q.push({ x - 1, y });
				board[x - 1][y] = -1;
			}
			else if (board[x - 1][y] > 0) {
				board[x - 1][y]++;
			}
		}
		if (x < N - 1 && board[x + 1][y] != -1) {
			if (board[x + 1][y] == 0) {
				q.push({ x + 1, y });
				board[x + 1][y] = -1;
			}
			else if (board[x + 1][y] > 0) {
				board[x + 1][y]++;
			}
		}
		if (y > 0 && board[x][y - 1] != -1) {
			if (board[x][y - 1] == 0) {
				q.push({ x, y - 1 });
				board[x][y - 1] = -1;
			}
			else if (board[x][y - 1] > 0) {
				board[x][y - 1]++;
			}
		}
		if (y < M - 1 && board[x][y + 1] != -1) {
			if (board[x][y + 1] == 0) {
				q.push({ x, y + 1 });
				board[x][y + 1] = -1;
			}
			else if (board[x][y + 1] > 0) {
				board[x][y + 1]++;
			}
		}
	}
}

bool check() {
	bool flag = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == -1)
				board[i][j] = 0;
			else if (board[i][j] == 2) {
				board[i][j] = 1;
				flag = true;
			}
			else if (board[i][j] == 1)
				flag = true;
			else if (board[i][j] > 2)
				board[i][j] = 0;
		}
	}
	return flag;
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

	int ans = 0;
	while (check()) {
		hour();
		ans++;
	}
	cout << ans;
}