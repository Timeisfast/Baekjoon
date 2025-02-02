#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[9];
int visited[9];
int res[9];

void bt(int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++) {
            cout << res[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int tmp = 0;
    for (int i = 0; i < N; i++)
    {
        if (visited[i] == 0 && tmp != arr[i]) {
            res[cnt] = arr[i];
            tmp = res[cnt];
            visited[i] = 1;
            bt(cnt + 1);
            visited[i] = 0;
        }
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
    bt(0);
}