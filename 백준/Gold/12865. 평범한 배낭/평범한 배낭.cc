#include <iostream>
#include <queue>
using namespace std;

int a[100001] = { 0, };

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, K, w[100], v[100];
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> w[i] >> v[i];
		queue<int> q;
		for (int j = w[i]; j <= K; j++) {
			q.push(max(a[j], v[i] + a[j - w[i]]));
		}
		for (int j = w[i]; j <= K; j++) {
			a[j] = q.front();
			q.pop();
		}
	}

	cout << a[K];
}