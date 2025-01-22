#include <iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	string s;
	cin >> s;

	int i{ 0 }, cnt{ 0 }, ans{ 0 };

	while (i < M) {
		if (cnt < N)
		{
			if (s[i] == 'I' && s[i + 1] == 'O') {
				i += 2;
				cnt++;
			}
			else {
				i++;
				cnt = 0;
			}
		}
		if (cnt == N) {
			if (s[i] == 'I') {
				ans++;
				cnt--;
			}
			else {
				cnt = 0;
				i++;
			}
		}
	}
	cout << ans;
}