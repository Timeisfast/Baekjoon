#include <iostream>
using namespace std;

int n, m, i, j, tmp;
int box[101] = {0, };

void swap(int idx1, int idx2) {
    tmp = box[idx1];
    box[idx1] = box[idx2];
    box[idx2] = tmp;
}

int main() {
    cin >> n >> m;
    for(int c = 1; c <= n; c++)
        box[c] = c;
    for(int a = 0; a < m; a++) {
        cin >> i >> j;
        swap(i, j);
    }
    for(int b = 1; b <= n; b++)
        cout << box[b] << " ";
}