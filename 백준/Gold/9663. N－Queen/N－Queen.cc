#include <iostream>
#include <vector>

using namespace std;

vector<int> board;
bool isused[15] = { 0 };
int ans = 0;
int N;

void BT(int ind)
{
	if (ind >= N)
	{
		ans++;
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (isused[i]) continue;
		else
		{
			int j;
			isused[i] = true;
			board[ind] = i;
			for (j = 0; j < ind; j++)
			{
				if (ind - j == abs(board[ind] - board[j]))
				{
					isused[i] = false;
					break;
				}
			}
			if (j >= ind || ind == 0)
				BT(ind + 1);
			isused[i] = false;
		}
	}
}

int main()
{
	cin >> N;
	vector<int> v;

	for (int i = 0; i < N; i++)
		board.push_back(0);

	BT(0);

	cout << ans;
}