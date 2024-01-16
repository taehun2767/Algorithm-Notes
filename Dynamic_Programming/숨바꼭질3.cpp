#include <iostream>
#include <queue>

#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 100001
#define INF 1e9

using namespace std;

typedef pair<int, int> pii;

int n, k, ans = INF;
int visited[MAX];

void bfs(){
    queue<pii> que;
    que.emplace(n, 0);
    while(!que.empty()){
        int cur = que.front().first;
        int cnt = que.front().second;
        que.pop();

        if(cur == k){
            ans = min(ans, cnt);
            continue;
        }

        int nxt = cur - 1;
        if(nxt >= 0 && nxt < MAX && cnt + 1 < visited[nxt]){
            que.emplace(nxt, cnt + 1);
            visited[nxt] = cnt + 1;
        }

        nxt = cur + 1;
        if(nxt >= 0 && nxt < MAX && cnt + 1 < visited[nxt]){
            que.emplace(nxt, cnt + 1);
            visited[nxt] = cnt + 1;
        }

        nxt = cur + cur;
        if(nxt >= 0 && nxt < MAX  && cnt < visited[nxt]){
            que.emplace(nxt, cnt);
            visited[nxt] = cnt;
        }
    }

    cout << ans << endl;
}

int main(){
    fastio();
    fill_n(visited, MAX, INF);
    cin >> n >> k;
    bfs();
}
