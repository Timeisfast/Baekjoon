#include <iostream>
#include <numeric>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T, M, N, x, y;
	cin >> T;

	while (T--) {
		cin >> M >> N >> x >> y;
		int m = lcm(N, M);
		
		while(x <= m || y <= m) {
            if(x == y) break;
            
            if(x < y) x += M;
            else y += N;
        }
        
        if(x == y) cout << x << "\n";
        else cout << -1 << "\n";
	}
}