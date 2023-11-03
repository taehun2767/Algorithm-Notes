#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

struct posInfo{
    int r;
    int c;
    int distance;
};

int bfs(vector<string> maps, vector<int> source, vector<int> destination){
    
    vector<vector<bool>> visited = vector<vector<bool>>(maps.size(), vector<bool>(maps[0].size(), false));
    queue<posInfo> que;
    
    posInfo cur;
    cur.r = source[0];
    cur.c = source[1];
    cur.distance = 0;
    que.push(cur);
    visited[cur.r][cur.c] = true;
    
    while(que.empty() == false){
        cur = que.front();
        que.pop();
        if(cur.r == destination[0] && cur.c == destination[1])
            return cur.distance;
        
        for(int i = 0; i < 4; i++){
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            
            if(nr < 0 || nr >= maps.size() || nc < 0 || nc >= maps[0].size())
                continue;
            if(visited[nr][nc] || maps[nr][nc] == 'X')
                continue;
            
            posInfo next;
            next.r = nr;
            next.c = nc;
            next.distance = cur.distance + 1;
            que.push(next);
            visited[nr][nc] = true;
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    vector<vector<int>> pos (3, vector<int>());
    for(int i = 0; i < maps.size(); i++){
        for(int j = 0; j < maps[i].size(); j++){
            if(maps[i][j] == 'S'){
                pos[0].push_back(i);
                pos[0].push_back(j);
            }
            else if(maps[i][j] == 'L'){
                pos[1].push_back(i);
                pos[1].push_back(j);
            }
            else if(maps[i][j] == 'E'){
                pos[2].push_back(i);
                pos[2].push_back(j);
            }
        }
    }
    
    int startToLever = bfs(maps, pos[0], pos[1]);
    if(startToLever == -1)
        return -1;
    int leverToEnd = bfs(maps, pos[1], pos[2]);
    if(leverToEnd == -1)
        return -1;
    
    
    return startToLever + leverToEnd;
}
