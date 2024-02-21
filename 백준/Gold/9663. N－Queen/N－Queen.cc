#include <iostream>
#include <vector>
using namespace std;

int N, ans{ 0 };
int b[15] = { 0, };
bool isUsed[15] = { false, };

void f(int a) {
	if (a == N) {
		ans++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (isUsed[i]) continue;
		
		int j;
		b[a] = i;
		for (j = 0; j < a; j++)
			if (a - j == abs(b[a] - b[j])) break;

		if (j >= a || a == 0) {
			isUsed[i] = true;
			f(a + 1);
		}
		isUsed[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	f(0);
	cout << ans;
}