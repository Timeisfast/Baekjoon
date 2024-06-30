#include <iostream>
using namespace std;

int main() {
	int N, cnt = 0;
	string K;
	cin >> N >> K;
	
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;

		bool flag1 = true;
		for(int j = 0; j < (int)s.size(); j++) {
			bool flag2 = true;
			int tmp = j;
			for(int k = 0; k < (int)K.size(); k++) {
				if(s[tmp] == K[k]) {
					tmp++;
					continue;
				}
				else {
					flag2 = false;
					break;
				}
			}
			if(flag2) {
				flag1 = false;
				break;
			}
		}
		if(flag1) cnt++;
	}
	
	cout << cnt;
	
	return 0;
}