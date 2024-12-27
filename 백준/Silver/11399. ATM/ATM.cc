#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> P(N, 0);
	for (int i = 0; i < N; i++)
		cin >> P[i];

	sort(P.begin(), P.end());
	
	int ans = 0;
	for (int i = 0; i < N; i++)
		ans += P[i] * (N - i);

	cout << ans;
}