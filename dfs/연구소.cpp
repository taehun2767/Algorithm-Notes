#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

typedef pair<int, int> pii;
int n, m;

int board[8][8];
bool visited[8][8];
int temp[8][8];
int answer = 0;
vector<pii> viruses;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

void bfs(int r, int c){
    queue<pii> que;
    visited[r][c] = true;
    que.emplace(r, c);
    while(que.empty() == false){
        auto cur = que.front();
        que.pop();
        for(int i = 0; i < 4; i++){
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m || visited[nr][nc])
                continue;

            if(temp[nr][nc] == 1) continue;

            temp[nr][nc] = 2;
            visited[nr][nc] = true;
            que.emplace(nr, nc);
        }
    }
}

int countSafeZone(const vector<int>& newWalls){

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            temp[i][j] = board[i][j];
            visited[i][j] = false;
        }
    }

    for(int i = 0; i < newWalls.size(); i++){
        int r = newWalls[i] / m;
        int c = newWalls[i] % m;
        if(temp[r][c] != 0) return -1;

        temp[r][c] = 1;
    }

    for(const auto& v : viruses){
        if(visited[v.first][v.second] == false)
            bfs(v.first, v.second);
    }

    int ret = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(temp[i][j] == 0)
                ret++;
        }
    }


    return ret;
}

void solve(){

    vector<int> comb(n*m, 1);
    for(int i = 0; i < 3; i++)
        comb[i] = 0;
    do
    {
        vector<int> newWalls;
        for (int i = 0; i < n * m; i++)
        {
            if (comb[i] == 0){
                newWalls.push_back(i);
            }
        }

        answer = max(answer, countSafeZone(newWalls));
    } while (next_permutation(comb.begin(), comb.end()));

}

int main(){
    fastio()
    int num;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            cin >> num;
            board[i][j] = num;
            if(num == 2) viruses.emplace_back(i, j);
        }
    }


    solve();
    cout << answer << endl;
}
