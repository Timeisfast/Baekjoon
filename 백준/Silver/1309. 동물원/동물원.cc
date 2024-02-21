#include <iostream>
using namespace std;

int a[100001];
int b[100001];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N;
	cin >> N;
	a[1] = 2;
	b[1] = 1;
	for (int i = 2; i <= N; i++) {
		a[i] = (a[i - 1] + 2 * b[i - 1]) % 9901;
		b[i] = (a[i - 1] + b[i - 1]) % 9901;
	}
	cout << (a[N] + b[N]) % 9901;
}