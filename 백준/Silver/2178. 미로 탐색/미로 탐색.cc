#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M, ans;
    cin >> N >> M;
    
    vector<vector<bool>> laby(N, vector<bool>(M, false));
    vector<vector<bool>> check(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < M; j++)
            laby[i][j] = (tmp[j] == '1') ? true : false;
    }

    queue<vector<int>> q;
    q.push({0, 0, 1});
    while (!q.empty()) {
        vector<int> tmp = q.front();
        q.pop();

        int x{ tmp[0] }, y{ tmp[1] };
        if (!laby[x][y]) continue;
        if (x == N - 1 && y == M - 1) {
            ans = tmp[2];
            cout << ans;
            break;
        }

        if (x > 0 && !check[x - 1][y]) {
            q.push({ x - 1, y, tmp[2] + 1 });
            check[x - 1][y] = true;
        }
        if (y > 0 && !check[x][y - 1]) {
            q.push({ x, y - 1, tmp[2] + 1 });
            check[x][y - 1] = true;
        }
        if (x < N - 1 && !check[x + 1][y]) {
            q.push({ x + 1, y, tmp[2] + 1 });
            check[x + 1][y] = true;
        }
        if (y < M - 1 && !check[x][y + 1]) {
            q.push({ x, y + 1, tmp[2] + 1 });
            check[x][y + 1] = true;
        }
    }
}