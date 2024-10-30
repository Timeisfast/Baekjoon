#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

vector<pair<int, int>> node[1000];
int dist[1000];

void dijkstra(int st) {
	for (int i = 0; i < 1000; i++) {
		dist[i] = INT_MAX;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[st] = 0;
	pq.push({ dist[st], st });
	while (!pq.empty()) {
		pair<int, int> cur = pq.top();
		pq.pop();
		if (dist[cur.second] != cur.first) continue;
		for (pair<int, int> next : node[cur.second]) {
			if (dist[next.second] <= dist[cur.second] + next.first) continue;
			dist[next.second] = dist[cur.second] + next.first;
			pq.push({ dist[next.second], next.second });
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, E;
	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		node[a].push_back({ c, b });
		node[b].push_back({ c, a });
	}

	int mid1, mid2;
	cin >> mid1 >> mid2;

	int ans{ 0 }, path1{ 0 }, path2{ 0 };
	bool valid1{ true }, valid2{ true };

	dijkstra(1);
	if (dist[mid1] == INT_MAX) valid1 = false;
	path1 += dist[mid1];
	if (dist[mid2] == INT_MAX) valid2 = false;
	path2 += dist[mid2];

	dijkstra(mid1);
	if (dist[mid2] == INT_MAX)
		valid1 = valid2 = false;
	path1 += dist[mid2];
	path2 += dist[mid2];

	dijkstra(N);
	if (dist[mid2] == INT_MAX) valid1 = false;
	path1 += dist[mid2];
	if (dist[mid1] == INT_MAX) valid2 = false;
	path2 += dist[mid1];

	if (!valid1 && !valid2)
		ans = -1;
	else if (!valid1)
		ans = path2;
	else if (!valid2)
		ans = path1;
	else
		ans = min(path1, path2);

	cout << ans;
}