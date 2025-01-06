#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[1001];
bool check[1001];

void dfs(int cur) {
	check[cur] = true;

	for (int i = 0; i < graph[cur].size(); i++) {
		if (!check[graph[cur][i]]) dfs(graph[cur][i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M, cnt{ 0 };
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int st, dt;
		cin >> st >> dt;

		graph[st].push_back(dt);
		graph[dt].push_back(st);
	}

	for (int i = 1; i <= N; i++) {
		if (!check[i]) {
			cnt++;
			dfs(i);
		}
	}

	cout << cnt;
}