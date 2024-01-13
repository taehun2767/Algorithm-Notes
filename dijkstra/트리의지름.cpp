#include <iostream>
#include <vector>
#include <queue>

#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 10001
#define INF 1e9

using namespace std;

typedef pair<int, int> pii;

int n;
int p, c, w, maxNode = -1;
int _distance[MAX];
vector<pii> edges[MAX];

void input(){
    fastio();
    cin >> n;
    for(int i = 0; i < n-1; i++){
        cin >> p >> c >> w;
        edges[p].emplace_back(c, w);
        edges[c].emplace_back(p, w);
    }
}

void initialize(){
    fill_n(_distance, n+1, INF);
}

int dijkstra(int s){

    priority_queue<pii> pq;
    _distance[s] = 0;
    pq.emplace(0, s);


    while(!pq.empty()){
        int dist = -pq.top().first;
        int pos = pq.top().second;
        pq.pop();

        for(const auto& e : edges[pos]){
            int ncost = e.second;
            int npos = e.first;

            if(dist + ncost < _distance[npos]){
                _distance[npos] = dist + ncost;
                pq.emplace(-_distance[npos], npos);
            }
        }
    }

    int maxDist = -1;
    for(int i = 1; i <= n; i++){
        if(_distance[i] > maxDist){
            maxNode = i;
            maxDist = _distance[i];
        }
    }

    return maxDist;
}

int main(){
    input();
    initialize();
    dijkstra(1);
    initialize();
    cout << dijkstra(maxNode) << endl;
}
