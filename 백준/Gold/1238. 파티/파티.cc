#include <iostream>
#include <vector>
#include <queue>
#define INF 10000000
using namespace std;

int N, M, X, sum[1001]{ 0, };
vector<vector<int>> node;

vector<int> Dijkstra(int str) {
	vector<int> dis(node.size(), INF);
	dis[str] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push(make_pair(dis[str], str));

	while (!pq.empty()) {
		int n = pq.top().second;
		pq.pop();

		for (int i = 0; i < N + 1; i++) {
			if (node[n][i] > 0) {
				int k = dis[n] + node[n][i];
				if (k < dis[i]) {
					dis[i] = k;
					pq.push(make_pair(dis[i], i));
				}
			}
		}
	}

	return dis;
}

int main() {
	cin >> N >> M >> X;
	node.resize(N + 1);
	for (int i = 0; i <= N; i++) {
		node[i].resize(N + 1);
		for (int j = 0; j <= N; j++) {
			node[i][j] = -1;
		}
		node[i][i] = 0;
	}
	int a, b, c;
	while (M--) {
		cin >> a >> b >> c;
		node[a][b] = c;
	}

	for (int i = 1; i <= N; i++) {
		if (i == X) {
			vector<int> v = Dijkstra(i);
			for (int j = 1; j <= N; j++) {
				sum[j] += v[j];
			}
		}
		else {
			sum[i] += Dijkstra(i)[X];
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (sum[i] > ans) ans = sum[i];
	}

	cout << ans;
}