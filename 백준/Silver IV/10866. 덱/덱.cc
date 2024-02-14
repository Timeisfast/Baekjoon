#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	vector<int> v;
	int N;
	
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		string a;
		cin >> a;
		
		if(a == "push_front")
		{
			int X;
			cin >> X;
			v.insert(v.begin(), X);
		}
		else if(a == "push_back")
		{
			int X;
			cin >> X;
			v.push_back(X);
		}
		else if(a == "pop_front")
		{
			if(v.empty() == true)
				cout << "-1\n";
			else
			{
				cout << v.front() << "\n";
				v.erase(v.begin());
			}
		}
		else if(a == "pop_back")
		{
			if(v.empty() == true)
				cout << "-1\n";
			else
			{
				cout << v.back() << "\n";
				v.pop_back();
			}
		}
		else if(a == "size")
			cout << v.size() << "\n";
		else if(a == "empty")
			cout << v.empty() << "\n";
		else if(a == "front")
		{
			if(v.empty() == true)
				cout << "-1\n";
			else
				cout << v.front() << "\n";
		}
		else if(a == "back")
		{
			if(v.empty() == true)
				cout << "-1\n";
			else
				cout << v.back() << "\n";
		}
	}
}