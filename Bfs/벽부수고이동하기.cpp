#include <iostream>
#include <queue>

#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 1001

using namespace std;

int n, m;
string s;
bool map[MAX][MAX];
bool visited[MAX][MAX][2];

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

struct info{
    int r;
    int c;
    int cnt = 0;
    bool isWallCrashed = false;
    info (int R, int C, int CNT, int ISWALLCRASHED) : r(R), c(C), cnt(CNT), isWallCrashed(ISWALLCRASHED) {};
};

void bfs(){

    queue<info> que;
    info cur = info(1, 1, 1, false);
    que.emplace(cur);
    visited[1][1][0] = true;

    while(!que.empty()){
        cur = que.front();
        que.pop();
        if(cur.r == n && cur.c == m){
            cout << cur.cnt << endl;
            return;
        }

        for(int i = 0; i < 4; i++){
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];

            if(nr < 1 || nr > n || nc < 1 || nc > m)
                continue;

            if(map[nr][nc] == 1 && visited[nr][nc][1] == false){
                if(cur.isWallCrashed)
                    continue;

                que.emplace(nr, nc, cur.cnt + 1, true);
                visited[nr][nc][1] = true;
            }

            else if(map[nr][nc] == 0){
                if(!visited[nr][nc][0] && !cur.isWallCrashed){
                    que.emplace(nr, nc, cur.cnt + 1, cur.isWallCrashed);
                    visited[nr][nc][0] = true;
                }
                else if(!visited[nr][nc][1] && cur.isWallCrashed){
                    que.emplace(nr, nc, cur.cnt + 1, cur.isWallCrashed);
                    visited[nr][nc][1] = true;
                }
            }
        }
    }

    cout << -1 << endl;
}

void input(){
    fastio();
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> s;
        for(int j = 1; j <= m; j++)
            map[i][j] = s[j-1] - '0';
    }
}

int main(){
    input();
    bfs();
}
