#include <iostream>
using namespace std;

int main() {
	string ans;
	bool isAscen = true;
	bool isDescen = true;
	for (int i = 1; i < 9; i++) {
		int a;
		cin >> a;
		if (a != i && isAscen) isAscen = false;
		if (a != 9 - i && isDescen) isDescen = false;
	}
	if (isAscen) cout << "ascending";
	else if (isDescen) cout << "descending";
	else cout << "mixed";
}