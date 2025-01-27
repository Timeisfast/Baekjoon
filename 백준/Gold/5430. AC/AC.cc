#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <sstream>
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
		deque<int> v;
		cin >> arr;
		
		arr = arr.substr(1, arr.size() - 2);
		istringstream iss(arr);
		while (getline(iss, arr, ',')) {
			v.push_back(stoi(arr));
		}

		int i;
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
					else v.pop_front();
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