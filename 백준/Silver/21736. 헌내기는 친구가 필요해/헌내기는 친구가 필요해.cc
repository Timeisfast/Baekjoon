#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M, ans{ 0 };
	cin >> N >> M;

	vector<vector<char>> campus(N, vector<char>(M, 0));
	pair<int, int> st;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> campus[i][j];
			if (campus[i][j] == 'I') st = { i, j };
		}
	}

	vector<vector<bool>> check(N, vector<bool>(M, false));
	check[st.first][st.second] = true;
	queue<pair<int, int>> q;
	q.push(st);

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (campus[x][y] == 'P') ans++;
		else if (campus[x][y] == 'X') continue;

		if (x > 0 && !check[x - 1][y]) {
			q.push({ x - 1,y });
			check[x - 1][y] = true;
		}
		if (x < N - 1 && !check[x + 1][y]) {
			q.push({ x + 1,y });
			check[x + 1][y] = true;
		}
		if (y > 0 && !check[x][y - 1]) {
			q.push({ x,y - 1 });
			check[x][y - 1] = true;
		}
		if (y < M - 1 && !check[x][y + 1]) {
			q.push({ x,y + 1 });
			check[x][y + 1] = true;
		}
	}

	if (ans) cout << ans;
	else cout << "TT";
}