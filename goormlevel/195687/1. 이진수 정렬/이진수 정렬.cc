#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	vector<pair<int, int>> v;
	for(int i = 0; i < N; i++) {
		int k, cnt = 0;
		cin >> k;
		int tmp = k;
		while(tmp != 0) {
			if(tmp % 2) cnt++;
			tmp /= 2;
		}
		v.push_back({cnt, k});
	}
	
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	
	cout << v[K -1].second;
	
	return 0;
}