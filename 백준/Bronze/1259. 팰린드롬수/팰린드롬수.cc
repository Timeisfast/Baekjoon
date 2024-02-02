#include <iostream>
using namespace std;

int main() {
	string a;
	cin >> a;
	while (a != "0") {
		bool ans = true;
		for (int i = 0; i < a.size() / 2; i++) {
			if (a[i] != a[a.size() - 1 - i]) ans = false;
		}
		if (ans) cout << "yes\n";
		else cout << "no\n";
		cin >> a;
	}
}