#include <iostream>
#include <algorithm>
using namespace std;

int N;
int fruit[200000];
int mp[10] = { 0, };
int mm = 0;

bool check() {
    int cnt = 0;
    for (int i = 1; i < 10; i++) {
        if (mp[i] > 0) { cnt++; }
    }
    if (cnt > 2) {
        return true;
    }
    return false;
}

int solve() {
    int l = 0;
    int r = 0;
    while (l < N) {
        while (r < N) {
            mp[fruit[r++]]++;
            if (check()) {
                r--;
                mp[fruit[r]]--;
                break;
            }
        }
        mm = max(mm, r - l);
        mp[fruit[l++]]--;
    }
    return mm;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> fruit[i];
    }
    cout << solve() << '\n';
}