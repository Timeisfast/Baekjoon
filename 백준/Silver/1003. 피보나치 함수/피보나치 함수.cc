#include <iostream>
#include <vector>

using namespace std;

int main(){
	int T;
	cin >> T;
	
	while(T--)
	{
		int N;
		cin >> N;
		
		vector<int> dp0(N + 1, 0);
		vector<int> dp1(N + 1, 0);
		
		dp0[0] = dp1[1] = 1;
		
		for(int i = 2; i <= N; i++)
		{
			dp0[i] = dp0[i - 2] + dp0[i - 1];
			dp1[i] = dp1[i - 2] + dp1[i - 1];
		}
		
		cout << dp0[N] << " " << dp1[N] << "\n";
	}
}