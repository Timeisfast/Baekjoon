#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[100001];
int parent[100001] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, a, b;
	cin >> N;
	
	for(int i = 1; i < N; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	queue<int> q;
	for (int i = 0; i < graph[1].size(); i++) {
		q.push(graph[1][i]);
		parent[graph[1][i]] = 1;
	}

	while (!q.empty()) {
		int k = q.front();
		q.pop();
		for (int i = 0; i < graph[k].size(); i++) {
			if (!parent[graph[k][i]]) {
				q.push(graph[k][i]);
				parent[graph[k][i]] = k;
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}
}