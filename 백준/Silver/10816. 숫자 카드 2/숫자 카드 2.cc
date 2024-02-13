#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M;
	map<int, int> m;
	cin >> N;
	while (N--) {
		int a;
		cin >> a;
		m[a]++;
	}
	cin >> M;
	while (M--) {
		int a;
		cin >> a;
		cout << m[a] << " ";
	}
}