#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1 ,0};

struct info {
    int r;
    int c;
    int value;
};

int bfs(int r, int c, vector<string> maps, vector<vector<bool>> &visit){
    int days = 0;
    queue<info> que;
    info cur;
    cur.r = r;
    cur.c = c;
    cur.value = maps[r][c] -'0';
    que.push(cur);
    visit[r][c] = true;
    
    while(que.empty() == false){
        info cur = que.front();
        que.pop();
        days += cur.value;
        for(int i = 0; i < 4; i++){
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            if(nr < 0 || nr >= maps.size())
                continue;
            if(nc < 0 || nc >= maps[i].size())
                continue;
            if(maps[nr][nc] != 'X' && visit[nr][nc] == false){
                info next;
                next.r = nr;
                next.c = nc;
                next.value = maps[nr][nc] - '0';
                que.push(next);
                visit[nr][nc] = true;
            }
        }
    }
    
    return days;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    vector<vector<bool>> visit(maps.size(), vector<bool>(maps[0].size(), false));

    for(int i = 0; i < maps.size(); i++){
        for(int j = 0; j < maps[0].size(); j++){
            if(maps[i][j] != 'X' && visit[i][j] == false){
                answer.push_back(bfs(i, j, maps, visit));
            }
        }
    }
    sort(answer.begin(), answer.end());
    if(answer.empty())
        answer.push_back(-1);
    
    return answer;
}
