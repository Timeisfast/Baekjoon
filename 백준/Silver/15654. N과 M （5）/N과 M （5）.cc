#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> seq;
vector<bool> check;
vector<int> ans;

void bt(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++)
			cout << ans[i] << " ";
		cout << "\n";
	}
	else {
		for (int i = 0; i < N; i++) {
			if (!check[i]) {
				ans.push_back(seq[i]);
				check[i] = true;
				bt(cnt + 1);
				ans.pop_back();
				check[i] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		seq.push_back(0);
		cin >> seq[i];
		check.push_back(false);
	}

	sort(seq.begin(), seq.end());

	bt(0);
}