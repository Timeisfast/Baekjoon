#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    bool flag = false;
    int tar_ind = -1;
    for(int i = 0; i < words.size(); i++){
        if(words[i] == target) {
            flag = true;
            tar_ind = i;
        }
    }
    if(!flag) return 0;
    
    words.insert(words.begin(), begin);
    int len = begin.size();
    vector<int> visited(words.size(), 0);
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for(int i = 1; i < words.size(); i++){
            int cnt = 0;
            if(visited[i] == 0) {
                for(int j = 0; j < len; j++){
                    if(words[k][j] != words[i][j]) cnt++;
                }
                if(cnt > 1) continue;
                visited[i] = visited[k] + 1;
                q.push(i);
                if(words[i] == target) {
                    flag = false;
                    break;
                }
            }
        }
        if(!flag) break;
    }
    return visited[tar_ind + 1];
}