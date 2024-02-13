#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int L;
	cin >> L;
	long long k = 1;
	long long sum = 0;
	for (int i = 0; i < L; i++) {
		char c;
		cin >> c;
		int a = (int)(c - 'a') + 1;
		sum += (a * k) % 1234567891;
		sum %= 1234567891;
		k = (k * 31) % 1234567891;
	}
	cout << sum;
}