#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<pair<int, int>> city[10000];
int dist[10000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		city[a].push_back({ c, b });
	}

	memset(dist, 0x7f, sizeof(dist));

	int st, dt;
	cin >> st >> dt;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[st] = 0;
	pq.push({ dist[st], st });
	while (!pq.empty()) {
		pair<int, int> cur = pq.top();
		pq.pop();
		if (dist[cur.second] != cur.first) continue;
		for (pair<int, int> next : city[cur.second]) {
			if (dist[next.second] <= dist[cur.second] + next.first) continue;
			dist[next.second] = dist[cur.second] + next.first;
			pq.push({ dist[next.second], next.second });
		}
	}

	cout << dist[dt];
}