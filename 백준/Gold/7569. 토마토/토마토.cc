#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int tomato[101][101][101];
queue<vector<int>> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int M, N, H, i, j, k;
	int dx[6] = { 1, 0, 0, -1, 0, 0 };
	int dy[6] = { 0, 1, 0, 0 ,-1, 0 };
	int dz[6] = { 0, 0, 1, 0, 0, -1 };

	cin >> M >> N >> H;
	for (k = 0; k < H; k++) {
		for (j = 0; j < N; j++) {
			for (i = 0; i < M; i++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1)
					q.push({ i, j, k, 1 });
			}
		}
	}

	int x, y, z, day, nx, ny, nz;
	while (!q.empty()) {
		x = q.front()[0];
		y = q.front()[1];
		z = q.front()[2];
		day = ++q.front()[3];
		q.pop();

		for (j = 0; j < 6; j++) {
			nx = x + dx[j];
			ny = y + dy[j];
			nz = z + dz[j];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N || nz < 0 || nz >= H) continue;
			if (tomato[nx][ny][nz] == 0 || tomato[nx][ny][nz] > day) {
				tomato[nx][ny][nz] = day;
				q.push({ nx, ny, nz, day });
			}
		}
	}

	bool flag = false;
	int ans = 1;
	for (k = 0; k < H; k++) {
		for (i = 0; i < M; i++) {
			for (j = 0; j < N; j++) {
				if (tomato[i][j][k] == 0) {
					flag = true;
					break;
				}
				else if (tomato[i][j][k] > ans)
					ans = tomato[i][j][k];
			}
			if (flag) break;
		}
		if (flag) break;
	}

	if (flag) cout << -1;
	else cout << ans - 1;
}