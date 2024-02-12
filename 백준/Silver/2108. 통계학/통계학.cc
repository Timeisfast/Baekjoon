#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int N, sum{0};
	vector<int> num;
	int cnt[8001] = {0};
	int max_cnt{0};
	vector<int> max_cntn;
	
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		num.push_back(a);
		cnt[a + 4000]++;
		sum += num[i];
	}
	
	cout << (int)round((double)sum / N) << endl;
	
	sort(num.begin(), num.end());
	
	cout << num[N / 2] << endl;
	
	for(int i = 0; i < 8001; i++)
		max_cnt = max(max_cnt, cnt[i]);
	
	for(int i = 0; i < 8001; i++)
		if(cnt[i] == max_cnt)
			max_cntn.push_back(i);
	
	sort(max_cntn.begin(), max_cntn.end());
	
	if(max_cntn.size() != 1)
		cout << max_cntn[1] - 4000 << endl;
	else
		cout << max_cntn[0] - 4000 << endl;
	
	cout << num[N - 1] - num[0];
}