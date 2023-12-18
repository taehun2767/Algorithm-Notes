#include <iostream>
#include <queue>

#define endl '\n'
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int edges[1001][1001] = {0, };
bool visited[1001];

int n, m;

int countCluster(int source){

    queue<int> que;
    visited[source] = true;

    que.push(source);
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        for(int i = 1; i <= n; i++){
            if(!visited[i] && edges[cur][i]){
                que.push(i);
                visited[i] = true;
            }
        }
    }

    return 1;
}

int main(){
    fastio();

    int u, v, answer = 0;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        cin >> u >> v;
        edges[u][v] = 1;
        edges[v][u] = 1;
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i])
            answer += countCluster(i);
    }

    cout << answer << endl;
}
