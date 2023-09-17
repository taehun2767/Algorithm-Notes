#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = 1000001;
    vector<vector<int>> vec(n + 1);
    for (int i = 0; i < wires.size(); i++) {
        vec[wires[i][0]].push_back(wires[i][1]);
        vec[wires[i][1]].push_back(wires[i][0]);
    }

    for (int i = 0; i < wires.size(); i++) {
        int size = 0;
        if (vec[wires[i][0]].size() == 1 || vec[wires[i][1]].size() == 1) {
            size = n - 2;
        }
        else {
            queue<int> q;
            q.push(wires[i][0]);
            size++;
            bool visited[101] = { 0, };
            visited[wires[i][0]] = true;
            visited[wires[i][1]] = true;
            while (!q.empty()) {
                for (int j = 0; j < vec[q.front()].size(); j++) {
                    if (visited[vec[q.front()][j]] == false) {
                        q.push(vec[q.front()][j]); 
                        visited[vec[q.front()][j]] = true;
                        size++;
                    }
                }
                q.pop();
            }
            size = abs(size - (n - size));
        }
        answer = min(answer, size);
    }

    return answer;
}
