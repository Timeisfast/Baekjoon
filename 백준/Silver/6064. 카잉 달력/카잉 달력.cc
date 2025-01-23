#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T, M, N, x, y;
	cin >> T;

	while (T--) {
		cin >> M >> N >> x >> y;
		int m = M * N;
		
		vector<int> s1, s2;
		for (int i = 0;; i++) {
			int tmp1 = M * i + x;
			int tmp2 = N * i + y;
			if(tmp1 <= m) s1.push_back(tmp1);
			if(tmp2 <= m) s2.push_back(tmp2);
			if (tmp1 >= m && tmp2 >= m) break;
		}

		vector<int> v;
		set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(v));

		if (v.empty()) cout << -1 << "\n";
		else cout << v[0] << "\n";
	}
}