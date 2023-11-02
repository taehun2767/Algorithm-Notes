#include <string>
#include <vector>
#include <iostream>

using namespace std;

// int bfs()

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

    return answer;
}
