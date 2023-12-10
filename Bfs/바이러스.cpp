#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int network[101][101] = {0,}; // Edge 정보 가지는 배열
bool visited[101]; // 방문 체크 배열

// queue를 이용한 BFS
int bfs(int source, int n){ 
    int count = 0;
    queue<int> que;
    que.push(source);
    visited[source] = true;

    while(!que.empty()){
        int cur = que.front();
        que.pop();
        for(int i = 1; i <= n; i++){
            if(network[cur][i] && !visited[i]){
                que.push(i);
                visited[i] = true;
                count++;
            }
        }
    }

    return count;
}

int main(){
    int n, p, p1, p2;
    cin >> n;
    cin >> p;

    //그래프 정보 저장
    for(int i = 0; i < p; i++){
        cin >> p1 >> p2;
        network[p1][p2] = 1;
        network[p2][p1] = 1;
    }

    cout << bfs(1, n);
}
