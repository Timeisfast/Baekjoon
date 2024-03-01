#include <string>
#include <vector>
using namespace std;

#define X first
#define Y second

int solution(string dirs) {
    int answer = 0;
    vector<vector<int>> board(11, vector<int>(11, 1));
    pair<int, int> cur = {5, 5};
    for(int i = 0; i < dirs.size(); i++) {
        if(dirs[i] == 'U') {
            if(cur.Y == 10) continue;
            if(board[cur.X][cur.Y] % 2) {
                board[cur.X][cur.Y] *= 2;
                board[cur.X][cur.Y + 1] *= 3;
                answer++;
            }
            cur = {cur.X, cur.Y + 1};
        }
        else if(dirs[i] == 'D') {
            if(cur.Y == 0) continue;
            if(board[cur.X][cur.Y] % 3) {
                board[cur.X][cur.Y] *= 3;
                board[cur.X][cur.Y - 1] *= 2;
                answer++;
            }
            cur = {cur.X, cur.Y - 1};
        }
        else if(dirs[i] == 'R') {
            if(cur.X == 10) continue;
            if(board[cur.X][cur.Y] % 5) {
                board[cur.X][cur.Y] *= 5;
                board[cur.X + 1][cur.Y] *= 7;
                answer++;
            }
            cur = {cur.X + 1, cur.Y};
        }
        else if(dirs[i] == 'L') {
            if(cur.X == 0) continue;
            if(board[cur.X][cur.Y] % 7) {
                board[cur.X][cur.Y] *= 7;
                board[cur.X - 1][cur.Y] *= 5;
                answer++;
            }
            cur = {cur.X - 1, cur.Y};
        }
    }
    return answer;
}