#include <iostream>
#include <vector>
using namespace std;

bool card[500001];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, k{ 1 }, a{ 1 };
	cin >> N;
	for (int i = 1; i <= N; i++) card[i] = true;
	for (int i = 0; i < N; i++) {
		while (1) {
			if (card[k]) {
				if (--a == 0) break;
			}
			if (++k > N) k = 1;
		}
		card[k] = false;
		a = 2;
	}
	cout << k;
}