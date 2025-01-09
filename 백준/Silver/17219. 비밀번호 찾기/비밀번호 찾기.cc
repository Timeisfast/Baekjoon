#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;

	unordered_map<string, string> pwd;
	while (N--) {
		string addr, password;
		cin >> addr >> password;
		pwd[addr] = password;
	}

	while (M--) {
		string addr;
		cin >> addr;
		cout << pwd[addr] << "\n";
	}
}