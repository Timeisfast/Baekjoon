#include <string>
#include <vector>

using namespace std;

long long arr[5001] = { 0, };

long long solution(int n) {
    if(n % 2) return 0;
    arr[0] = 1;
    arr[2] = 3;
    for(int i = 4; i <= n; i += 2) {
        arr[i] = ((4 * arr[i - 2]) % 1000000007) - arr[i - 4];
        if(arr[i] < 0) arr[i] += 1000000007;
    }
    return arr[n];
}