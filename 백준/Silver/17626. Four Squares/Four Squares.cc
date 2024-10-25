#include <iostream>
using namespace std;

int nums[50001] = { 0, };


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;

	nums[1] = 1;
	for (int i = 2; i <= n; i++) {
		int min_num = 5;
		for (int j = 1; j * j <= i; j++) {
			min_num = min(min_num, nums[i - j * j] + 1);
		}
		nums[i] = min_num;
	}

	cout << nums[n];
}