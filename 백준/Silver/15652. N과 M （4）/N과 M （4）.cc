#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v;

void print_vector() {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
}

void fun(int x) {
	if (v.size() == M) {
		print_vector();
		v.pop_back();
		return;
	}

	for (int i = x; i < N + 1; i++) {
		v.push_back(i);
		fun(i);
	}

	if (!v.empty()) {
		v.pop_back();
	}
	return;
}

int main() {
	cin >> N >> M;
	fun(1);
}