#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	getline(cin, s, '.');
	while (s != "" && s != "\n") {
		vector<bool> v;
		bool ans = true;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				v.push_back(false);
			}
			else if (s[i] == '[') {
				v.push_back(true);
			}
			else if (s[i] == ')') {
				if (!v.empty() && !v.back()) v.erase(v.end() - 1);
				else {
					ans = false;
					break;
				}
			}
			else if (s[i] == ']') {
				if (!v.empty() && v.back()) v.erase(v.end() - 1);
				else {
					ans = false;
					break;
				}
			}
		}
		if (!v.empty()) ans = false;
		cout << (ans ? "yes" : "no") << "\n";
		getline(cin, s, '.');
	}
}