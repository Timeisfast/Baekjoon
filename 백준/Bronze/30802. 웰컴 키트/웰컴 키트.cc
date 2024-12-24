#include <iostream>
using namespace std;

int main() {
    int N, T, P;
    int shirt[6] = { 0, };
    cin >> N;

    for(int i = 0; i < 6; i++)
        cin >> shirt[i];

    cin >> T >> P;

    int ans = 0;
    for (int i = 0; i < 6; i++)
        ans += (shirt[i] % T == 0) ? (shirt[i] / T) : (shirt[i] / T + 1);
    
    cout << ans << "\n";
    cout << N / P << " " << N % P;
}