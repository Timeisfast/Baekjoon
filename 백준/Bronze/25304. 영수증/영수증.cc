#include <iostream>
using namespace std;

int main() {
    int X, N, ans = 0;
    cin >> X >> N;
    
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        
        ans += a * b;
    }
    
    if(X == ans) cout << "Yes";
    else cout << "No";
}