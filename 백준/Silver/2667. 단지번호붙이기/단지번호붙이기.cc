#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, x, y, nx, ny, cnt;
    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    cin >> N;

    vector<int> ans;
    vector<vector<bool>> house(N, vector<bool>(N, false));
    vector<vector<bool>> check(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < N; j++)
            house[i][j] = (tmp[j] == '1') ? true : false;
    }

    queue<pair<int, int>> q;
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!house[i][j] || check[i][j]) continue;

            q.push({ i, j });
            check[i][j] = true;
            cnt = 1;
            while (!q.empty()) {
                x = q.front().first;
                y = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    nx = x + dx[k];
                    ny = y + dy[k];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= N || !house[nx][ny] || check[nx][ny])
                        continue;

                    check[nx][ny] = true;
                    q.push({ nx, ny });
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int x : ans) cout << x << "\n";
}