#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int a, b, n, m;
vector<vector<int>> node;
vector<bool> visited;
vector<int> tree;

void dfs(int str) {
	visited[str] = true;
	tree.push_back(str);
	for (int i = 0; i < node[str].size(); i++) {
		if (visited[node[str][i]]) continue;
		dfs(node[str][i]);
	}
}

bool check() {
	int sum = 0;
	for (int i = 0; i < tree.size(); i++)
		sum += node[tree[i]].size();
	if (sum / 2 == tree.size() - 1) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int k = 0;
	cin >> a >> b;
	while (a != 0) {
		k++;
		int ans = 0;
		node.clear();
		node.resize(a + 1);
		visited.resize(a + 1);
		for (int i = 0; i <= a; i++)
			visited[i] = false;
		while(b--) {
			cin >> n >> m;
			node[n].push_back(m);
			node[m].push_back(n);
		}
		for (int i = 1; i <= a; i++) {
			if (visited[i]) continue;
			dfs(i);
			if (check()) ans++;
			tree.clear();
		}
		if (ans == 0) cout << "Case " << k << ": No trees.\n";
		else if (ans == 1) cout << "Case " << k << ": There is one tree.\n";
		else cout << "Case " << k << ": A forest of " << ans << " trees.\n";
		cin >> a >> b;
	}
}