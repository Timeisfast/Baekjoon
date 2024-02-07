#include <iostream>
using namespace std;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int a, b;
	cin >> a >> b;
	bool *num;
	num = new bool[b + 1];
	num[1] = true;
	
	for(int i = 2; i * i <= b; i++)
	{
		if(num[i])
			continue;
		for(int j = i * 2; j <= b; j += i)
		{
			num[j] = true;
		}
	}
	
	for(int i = a; i <= b; i++)
	{
		if(!num[i])
			cout << i << "\n";
	}
}