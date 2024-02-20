#include <iostream>
#include <queue>
using namespace std;

string v[10000];

int f(int n, int x) {
	switch (n) {
	case 0:
		return (2 * x) % 10000;
	case 1:
		return --x < 0 ? 9999 : x;
	case 2:
		return (x * 10 + x / 1000) % 10000;
	case 3:
		return (x + (x % 10) * 10000) / 10;
	}
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		bool isVisited[10000] = { false, };
		cin >> a >> b;

		queue<int> q;
		q.push(a);
		v[a] = "";
		isVisited[a] = true;
		while (!isVisited[b]) {
			int k = q.front();
			q.pop();
			for(int i =0;i<4;i++){
			int tmp = f(0, k);
			if (!isVisited[tmp]) {
				isVisited[tmp] = true;
				q.push(tmp);
				v[tmp] = v[k] + 'D';
			}
			tmp = f(1, k);
			if (!isVisited[tmp]) {
				isVisited[tmp] = true;
				q.push(tmp);
				v[tmp] = v[k] + 'S';
			}
			tmp = f(2, k);
			if (!isVisited[tmp]) {
				isVisited[tmp] = true;
				q.push(tmp);
				v[tmp] = v[k] + 'L';
			}
			tmp = f(3, k);
			if (!isVisited[tmp]) {
				isVisited[tmp] = true;
				q.push(tmp);
				v[tmp] = v[k] + 'R';
			}
			}
		}
		cout << v[b] << "\n";
	}
}