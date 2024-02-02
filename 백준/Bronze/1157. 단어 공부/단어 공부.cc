#include <iostream>
#include <string>
using namespace std;

int alp[26] = { 0, };

int main() {
	string a;
	cin >> a;
	char ans = 'A';
	int b = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] < 'a') alp[a[i] - 'A']++;
		else alp[a[i] - 'a']++;
	}
	for (int i = 1; i < 26; i++) {
		if (alp[i] > alp[b]) {
			ans = i + 'A';
			b = i;
		}
		else if (alp[i] == alp[b]) ans = '?';
	}

	cout << ans;
}