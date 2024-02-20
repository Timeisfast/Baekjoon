#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, ans{ 0 };
vector<vector<int>> board;
vector<pair<int, int>> ice;


bool isConnected() {
	if (ice.empty()) {
		ans = 0;
		return false;
	}
	vector<vector<bool>> isVisited(N, vector<bool>(M, true));
	for (int i = 1; i < ice.size(); i++) {
		isVisited[ice[i].first][ice[i].second] = false;
	}
	queue<pair<int, int>> bfs;
	bfs.push(make_pair(ice[0].first, ice[0].second));
	while (!bfs.empty()) {
		int x{ bfs.front().first }, y{ bfs.front().second };
		bfs.pop();
		if (x > 0)
			if (board[x - 1][y] != 0 && !isVisited[x - 1][y]) {
				bfs.push(make_pair(x - 1, y));
				isVisited[x - 1][y] = true;
			}
		if (x < N - 1)
			if (board[x + 1][y] != 0 && !isVisited[x + 1][y]) {
				bfs.push(make_pair(x + 1, y));
				isVisited[x + 1][y] = true;
			}
		if (y > 0)
			if (board[x][y - 1] != 0 && !isVisited[x][y - 1]) {
				bfs.push(make_pair(x, y - 1));
				isVisited[x][y - 1] = true;
			}
		if (y < M - 1)
			if (board[x][y + 1] != 0 && !isVisited[x][y + 1]) {
				bfs.push(make_pair(x, y + 1));
				isVisited[x][y + 1] = true;
			}
	}
	for (int i = 1; i < ice.size(); i++) {
		if (!isVisited[ice[i].first][ice[i].second]) return false;
	}
	return true;
}

void year() {
	for (int i = 0; i < ice.size(); i++) {
		int x{ ice[i].first }, y{ ice[i].second }, cnt{ 0 };
		if (x > 0)
			if (board[x - 1][y] == 11) cnt++;
		if (x < N - 1)
			if (board[x + 1][y] == 11) cnt++;
		if (y > 0)
			if (board[x][y - 1] == 11) cnt++;
		if (y < M - 1)
			if (board[x][y + 1] == 11) cnt++;
		board[x][y] -= cnt;
	}

	for (int i = 0; i < ice.size(); i++) {
		int x{ ice[i].first }, y{ ice[i].second };
		if (board[x][y] <= 0) {
			board[x][y] = 11;
			ice.erase(ice.begin() + i);
			i--;
		}
	}
}

int main() {
	cin >> N >> M;
	board.resize(N);
	for (int i = 0; i < N; i++) {
		board[i].resize(M);
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] > 0)
				ice.push_back(make_pair(i, j));
			else if (board[i][j] == 0) board[i][j] += 11;
		}
	}

	while (isConnected()) {
		year();
		ans++;
	}

	cout << ans;
}