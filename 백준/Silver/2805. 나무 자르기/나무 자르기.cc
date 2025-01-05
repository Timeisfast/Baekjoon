#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M, maxv, minv{ 0 };
	cin >> N >> M;
	
	vector<int> v(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), greater<int>());
	maxv = v[0];

	while (minv < maxv - 1) {
		int mid = (maxv + minv) / 2;
		long long sum = 0;

		for (int i = 0; i < N && sum < M; i++) {
			if (v[i] <= mid) break;
			sum += v[i] - mid;
		}

		if (sum >= M) minv = mid;
		else maxv = mid;
	}

	cout << minv;
}