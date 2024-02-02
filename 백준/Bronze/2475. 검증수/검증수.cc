#include <iostream>
using namespace std;

int main() {
	int a = 0;
	for (int i = 0; i < 5; i++) {
		int tmp;
		cin >> tmp;
		a += tmp * tmp;
	}
	cout << a % 10;
}