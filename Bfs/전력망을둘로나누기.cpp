#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>


using namespace std;

int search(int n, vector<vector<int>> edges){
    int count = 0;
    vector<bool> visited(n+1, false);
    queue<int> q;
    visited[1] = true;
    q.push(1);
    count++;
    while(q.empty() == false){
        int cur = q.front();
        q.pop();
        for(int i = 1; i <= n; i++){
            if(edges[cur][i] && visited[i] == false){
                visited[i] = true;
                q.push(i);
                count++;
            }
        }
    }
    int ret = abs(n - 2 * count);
    return ret;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    for(int j = 0; j < wires.size(); j++){
        vector<vector<int>> edges(n + 1, vector<int>(n + 1, 0));
        for(int i = 0 ; i < wires.size(); i++){
            if(i == j)
                continue;
            int s = wires[i][0];
            int d = wires[i][1];
            edges[s][d] = 1;
            edges[d][s] = 1;
        }
        answer = min(answer, search(n, edges));
    }

    return answer;
}
