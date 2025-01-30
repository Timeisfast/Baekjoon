#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int ls[101] = { 0, };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M, i, j, tmp1, tmp2;
	cin >> N >> M;

	for (i = 0; i < N + M; i++) {
		cin >> tmp1 >> tmp2;
		ls[tmp1] = tmp2;
	}

	queue<int> q;
	q.push(1);

	int cnt = 0;
	bool finish = false;
	while (!q.empty()) {
		cnt++;
		int loopsize = q.size();
		for (i = 0; i < loopsize; i++) {
			int cur = q.front();
			if (cur >= 94) {
				finish = true;
				break;
			}
			q.pop();

			bool flag = false;
			for (j = 6; j >= 1; j--) {
				if (ls[cur + j] != 0) q.push(ls[cur + j]);
				else if (!flag) {
					q.push(cur + j);
					flag = true;
				}
			}
		}
		if (finish) break;
	}

	cout << cnt;
}