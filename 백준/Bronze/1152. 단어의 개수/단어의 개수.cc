#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	int cnt = 0;
	bool isEmpty = false;
	getline(cin, a);
	if (a == " ") isEmpty = true;
	for (int i = 1; i < a.size() - 1; i++) {
		if (a[i] == ' ') cnt++;
	}
	if (isEmpty) cout << 0;
	else cout << cnt + 1;
}