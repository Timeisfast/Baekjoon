#include <iostream>
using namespace std;

long long fun(int A, int B, int C) {
	if (B == 1) return A % C;
	long long tmp = fun(A, B / 2, C);
	if (B % 2) return (tmp * tmp % C) * A % C;
	else return tmp * tmp % C;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int A, B, C;
    cin >> A >> B >> C;

	cout << fun(A, B, C);
}