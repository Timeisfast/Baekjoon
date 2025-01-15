#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string exp;
	cin >> exp;

	string tmp;
    vector<int> num;
    vector<char> op;
	for (int i = 0; i < exp.size(); i++) {
		if (exp[i] < '0' || exp[i] > '9') {
			op.push_back(exp[i]);
			num.push_back(stoi(tmp));
			tmp = "";
		}
		else
			tmp += exp[i];
	}
	num.push_back(stoi(tmp));

	vector<int> num2;
	int sum = 0;
	for (int i = 0; i < op.size(); i++) {
		sum += num[i];
		if (op[i] == '-') {
			num2.push_back(sum);
			sum = 0;
		}
	}
	sum += num[op.size()];
	num2.push_back(sum);

	sum = num2[0];
	for (int i = 1; i < num2.size(); i++) {
		sum -= num2[i];
	}

	cout << sum;
}