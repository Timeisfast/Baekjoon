#include <iostream>
#include <vector>
#include <queue>
using namespace std;

pair<int, int> visited[100001];

int main() {
	int n, k;
	cin >> n >> k;
	if (n == k) {
		cout << "0\n1";
		return 0;
	}

	for (int i = 0; i <= 100000; i++) {
		visited[i] = { -1, 0 };
	}

	queue<queue<int>> q;
	queue<int> q1;
	q1.push(n);
	q.push(q1);
	bool flag = false;
	visited[n] = { 0, 1 };
	while (!q.empty()) {
		q1 = q.front();
		q.pop();
		queue<int> q2;
		while (!q1.empty()) {
			int a = q1.front();
			if (a < 50001) {
				if (visited[2 * a].first == -1) {
					q2.push(a * 2);
					visited[2 * a].first = visited[a].first + 1;
					visited[2 * a].second = visited[a].second;
				}
				else if(visited[2*a].first == visited[a].first + 1) {
					visited[2 * a].second += visited[a].second;
				}
			}
			if (a < 100000) {
				if (visited[a + 1].first == -1) {
					q2.push(a + 1);
					visited[a + 1].first = visited[a].first + 1;
					visited[a + 1].second = visited[a].second;
				}
				else if (visited[a + 1].first == visited[a].first + 1) {
					visited[a + 1].second += visited[a].second;
				}
			}
			if (a > 0) {
				if (visited[a - 1].first == -1) {
					q2.push(a - 1);
					visited[a - 1].first = visited[a].first + 1;
					visited[a - 1].second = visited[a].second;
				}
				else if (visited[a - 1].first == visited[a].first + 1) {
					visited[a - 1].second += visited[a].second;
				}
			}
			if (a == k) flag = true;
			q1.pop();
		}
		if (flag) break;
		q.push(q2);
	}
	cout << visited[k].first << "\n" << visited[k].second;
}