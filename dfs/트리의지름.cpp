#include <iostream>
#include <vector>
#include <cstring>

#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
typedef pair<int, int> pii;

int v, v1, v2, d;
int maxAt = 0;
int maxDist = 0;
vector<pii> e[100001];
bool visited[100001];

void dfs(int cur, int dist){
    visited[cur] = true;

    if(maxDist < dist){
        maxDist = dist;
        maxAt = cur;
    }

    for(const auto& edge : e[cur]){
        int nxt = edge.first;
        if(!visited[nxt]){
            dfs(nxt, dist + edge.second);
        }
    }
}

void solution(){
    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    maxDist = 0;
    dfs(maxAt, 0);
    cout << maxDist <<endl;
}

int main(){
    fastio();
    cin >> v;
    for(int i = 1; i <= v; i++){
        cin >> v1;

        while(cin >> v2 && v2 != -1){
            cin >> d;
            e[v1].emplace_back(v2, d);
        }
    }

    solution();
}
