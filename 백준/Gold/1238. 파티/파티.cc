#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> vertex[10000];
vector<pair<int, int>> rvertex[10000];
int dis_in[20000] = { 0, };
int dis_out[20000] = { 0, };

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;

	int x;
	cin >> x;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vertex[a].push_back({ c, b });
		rvertex[b].push_back({ c, a });
	}

	for (int i = 0; i < n + 1; i++) {
		dis_in[i] = dis_out[i] = 10000000;
	}

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dis_in[x] = dis_out[x] = 0;
	pq.push({ dis_in[x], x });
	while (!pq.empty()) {
		pair<int, int> k = pq.top();
		pq.pop();

		for (pair<int, int> x : vertex[k.second]) {
			if (dis_in[x.second] <= dis_in[k.second] + x.first)
				continue;
			dis_in[x.second] = dis_in[k.second] + x.first;
			pq.push({ dis_in[x.second], x.second });
		}
	}

	pq.push({ dis_out[x], x });
	while (!pq.empty()) {
		pair<int, int> k = pq.top();
		pq.pop();

		for (pair<int, int> x : rvertex[k.second]) {
			if (dis_out[x.second] <= dis_out[k.second] + x.first)
				continue;
			dis_out[x.second] = dis_out[k.second] + x.first;
			pq.push({ dis_out[x.second], x.second });
		}
	}

	int ans = 0;
	for (int i = 1; i < n + 1; i++) {
		ans = max(ans, dis_in[i] + dis_out[i]);
	}

	cout << ans;
}