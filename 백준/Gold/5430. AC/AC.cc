#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int path[101][101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T, N;
	string command, arr;
	cin >> T;

	while (T--) {
		cin >> command >> N;
		vector<int> v;
		cin >> arr;
		
		int i;
		if (N != 0) {
			int k = 1;
			for (i = 1; i < arr.size(); i++) {
				if (i != k && arr[i] == ',' || arr[i] == ']') {
					string tmp = arr.substr(k, i - k);
					k = i + 1;
					v.push_back(stoi(tmp));
				}
			}
		}

		bool flag = false, flipped = false;
		for (i = 0; i < command.size(); i++) {
			if (command[i] == 'R')
				flipped = !flipped;
			else {
				if (v.empty()) {
					flag = true;
					break;
				}
				else {
					if (flipped) v.pop_back();
					else v.erase(v.begin());
				}
			}
		}

		if (flag) cout << "error\n";
		else if (v.empty()) cout << "[]\n";
		else {
			if (flipped) reverse(v.begin(), v.end());
			cout << "[";
			for (i = 0; i < v.size() - 1; i++)
				cout << v[i] << ",";
			cout << v[v.size() - 1] << "]\n";
		}
	}
}