#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> edge[101];
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    int d[100];
    priority_queue<pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>> pq;
    pair<int, int> ans = { 0, 0x7fffffff };

    for (int i = 1; i <= N; i++) {
        fill(d, d + N + 1, 0x7fffffff);
        d[i] = 0;
        pq.push({ d[i], i });
        while (!pq.empty()) {
            pair<int, int> cur = pq.top();
            pq.pop();
            if (d[cur.second] != cur.first) continue;
            for (int next : edge[cur.second]) {
                if (d[next] > d[cur.second] + 1) {
                    d[next] = d[cur.second] + 1;
                    pq.push({ d[next], next });
                }
            }
        }
        
        int sum = 0;
        for (int i = 1; i <= N; i++)
            sum += d[i];

        if (sum < ans.second) {
            ans.first = i;
            ans.second = sum;
        }
    }

    cout << ans.first;
}