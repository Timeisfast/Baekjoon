#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> vertex[30000];
int dis[30000] = { 0, };

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int v, e;
	cin >> v >> e;

	int st;
	cin >> st;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vertex[a].push_back({ c, b });
	}

	for (int i = 0; i < v + 1; i++) {
		dis[i] = 10000000;
	}

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dis[st] = 0;
	pq.push({ dis[st], st });
	while (!pq.empty()) {
		pair<int, int> k = pq.top();
		pq.pop();

		for (pair<int, int> x : vertex[k.second]) {
			if (dis[x.second] <= dis[k.second] + x.first)
				continue;
			dis[x.second] = dis[k.second] + x.first;
			pq.push({ dis[x.second], x.second });
		}
	}

	for (int i = 1; i < v + 1; i++) {
		if (dis[i] == 10000000) cout << "INF\n";
		else cout << dis[i] << "\n";
	}
}