#include <iostream>
#include <queue>
using namespace std;

int visited[100001];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i <= 100000; i++) {
		visited[i] = -1;
	}

	queue<int> q;
	q.push(n);
	visited[n] = 0;
	while (!q.empty()) {
		int a = q.front();
		if (a == k) break;
		q.pop();
		if (a < 50001) {
			if (visited[2 * a] == -1) {
				q.push(a * 2);
				visited[2 * a] = visited[a] + 1;
			}
		}
		if (a < 100000) {
			if (visited[a + 1] == -1) {
				q.push(a + 1);
				visited[a + 1] = visited[a] + 1;
			}
		}
		if (a > 0) {
			if (visited[a - 1] == -1) {
				q.push(a - 1);
				visited[a - 1] = visited[a] + 1;
			}
		}
	}
	cout << visited[k];
}