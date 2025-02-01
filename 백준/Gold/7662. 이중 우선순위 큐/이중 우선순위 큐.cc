#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T, k, n;
	char c;
	cin >> T;

	while (T--) {
		cin >> k;

		unordered_map<int, int> m;
		priority_queue<int> qmax;
		priority_queue<int, vector<int>, greater<int>> qmin;
		while (k--) {
			cin >> c >> n;
			if (c == 'I') {
				qmin.push(n);
				qmax.push(n);
				m[n]++;
			}
			else {
				if (n == 1) {
					while (!qmax.empty() && m[qmax.top()] == 0) qmax.pop();
					if (!qmax.empty()) {
						m[qmax.top()]--;
						qmax.pop();
					}
				}
				else {
					while (!qmin.empty() && m[qmin.top()] == 0) qmin.pop();
					if (!qmin.empty()) {
						m[qmin.top()]--;
						qmin.pop();
					}
				}
			}
		}

		while (!qmin.empty() && m[qmin.top()] == 0) qmin.pop();
		while (!qmax.empty() && m[qmax.top()] == 0) qmax.pop();

		if (qmin.empty()) cout << "EMPTY\n";
		else cout << qmax.top() << " " << qmin.top() << "\n";
	}
}