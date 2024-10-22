#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int doc[101];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;

	vector<vector<int>> board(n, vector<int>(m, 0));
	pair<int, int> st;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) st = { i, j };
			if (board[i][j] == 1) board[i][j] = -1;
		}
	}

	queue<pair<int, int>> q;

	q.push(st);
	board[st.first][st.second] = 0;
	while (!q.empty()) {
		int x{ q.front().first }, y{ q.front().second };
		q.pop();

		if (x > 0 && board[x - 1][y] == -1) {
			board[x - 1][y] = board[x][y] + 1;
			q.push({ x - 1, y });
		}
		if (y > 0 && board[x][y - 1] == -1) {
			board[x][y - 1] = board[x][y] + 1;
			q.push({ x, y - 1 });
		}
		if (x < n - 1 && board[x + 1][y] == -1) {
			board[x + 1][y] = board[x][y] + 1;
			q.push({ x + 1, y });
		}
		if (y < m - 1 && board[x][y + 1] == -1) {
			board[x][y + 1] = board[x][y] + 1;
			q.push({ x, y + 1 });
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}