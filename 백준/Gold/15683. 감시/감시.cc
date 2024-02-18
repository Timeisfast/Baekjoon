#include <iostream>
#include <vector>
using namespace std;

int N, M, ans{ 64 };
vector<vector<int>> v, save[9];
vector<pair<int, int>> cctv;

void check2(int k, int x, int y) {
	if (k % 4 == 0) { //right
		for (int i = y + 1; i < M; i++) {
			if (v[x][i] == 6) break;
			else if (v[x][i] == 0) v[x][i] = 7;
		}
	}
	else if (k % 4 == 1) { // down
		for (int i = x + 1; i < N; i++) {
			if (v[i][y] == 6) break;
			else if (v[i][y] == 0) v[i][y] = 7;
		}
	}
	else if (k % 4 == 2) { // left
		for (int i = y - 1; i >= 0; i--) {
			if (v[x][i] == 6) break;
			else if (v[x][i] == 0) v[x][i] = 7;
		}
	}
	else if (k % 4 == 3) { //up
		for (int i = x - 1; i >= 0; i--) {
			if (v[i][y] == 6) break;
			else if (v[i][y] == 0) v[i][y] = 7;
		}
	}
}

void check(int a) {
	if (a >= cctv.size()) {
		int cnt{ 0 };
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (v[i][j] == 0) cnt++;
			}
		}
		if (cnt < ans) ans = cnt;
		return;
	}

	int n = v[cctv[a].first][cctv[a].second];
	int x{ cctv[a].first }, y{ cctv[a].second };
	if (n == 1) {
		for (int i = 0; i < 4; i++) {
			check2(i, x, y);
			save[a + 1] = v;
			check(a + 1);
			v = save[a];
		}
	}
	else if (n == 2) {
		for (int i = 0; i < 2; i++) {
			check2(i, x, y);
			check2(i + 2, x, y);
			save[a + 1] = v;
			check(a + 1);
			v = save[a];
		}
	}
	else if (n == 3) {
		for (int i = 0; i < 4; i++) {
			check2(i, x, y);
			check2(i + 1, x, y);
			save[a + 1] = v;
			check(a + 1);
			v = save[a];
		}
	}
	else if (n == 4) {
		for (int i = 0; i < 4; i++) {
			check2(i, x, y);
			check2(i + 1, x, y);
			check2(i + 2, x, y);
			save[a + 1] = v;
			check(a + 1);
			v = save[a];
		}
	}
	else if (n == 5) {
		for (int i = 0; i < 4; i++) {
			check2(i,x,y);
		}
		save[a + 1] = v;
		check(a + 1);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		v[i].resize(M);
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
			if (v[i][j] > 0 && v[i][j] < 6) {
				cctv.push_back(make_pair(i, j));
			}
		}
	}
	save[0] = v;
	check(0);
	cout << ans;
}