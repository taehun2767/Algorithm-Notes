#include <iostream>

#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int n,m;

bool visited[1001][1001];
int board[1001][1001];

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int ret = -1;

void dfs(int r, int c, int cnt, int sum){

    if(cnt == 4){
        ret = max(ret, sum);
        return;
    }

    for(int i = 0; i < 4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr <= 0 || nr > n || nc <= 0 || nc > m || visited[nr][nc])
            continue;

        visited[nr][nc] = true;
        dfs(nr, nc, cnt + 1, sum + board[nr][nc]);
        visited[nr][nc] = false;
    }
}

void shapeT(int r, int c){
    if(r > 0 && r < n && c > 1 && c < m)
        ret = max(ret, board[r][c] + board[r][c-1] + board[r][c+1] + board[r+1][c]);

    if(r > 1 && r < n && c > 0 && c < m)
        ret = max(ret, board[r][c] + board[r-1][c] + board[r][c+1] + board[r+1][c]);

    if(r > 1 && r < n && c > 1 && c <= m)
        ret = max(ret, board[r][c] + board[r-1][c] + board[r+1][c] + board[r][c-1]);

    if(r > 1 && r <= n && c > 1 && c < m)
        ret = max(ret, board[r][c] + board[r-1][c] + board[r][c-1] + board[r][c+1]);
}

int main(){
    
    fastio();
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            visited[i][j] = true;
            dfs(i, j, 1, board[i][j]);
            visited[i][j] = false;
            shapeT(i, j);
        }
    }

    cout << ret << endl;
}
