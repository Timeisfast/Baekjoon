#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int a[200001] = {0};

int main() {
	int N;
	cin >> N;
	for(int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		v.push_back({e, s});
	}
	
	sort(v.begin(), v.end());
	int sum = 1, cur = v[0].first;
	for(int i = 1; i < (int)v.size(); i++) {
		if(v[i].second > cur) {
			sum += 1;
			cur = v[i].first;
		}
	}
	
	cout << sum;
	
	return 0;
}