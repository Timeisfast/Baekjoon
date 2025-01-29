#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
char arr[101][101];
bool check[101][101] = { false, };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int x, int y, char rgb) {
	check[x][y] = true;

	int nx, ny;
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N || check[nx][ny]) continue;
		if (arr[nx][ny] == rgb) {
			dfs(nx, ny, rgb);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!check[i][j]) {
				dfs(i, j, arr[i][j]);
				cnt++;
			}
		}
	}
	cout << cnt << " ";
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			check[i][j] = false;
			if (arr[i][j] == 'R' || arr[i][j] == 'G')
				arr[i][j] = 'A';
		}
	}

	cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!check[i][j]) {
				dfs(i, j, arr[i][j]);
				cnt++;
			}
		}
	}
	cout << cnt;
}