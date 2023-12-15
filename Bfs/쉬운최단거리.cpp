#include <iostream>
#include <queue>

#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int map[1001][1001] ={0, };
bool visited[1001][1001];
int ans[1001][1001] = {0, };

struct info{
    int r;
    int c;
    int dist;
};

void solve(int destr, int destc, int n, int m){
    queue<info> que;
    info cur{destr, destc, 0};
    visited[destr][destc] = true;
    que.push(cur);
    while(!que.empty()){
        cur = que.front();
        que.pop();
        for(int i = 0; i < 4; i++){
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            int ndist = cur.dist + 1;

            if(nr <= 0 || nr > n || nc <= 0 || nc > m)
                continue;

            if(!visited[nr][nc] && map[nr][nc] != 0){
                info next{nr, nc, ndist};
                que.push(next);
                ans[nr][nc] = ndist;
                visited[nr][nc] = true;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!visited[i][j] && map[i][j] == 1)
                ans[i][j] = -1;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << ans[i][j] <<" ";
        }
        cout << endl;
    }

}

int main(){
    fastio();
    int n, m, num, destr, destc;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> num;
            map[i][j] = num;
            if(num == 2){
                destr = i;
                destc = j;
            }
        }
    }
    solve(destr, destc, n, m);
}
