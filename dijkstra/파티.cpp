#include <iostream>
#include <vector>
#include <queue>

#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 1001
#define INF 1e9

using namespace std;

typedef pair<int, int> pii;

int n, m, x;
int s, d, t;

int dist[MAX] = {0, };
int dist2[MAX] = {0, };
bool selected[MAX];
vector<pii> e[MAX];
vector<pii> e2[MAX];


void dijkstra(int start){
    fill_n(dist,  1001, INF);
    priority_queue<pii> pq;

    pq.emplace(0, start);
    dist[start] = 0;


    while(!pq.empty()){

        int curDist = - pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for(const auto& road : e[cur]){
            int nxt = road.first;
            int dr = road.second;

            if(dist[nxt] > curDist + dr){
                dist[nxt] = curDist + dr;
                pq.emplace(-dist[nxt], nxt);
            }
        }
    }

    fill_n(dist2,  1001, INF);

    pq = priority_queue<pii>();

    pq.emplace(0, start);
    dist2[start] = 0;


    while(!pq.empty()){

        int curDist = - pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for(const auto& road : e2[cur]){
            int nxt = road.first;
            int dr = road.second;

            if(dist2[nxt] > curDist + dr){
                dist2[nxt] = curDist + dr;
                pq.emplace(-dist2[nxt], nxt);
            }
        }
    }

    int answer = -1;
    for(int i = 1; i <= n; i++){
        if(i == x)
            continue;

        if(answer < dist[i] + dist2[i])
            answer = dist[i] + dist2[i];
    }

    cout << answer << endl;
}

int main(){
    fastio();
    cin >> n >> m >> x;
    for(int i = 0; i < m; i++){
        cin >> s >> d >> t;
        e[s].emplace_back(d, t);
        e2[d].emplace_back(s, t);
    }

    dijkstra(x);
}
