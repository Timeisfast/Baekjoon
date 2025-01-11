#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	do {
		cout << "long ";
	} while (N -= 4);
	cout << "int";
}