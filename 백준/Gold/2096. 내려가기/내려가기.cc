#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, max_num, min_num;
	cin >> N;

	vector<int> max_cur(3, 0);
	vector<int> min_cur(3, 0);
	vector<int> max_prev(3, 0);
	vector<int> min_prev(3, 0);
	
	cin >> max_prev[0] >> max_prev[1] >> max_prev[2];
	min_prev = max_prev;

	min_cur = min_prev;
	max_cur = max_prev;

	for (int i = 1; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		max_cur[0] = max(max_prev[0], max_prev[1]) + a;
		max_cur[1] = max(max(max_prev[0], max_prev[1]), max_prev[2]) + b;
		max_cur[2] = max(max_prev[1], max_prev[2]) + c;

		min_cur[0] = min(min_prev[0], min_prev[1]) + a;
		min_cur[1] = min(min(min_prev[0], min_prev[1]), min_prev[2]) + b;
		min_cur[2] = min(min_prev[1], min_prev[2]) + c;

		for (int j = 0; j < 3; j++) {
			max_prev[j] = max_cur[j];
			min_prev[j] = min_cur[j];
		}
	}

	max_num = max(max(max_cur[0], max_cur[1]), max_cur[2]);
	min_num = min(min(min_cur[0], min_cur[1]), min_cur[2]);

	cout << max_num << " " << min_num;
}