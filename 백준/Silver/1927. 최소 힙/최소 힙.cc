#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	priority_queue<int, vector<int>, greater<int>> q;

	int N;
	cin >> N;

	while (N--) {
		int x;
		cin >> x;
		if (x == 0) {
			if (q.empty())
				cout << 0 << "\n";
			else {
				cout << q.top() << "\n";
				q.pop();
			}
		}
		else
			q.push(x);
	}
}