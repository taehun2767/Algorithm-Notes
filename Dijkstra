#include <iostream>
#include <vector>
#include <queue>

#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 20001
#define INF 1e9

using namespace std;

typedef pair<int, int> pii;

int V, E, s;
int u, v, w;
vector<pii> edges[MAX];
int dist[MAX];

void dijkstra(int source){
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, source);
    dist[source] = 0;
    while(!pq.empty()){
        int curDist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for(const auto& edge :  edges[cur]){
            int nxtDist = edge.second;
            int nxt = edge.first;
            if(dist[nxt] > curDist + nxtDist){
                dist[nxt] = curDist + nxtDist;
                pq.emplace(-dist[nxt], nxt);
            }
        }
    }

    for(int i = 1; i <= V; i++){
        if(dist[i] == INF){
            cout << "INF" << endl;
            continue;
        }

        cout << dist[i] << endl;
    }
}

int main(){
    fastio();
    cin >> V >> E;
    cin >> s;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        edges[u].emplace_back(v, w);
    }

    fill_n(dist, V+1, INF);
    dijkstra(s);
}
